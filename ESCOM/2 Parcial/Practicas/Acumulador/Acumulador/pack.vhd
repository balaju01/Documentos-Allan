library IEEE;
use IEEE.STD_LOGIC_1164.all;

package pack is

component FFJK Port ( j : in  STD_LOGIC;
           k : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC;
           Qn : out  STD_LOGIC);
end component;

component suma Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           F : out  STD_LOGIC;
           Cout : out  STD_LOGIC);
end component;

component Reg Port ( J : in  STD_LOGIC_VECTOR (3 downto 0);
           K : in  STD_LOGIC_VECTOR (3 downto 0);
           clk2 : in  STD_LOGIC;
           Sal : out  STD_LOGIC_VECTOR (3 downto 0));
end component;

component vclk PORT (
		clk: IN std_logic; 
		q: inOUT std_logic);
end component;
end pack;