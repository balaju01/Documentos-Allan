library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.micros_package.all;
use work.bin_to_bcd_package.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity main is
	generic (ram_addr_bits:integer:=5; ram_width:integer:=8);
	port(
	clk,reset: IN STD_LOGIC;
	an: OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
	ssg: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
	);
end main;

architecture Behavioral of main is
	signal clkdiv: std_logic_vector(27 downto 0):=(others=>'0');
	signal Cont_Anillo: std_logic_vector(1 downto 0):="00";
	signal clk_interno: STD_LOGIC;
	signal clk_interno2: STD_LOGIC;
	signal unidades_7SG, decenas_7SG, centenas_7SG: std_logic_vector(6 downto 0);
	SIGNAL unidades_BCD, decenas_BCD, centenas_BCD: std_logic_vector(3 downto 0);
	signal ACC: std_logic_vector (ram_width-1 downto 0);--salida del dato
	signal BANDERAS: std_logic_vector (2 downto 0);--registro de banderas ZVC
	signal DATO_VALIDO: std_logic;
	signal salida_BIN: STD_LOGIC_VECTOR (4 DOWNTO 0);
	signal salida_BCD: STD_LOGIC_VECTOR (11 DOWNTO 0);
	
	begin		
		micro: mp4 port map (clk_interno2,reset,ACC,BANDERAS,DATO_VALIDO);
		
		--salida_BIN <= BANDERAS(0) & ACC; --concatenamos para tener 5 bits
	
		salida_BCD <= to_bcd(ACC); --recibimos el bcd de salida bin concatenado con 000 para tener 8 bits
		
		unidades_BCD <= salida_BCD(3 DOWNTO 0);--asignamos los bits correspondientes dependiendo de la unidades
		decenas_BCD <= salida_BCD (7 DOWNTO 4);
		centenas_BCD <= salida_BCD (11 DOWNTO 8);
		
		Conv_Unidades:  bcd_7seg PORT MAP (unidades_BCD, unidades_7SG);
		Conv_Decenas:   bcd_7seg PORT MAP (decenas_BCD, decenas_7SG);
		Conv_Centenas:  bcd_7seg PORT MAP (centenas_BCD, centenas_7SG);
		
		process(clk) begin
			  if rising_edge(clk)then
				  clkdiv <= clkdiv + 1;
			  end if;
		end process;		
		clk_interno <= clkdiv(16);
		clk_interno2 <= clkdiv(22);
		
		process(clk_interno, Cont_Anillo, unidades_7sg, decenas_7sg, centenas_7sg) begin
			if rising_edge(clk_interno) then
				Cont_Anillo <= Cont_Anillo + 1;
			end if;
			
			case Cont_Anillo is
				when "00" =>
					an<="1110";
					ssg <= unidades_7SG;
				when "01" =>
					an<="1101";
					ssg <= decenas_7SG;
				when "10" =>
					an <= "1011";
					ssg <= centenas_7SG;
				when others =>
					an<="1111";
			end case;
		end process;
end Behavioral;

