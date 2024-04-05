-- Módulo registro de instruccion 
-- Almacena temporalmente las instrucciones provenientes de la memoria de programa
--
library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity reg_ins is port (
 A: in std_logic;
 RO: in std_logic_vector (7 downto 0);--proveniente de memoria de programa
 RI: out std_logic_vector (7 downto 0));--hacia el decodificador de instrucciones
end reg_ins;
architecture a_reg of reg_ins is
begin
 process (A) begin
   if (A'event and A = '1' ) then 
       RI <= RO;
  end if;
 end process;
end a_reg;