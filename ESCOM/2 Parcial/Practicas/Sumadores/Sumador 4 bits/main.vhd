library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is
    Port ( vecA : in  STD_LOGIC_VECTOR (3 downto 0);
           vecB : in  STD_LOGIC_VECTOR (3 downto 0);
			  Cin : inout STD_LOGIC;
           Sal : out  STD_LOGIC_VECTOR (4 downto 0));
end main;

architecture Behavioral of main is
--signal Acar0: STD_LOGIC:='0';
signal Acar1: STD_LOGIC;
signal Acar2: STD_LOGIC;
signal Acar3: STD_LOGIC;
begin

bit1: sumaC port map(vecA(0),vecB(0),Cin,Acar1,Sal(0));
bit2: sumaC port map(vecA(1),vecB(1),Acar1,Acar2,Sal(1));
bit3: sumaC port map(vecA(2),vecB(2),Acar2,Acar3,Sal(2));
bit4: sumaC port map(vecA(3),vecB(3),Acar3,Sal(4),Sal(3));

end Behavioral;

