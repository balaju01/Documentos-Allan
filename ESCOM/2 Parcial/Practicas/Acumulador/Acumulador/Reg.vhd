library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.FFJK;

entity Reg is
    Port ( J : in  STD_LOGIC_VECTOR (3 downto 0);
           K : in  STD_LOGIC_VECTOR (3 downto 0);
           clk2 : in  STD_LOGIC;
           Sal : out  STD_LOGIC_VECTOR (3 downto 0));
end Reg;

architecture Behavioral of Reg is
signal Qn: std_logic_vector(3 downto 0);

begin

bit1 : FFJK port map(J(0),k(0),clk2,Sal(0),Qn(0));
bit2 : FFJK port map(J(1),k(1),clk2,Sal(1),Qn(1));
bit3 : FFJK port map(J(2),k(2),clk2,Sal(2),Qn(2));
bit4 : FFJK port map(J(3),k(3),clk2,Sal(3),Qn(3));

end Behavioral;

