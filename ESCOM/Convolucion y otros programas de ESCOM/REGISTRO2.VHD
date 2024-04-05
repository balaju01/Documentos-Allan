glibrary ieee;
use ieee.std_logic_1164.all;

entity registro is
	GENERIC( N : INTEGER := 7 );
	port(
		D: in std_logic_vector(N-1 downto 0);
		clk, clr, Ds: in std_logic;
		OP:in std_logic_vector(1 downto 0);
		Q: inout std_logic_vector(N-1 downto 0)
	);
end registro;

architecture ecuaciones of registro is
begin
	A: process(clk,clr)
		begin
			if(clr='1')then
				Q <= (OTHERS=>'0');
			elsif(clk'event and clk='1')then
				FOR I IN 0 TO N-1 LOOP 
					CASE OP IS		--SWITCH( OP ){
						WHEN "00" =>	--CASE 00 :
 							Q(I) <= Q(I);
						WHEN "01" =>	--CASE 01 : 						
							Q(I) <= D(I);
						WHEN "10" =>	--CASE 10 : 						
							IF( I = 0 )THEN
								Q(I) <= DS;
							ELSE
								Q(I) <= Q(I-1);
							END IF;
						WHEN OTHERS =>	--DEFAULT : 						
							IF( I = N-1 )THEN
								Q(I) <= DS;
							ELSE
								Q(I) <= Q(I+1);
							END IF;
					END CASE;		--}
				END LOOP;	
			end if;
		end process A;
	
end ecuaciones;


