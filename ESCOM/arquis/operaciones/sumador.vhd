
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity sumador is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Ci : in  STD_LOGIC;
           Co : out  STD_LOGIC;
           F : out  STD_LOGIC);
end sumador;

architecture Behavioral of sumador is

begin

	
		F<=A xor B xor Ci;
		Co<=((A xor B) and Ci) or (A and B);
	

end Behavioral;

