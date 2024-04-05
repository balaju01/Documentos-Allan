-- Módulo de la unidad aritmética y lógica
-- Realiza operaciones aritméticas y lógicas del microprocesador
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity alu is port(
     DI: in std_logic_vector (0 to 9);--proveniente del decodificador de instrucciones
     RD: in std_logic_vector (7 downto 0);--proveniente del registro de datos
    ACC: in std_logic_vector (7 downto 0);--proveniente del acumulador permanente
     OP: inout std_logic_vector (7 downto 0);--resultado de la operacion
	  RE: inout std_logic_vector (2 downto 0));--registro de estado ZVC
end alu;
architecture a_alu of alu is

begin

process (DI,ACC,RD,RE) 
variable OP_E: std_logic_vector (8 downto 0):=(others=>'0');--resultado de la operacion EXTENDIDA 1 bit
variable v_RE: std_logic_vector (2 downto 0):=(others=>'0');--registro de estado ZVC

begin
OP_E:=(others=>'0');
v_RE:=RE;

  if  (DI = "1000000000") then-- funcion and
      OP <= ACC and RD;
		v_RE(1):='0';-- bandera de desbordamiento (V)
		v_RE(0):='0';-- bandera de acarreo de salida (C)
		
 elsif (DI = "0100000000") then-- funcion or 
      OP <= ACC or RD;
		v_RE(1):='0';-- bandera de desbordamiento (V)
		v_RE(0):='0';-- bandera de acarreo de salida (C)
		
 elsif (DI = "0010000000") then-- funcion xor
      OP <= ACC xor RD;
		v_RE(1):='0';-- bandera de desbordamiento (V)
		v_RE(0):='0';-- bandera de acarreo de salida (C)
		
 elsif (DI = "0001000000") then-- funcion suma aritmetica
      OP <= ACC + RD;
		OP_E:= ('0' & ACC) + ('0' & RD);
		if (OP_E(4)='1') then 
			v_RE(1):='1';-- bandera de desbordamiento (V)
		else 
			v_RE(1):='0';-- bandera de desbordamiento (V)
		end if;
		v_RE(0):=OP_E(4);-- bandera de acarreo de salida (C)
		
 elsif (DI = "0000100000") then-- funcion invertir el acumulador
      OP <= not ACC;
		v_RE(1):='0';-- bandera de desbordamiento (V)
		v_RE(0):='0';-- bandera de acarreo de salida (C)
		
 elsif (DI = "0000010000") then-- funcion retencion
      OP <= ACC;-- HOLD
		v_RE:=v_RE;-- retencion
				
 elsif (DI = "0000001000") then-- funcion cargar el acumulador 
      OP <= RD;--LOAD
		v_RE(1):='0';-- bandera de desbordamiento (V)
		v_RE(0):='0';-- bandera de acarreo de salida (C)
		
 elsif (DI = "0000000010") then-- funcion resta aritmetica	 	  
      OP <= ACC - RD;
		OP_E:= ('0' & ACC) - ('0' & RD);
		if (OP_E(4)='1') then 
			v_RE(1):='1';-- bandera de desbordamiento (V)
		else 
			v_RE(1):='0';-- bandera de desbordamiento (V)
		end if;
		v_RE(0):=OP_E(4);-- bandera de acarreo de salida (C)		
 else
      OP <= ACC;-- HOLD de la 9 a la 15
		v_RE:=v_RE;-- retencion
		
 end if;

 if (OP=x"0" and OP_E(4)='0') then
	v_RE(2):='1';-- bandera de cero (Z)
 else
	v_RE(2):='0';-- bandera de cero (Z)
 end if;
		
 RE <= v_RE;

end process;
end a_alu;