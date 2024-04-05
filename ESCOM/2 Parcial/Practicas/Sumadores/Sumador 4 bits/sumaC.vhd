library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sumaC is
    Port ( b1 : in  STD_LOGIC;
           b2 : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           Cout : out  STD_LOGIC;
           Sal : out  STD_LOGIC);
end sumaC;

architecture arq_sumaC of sumaC is

begin
	Sal <= (b1 xor b2) xor Cin;
	Cout <= (b1 and b2) or ((b1 xor b2) and Cin);

end arq_sumaC;

