library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity suma is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           F : out  STD_LOGIC;
           Cout : out  STD_LOGIC);
end suma;

architecture Behavioral of suma is

begin

F<= (A xor B) xor Cin;
Cout <= (A and B) or ((A xor B) and Cin);

end Behavioral;

