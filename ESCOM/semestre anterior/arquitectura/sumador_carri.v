library ieee;
use ieee.std_logic_1164.all;

entity sumador is
	port(
		A: in std_logic_vector(9 downto 0);
		B: in std_logic_vector(9 downto 0);
		S: out std_logic_vector(9 downto 0);
		C: out std_logic
	);
end sumador;

architecture sumador of suma is
signal c0: std_logic:='0';
begin
	
	process(A,B)
		begin
			for n in 0 to 9 loop
				S(n)<=(A(n) xor B(n));
				C(n)<=(A(n) and B(n))or c0;
				c0<=C(n);
			end loop
	end process;		
end suma;


