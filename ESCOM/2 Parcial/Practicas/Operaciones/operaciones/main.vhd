
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is
    Port ( vec1 : in  STD_LOGIC_vector(3 downto 0);
           vec2 : in  STD_LOGIC_vector(3 downto 0);
           c : in  STD_LOGIC_vector(2 downto 0);
           sum : out  STD_LOGIC_vector(4 downto 0));
end main;

architecture Behavioral of main is
 signal b: std_logic_vector(3 downto 0);
 signal vec: std_logic_vector(3 downto 0);
 signal ac1: std_logic;
 signal ac2: std_logic;
 signal ac3: std_logic;
 signal son: std_logic;
 begin
   son<=not c(2);
	vec<=not vec2;
   b(0)<=(son and vec2(0))or(c(1)and vec(0));
	b(1)<=(son and vec2(1))or(c(1)and vec(1));
	b(2)<=(son and vec2(2))or(c(1)and vec(2));
	b(3)<=(son and vec2(3))or(c(1)and vec(3));
	
   --b(0)<=(((not(c(2)))and vec2(0)) or (c(1)and(not(vec2(0)))));
	--b(1)<=(((not(c(2)))and vec2(1)) or (c(1)and(not(vec2(1)))));
	--b(2)<=(((not(c(2)))and vec2(2)) or (c(1)and(not(vec2(2)))));
	--b(3)<=(((not(c(2)))and vec2(3)) or (c(1)and(not(vec2(3)))));
	
	suma1:sumador port map(vec1(0),b(0),c(0),ac1,sum(0));
   suma2:sumador port map(vec1(1),b(1),c(0),ac2,sum(1));
   suma3:sumador port map(vec1(2),b(2),c(0),ac3,sum(2));
   suma4:sumador port map(vec1(3),b(3),c(0),sum(4),sum(3));
end Behavioral;

