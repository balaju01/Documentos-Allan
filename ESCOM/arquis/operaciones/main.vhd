library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pacman.all;

entity main is
    Port ( s1 : in  STD_LOGIC;
           s2 : in  STD_LOGIC;
           Ci : in  STD_LOGIC;
           A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Co : out  STD_LOGIC;
           F : out  STD_LOGIC);
end main;

architecture Behavioral of main is
signal a1 : std_logic;
signal b1 : std_logic;
signal c1 : std_logic;
begin
bit1: sumador port map (A,B,Ci,a1,b1);

if(a=0)
	A<=A2;

end Behavioral;

