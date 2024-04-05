library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity sumador is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           F : out  STD_LOGIC;
           Cout : out  STD_LOGIC);
end sumador;

architecture arqsum of sumador is

begin

F<= (A xor B) xor Cin;
Cout <= (A and B) or ((A xor B) and Cin);

end arqsum;

