library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity FFJK is
    Port ( j : in  STD_LOGIC;
           k : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           Q : out  STD_LOGIC;
           Qn : out  STD_LOGIC);
end FFJK;

architecture prosJK of FFJK is
signal aux: STD_LOGIC;
begin

process(clk)
begin
	if rising_edge(clk) then
		if(j='0' and k='0') then
			aux <= aux;
		elsif(j='1' and k='1') then
			aux <= not(aux);
		elsif(j='0' and k='1') then
			aux <='0';
		else
			aux <= '1';
		end if;
	end if;
end process;
Q<= aux;
Qn<= not (aux);
end prosJK;

