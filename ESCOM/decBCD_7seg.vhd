LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY bcd_7seg IS
	PORT(BCD : IN STD_LOGIC_VECTOR(3 downto 0);	     
	     D7seg : OUT STD_LOGIC_VECTOR(6 downto 0)
	);
END bcd_7seg;

ARCHITECTURE Structure OF bcd_7seg IS
signal D7seg_AC , D7seg_CC : STD_LOGIC_VECTOR(6 downto 0);
BEGIN
-- Estas combinaciones son para displays de CATODO COMUN (Prenden con 1)
	process (BCD)
		begin 
			case BCD is                   --gfedcba
				when "0000" => D7seg_CC <= "0111111"; --0	0111111
				when "0001" => D7seg_CC <= "0000110"; --1	0000110
				when "0010" => D7seg_CC <= "1011011"; --2	1011011
				when "0011" => D7seg_CC <= "1001111"; --3	1001111
				when "0100" => D7seg_CC <= "1100110"; --4	1100110
				when "0101" => D7seg_CC <= "1101101"; --5	1101101
				when "0110" => D7seg_CC <= "1111101"; --6	1111101
				when "0111" => D7seg_CC <= "0000111"; --7	0000111
				when "1000" => D7seg_CC <= "1111111"; --8	1111111
				when "1001" => D7seg_CC <= "1101111"; --9	1101111
				when "1010" => D7seg_CC <= "0111110"; --V	1110111
				when "1011" => D7seg_CC <= "0110000"; --I	1111100
				when "1100" => D7seg_CC <= "1110111"; --A	1011000
				when "1101" => D7seg_CC <= "1110011"; --P	1011110
				when "1110" => D7seg_CC <= "0110111"; --N	1111001
				when "1111" => D7seg_CC <= "0000000"; --APAGADO
				when OTHERS => D7seg_CC <= "0000000"; --APAGADO								
			end case;
	end process;	
	D7seg_AC <= not(D7seg_CC);
	-- Seleccionar la salida adecuada, dependiendo del tipo de display
	-- D7seg <= D7seg_CC;-- Catodo Comun
	D7seg <= D7seg_AC;-- Anodo Comun							
END Structure;