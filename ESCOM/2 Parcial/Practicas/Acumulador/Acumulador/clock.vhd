library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY vclk IS PORT (
		clk: IN std_logic; 
		q: inOUT std_logic);
END vclk;

ARCHITECTURE retardo of vclk is
signal aux:std_logic_vector(27 downto 0):=(others =>'0');

begin

process(clk)
begin
	if rising_edge(clk) then
		if aux(27)='1' then
			aux <= (others =>'0');
			q <= not q;
		else
			aux <= aux + 1;
		end if;
	end if;
end process;

end retardo;