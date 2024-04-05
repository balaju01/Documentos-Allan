
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is
    Port ( vec1 : in  STD_LOGIC_vector(3 downto 0);
           vec2 : in  STD_LOGIC_vector(3 downto 0);
           cin : in  STD_LOGIC;
           sum : out  STD_LOGIC_vector(4 downto 0));
end main;

architecture Behavioral of main is
signal ac1: std_logic;
signal ac2: std_logic;
signal ac3: std_logic;
signal vecs: std_logic_vector(3 downto 0);
begin

vecs(0)<=vec2(0) xor cin;
vecs(1)<=vec2(1) xor cin;
vecs(2)<=vec2(2) xor cin;
vecs(3)<=vec2(3) xor cin;

suma1:sumador port map(vec1(0),vecs(0),cin,ac1,sum(0));
suma2:sumador port map(vec1(1),vecs(1),ac1,ac2,sum(1));
suma3:sumador port map(vec1(2),vecs(2),ac2,ac3,sum(2));
suma4:sumador port map(vec1(3),vecs(3),ac3,sum(4),sum(3));
end Behavioral;

