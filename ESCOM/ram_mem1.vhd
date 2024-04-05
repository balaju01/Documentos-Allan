----------------------------------------------------------------------------------
-- Arquitectura de computadoras. 
-- Memoria RAM de 4 lineas de direccionamiento y 
-- ancho de palabra de 4 bits (16 posibles localidades)

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity RAM_mem1 is
generic (ram_addr_bits:integer:=5; ram_width:integer:=8);
	port(
		ram_enable, write_enable : in std_logic;		
		address : in std_logic_vector (ram_addr_bits-1 downto 0);
		data_in : in std_logic_vector(ram_width-1 downto 0);
		data_out : out std_logic_vector(ram_width-1 downto 0);
		data_ready : out std_logic
);
end RAM_mem1;

architecture Behavioral of RAM_mem1 is

---------------- Declaracion de la memoria RAM --------------------------
--type ram_type is array (2**ram_addr_bits-1 downto 0, ram_width-1 downto 0) of std_logic;
type ram_type is array (2**ram_addr_bits-1 downto 0) of std_logic_vector (ram_width-1 downto 0);
signal ram_input, ram_output : std_logic_vector (ram_width-1 downto 0):= (others=>'1');
signal ram_address : std_logic_vector (ram_addr_bits-1 downto 0):= (others=>'0');
signal ram_1: ram_type:= (
-- Fin de programa
--
x"00",--argumento			0
x"07", --carga
x"07",--argumento			0
x"07", --carga
x"07",--argumento			0
x"07", --carga
x"07",--argumento			0
x"07", --carga
x"07",--argumento			0
x"07", --carga
x"07",--argumento			0
x"07", --carga
x"07",--argumento			0
x"05", --carga
x"15",--argumento			0
x"06", --carga
x"0D",--argumento			0
x"06", --carga
x"08",--argumento			0
x"06", --carga
x"05",--argumento			0
x"06", --carga
x"03",--argumento			0
x"06", --carga
x"02",--argumento			0
x"06", --carga
x"01",--argumento			0
x"06", --carga
x"01",--argumento			0
x"06", --carga
x"00",--argumento			0
x"06" --carga
--
-- Inicio de programa
);
-------------------------------------------------------------------------

begin

--- Asignacion de los puertos y las señales -----------------------------
data_out <= ram_output;
ram_input <= data_in;
ram_address <= address;

-------------------------------------------------------------------------
process (ram_enable, write_enable, ram_input, ram_1, ram_address)
begin
       if (ram_enable = '1') then
         if (write_enable = '1') then
            ram_1(conv_integer(ram_address)) <= ram_input;	
				ram_output <= (others=>'Z');
         else
				ram_output <= ram_1(conv_integer(ram_address));						 
			end if;
				data_ready <= '1';
       else
			ram_output <= (others=>'Z');
			data_ready <= '0';
	  end if;
end process;

end Behavioral;
