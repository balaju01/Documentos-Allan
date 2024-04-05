library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           Cin : in  STD_LOGIC;
           Sal : out  STD_LOGIC_VECTOR (4 downto 0);
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC);
end main;

architecture Behavioral of main is
signal B2 : std_logic_vector (3 downto 0);
signal Cout2 : std_logic_vector (3 downto 0);

begin

Sal(4) <= Cout2(3);

B2(0) <= (not (S0) and B(0)) or (not (B(0)) and S1);
B2(1) <= (not (S0) and B(1)) or (not (B(1)) and S1);
B2(2) <= (not (S0) and B(2)) or (not (B(2)) and S1);
B2(3) <= (not (S0) and B(3)) or (not (B(3)) and S1);

bit1 : sumaC port map(A(0),B2(0),Cin,Cout2(0),Sal(0));
bit2 : sumaC port map(A(1),B2(1),Cout2(0),Cout2(1),Sal(1));
bit3 : sumaC port map(A(2),B2(2),Cout2(1),Cout2(2),Sal(2));
bit4 : sumaC port map(A(3),B2(3),Cout2(2),Cout2(3),Sal(3));


end Behavioral;

