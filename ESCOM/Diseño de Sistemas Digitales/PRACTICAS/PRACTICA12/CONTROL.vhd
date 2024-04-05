library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity CONTROL is
    Port ( 
           CLK : in  STD_LOGIC;
           CLR : in  STD_LOGIC;
           S, Z, A0 : in  STD_LOGIC;
           LA, EA, LB, EB, EC : Out  STD_LOGIC
			  );
end CONTROL;

architecture PROGRAMA of CONTROL is
TYPE ESTADOS IS (EDO_A, EDO_B, EDO_C);
SIGNAL EDO_ACT, EDO_SGTE : ESTADOS;
begin

	AUTOMATA : PROCESS( EDO_ACT, S, A0, Z )
	BEGIN
		LA <= '0';
		LB <= '0';
		EA <= '0';
		EB <= '0';
		EC <= '0';
		
		CASE EDO_ACT IS
			WHEN EDO_A => LB <= '1';
				IF( S = '0' )THEN
					LA <= '1';
					EDO_SGTE <= EDO_A;
				ELSE
					EDO_SGTE <= EDO_B;
				END IF;
			WHEN EDO_B => EA <= '1';
				IF( Z = '1' )THEN
					EDO_SGTE <= EDO_C;
				ELSE
					IF(A0 = '1') THEN
						EB <= '1';
						EDO_SGTE <= EDO_B;
					ELSE
						EDO_SGTE <= EDO_B;
					END IF;
				END IF;
			WHEN EDO_C => EC <= '1';
				IF( S = '1' )THEN
					EDO_SGTE <= EDO_C;
				ELSE
					EDO_SGTE <= EDO_A;
				END IF;
		END CASE;
	END PROCESS AUTOMATA;
	
	TRANSICION : PROCESS( CLK, CLR )
	BEGIN
		IF( CLR = '1' )THEN
			EDO_ACT <= EDO_A;
		ELSIF( RISING_EDGE(CLK) )THEN
			EDO_ACT <= EDO_SGTE;
		END IF;
	END PROCESS TRANSICION;
	
end PROGRAMA;

