-- Modúlo contador de programa
-- Es un registro interno del microprocesador que proporciona la siguiente direccion de memoria, sea
-- para introducir un dato o una instruccion del microprocesador

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity pcount is 
generic (ram_addr_bits:integer:=5);
port (
      E: in std_logic;
     DI: in std_logic_vector (0 to 9);--proveniente del decodificador de instrucciones
     PC: out std_logic_vector (ram_addr_bits-1 downto 0));--hacia la memoria de programa
end pcount;
architecture a_pc of pcount is
signal s_PC: std_logic_vector (ram_addr_bits-1 downto 0):=(others=>'0');
begin
 PC<=s_PC;
 process (E) begin
   if (E'event and E = '1') then
        s_PC <= s_PC + 1;-- proporciona la siguiente direccion de memoria
          if (DI = "0000000100") then-- funcion reset para el PC
            s_PC <=(others=>'0');
           end if;
    end if;
  end process;
 end a_pc;