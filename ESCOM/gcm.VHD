-- Módulo de generación ciclo de máquina 
-- Unidad de control del microprocesador, sincroniza y activa la participacion de cada uno
-- de los registros internos del microprocesador.
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity gcm is port(
 CLK,RESET: in std_logic;
 A,B,C,D,E: out std_logic;--hacia los diferentes modulos   
 Q: inout std_logic_vector (3 downto 0));
end gcm;
architecture a_gcm of gcm is
begin
 process (clk) 
	begin
   -- if  (clk'event and clk = '1') then
     --    Q <= Q  + 1;
            --if (RESET = '1' or Q = "0110") then
              -- Q <= "0000";
            --end if;
       --end if;

	if (RESET = '1' or Q = "0110") then
		Q <= "0000";
	elsif  (clk'event and clk = '1') then
		Q <= Q  + 1;
   end if;
 
   end process;

process (Q) 
	begin
	 case Q is
		when "0000" =>A <= '1';E <= '0' ; B <= '0'; C <= '0'; D <= '0' ;--registro de instruccion
		when "0001" =>A <= '0';E <= '1' ; B <= '0'; C <= '0'; D <= '0' ;--contador de programa
		when "0010" =>A <= '0';E <= '0' ; B <= '1'; C <= '0'; D <= '0' ;--registro de datos
		when "0011" =>A <= '0';E <= '1' ; B <= '0'; C <= '0'; D <= '0' ;--contador de programa
		when "0100" =>A <= '0';E <= '0' ; B <= '0'; C <= '1'; D <= '0' ;--acumulador temporal
		when others =>A <= '0';E <= '0' ; B <= '0'; C <= '0'; D <= '1' ;--acumulador permanente
	 end case;
   end process;
  end a_gcm;              