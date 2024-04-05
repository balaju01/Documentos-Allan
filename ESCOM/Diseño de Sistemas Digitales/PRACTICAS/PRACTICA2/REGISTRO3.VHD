library ieee;
use ieee.std_logic_1164.all;

entity registro is
	GENERIC( N : INTEGER := 4 );
	port(
		D: in std_logic_vector(N-1 downto 0);
		clk, clr, Ds: in std_logic;
		OP:in std_logic_vector(1 downto 0);
		Qs: inout std_logic_vector(1 downto 0)
	);
	attribute pin_numbers of registro: entity is
		"CLK:1 CLR:13 D(3):2 D(2):3 D(1):4 D(0):5  OP(0):8 OP(1):9  ";
	
end registro;

architecture ecuaciones of registro is
SIGNAL Q : std_logic_vector(N-1 downto 0);
begin
	A: process(clk,clr)
		begin
			if(clr='1')then
				Q <= (OTHERS=>'0');
			elsif(clk'event and clk='1')then
				CASE OP IS		--SWITCH( OP ){
					WHEN "00" =>	--CASE 00 :
						Q <= D;
					WHEN "01" =>	--CASE 01 : 						
						Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SLL 1);
						Q(0) <= DS;
					WHEN "10" =>	--CASE 10 : 										
						Q <= TO_STDLOGICVECTOR(TO_BITVECTOR(Q) SRL 1);
						Q(N-1) <= DS;
				END CASE;		--}
			end if;
		end process A;
		Qs(1)<=Q(N-1);
		Qs(0)<=Q(0);
end ecuaciones;


