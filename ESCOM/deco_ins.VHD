--Modulo de decodificador de instruccion 
-- convierte el codigo binario proveniente del registro de instrucciones en una accion particular
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity deco_ins is port(
 RI: in std_logic_vector (7 downto 0);--proveniente del registro de instrucciones
 DI: out std_logic_vector (0 to 9));--hacia la ALU
end deco_ins;
architecture a_deco of deco_ins is
begin
  process (RI) 
  begin
    case  RI(3 downto 0) is
      when "0000" =>DI<= "1000000000";-- funcion and
      when "0001" =>DI<= "0100000000";-- funcion or
      when "0010" =>DI<= "0010000000";-- funcion xor
      when "0011" =>DI<= "0001000000";-- funcion suma aritmetica
      when "0100" =>DI<= "0000100000";-- funcion invertir el acumulador
      when "0101" =>DI<= "0000010000";-- funcion retencion
      when "0110" =>DI<= "0000001000";-- funcion cargar el acumulador 
      when "0111" =>DI<= "0000000100";-- funcion reset para el PC
      when "1000" =>DI<= "0000000010";-- funcion resta aritmetica
      when others =>DI<= "0000000000";-- se inhabilita el DI
    end case;
  end process;
  end a_deco;