library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is
    Port ( A : in  STD_LOGIC_VECTOR (2 downto 0);
           B : in  STD_LOGIC_VECTOR (2 downto 0);
           Cin : in  STD_LOGIC;
           disp : out  STD_LOGIC_VECTOR (7 downto 0);
           an : out  STD_LOGIC_VECTOR (3 downto 0);
           S1 : in  STD_LOGIC);
end main;

architecture Behavioral of main is

signal Cout: STD_LOGIC_VECTOR(2 downto 0);
signal Sal : STD_LOGIC_VECTOR (2 downto 0);
signal B1 : STD_LOGIC_VECTOR (2 downto 0);
signal A1 : STD_LOGIC_VECTOR (2 downto 0);

begin

an <= "1110";

B1(0) <= ((not (Cin) and (not B(0))) and S1) or (S1 and B(0)) or (Cin and B(0));
B1(1) <= ((not (Cin) and (not B(1))) and S1) or (S1 and B(1)) or (Cin and B(1));
B1(2) <= ((not (Cin) and (not B(2))) and S1) or (S1 and B(2)) or (Cin and B(2));

A1(0) <= (S1 or (Cin  and (not (A(0)))));
A1(1) <= (S1 or (Cin  and (not (A(1)))));
A1(2) <= (S1 or (Cin  and (not (A(2)))));

bit1 : sumador port map(A1(0), B1(0), Cin, Sal(0), Cout(0));
bit2 : sumador port map(A1(1), B1(1), Cout(0), Sal(1), Cout(1));
bit3 : sumador port map(A1(2), B1(2), Cout(1), Sal(2), Cout(2));

process(sal)

begin

case(sal) is

when "000" => disp<="00000011";
when "001" => disp<="10011111";
when "010" => disp<="00100101";
when "011" => disp<="00001101";
when "100" => disp<="10011001";
when "101" => disp<="01001001";
when "110" => disp<="01000001";
when "111" => disp<="00011111";
when others => disp<="00000000";

end case;
end process;

end Behavioral;

