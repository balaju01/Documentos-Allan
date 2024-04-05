
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity sumador is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           cin : in  STD_LOGIC;
           cout : out  STD_LOGIC;
           sum : out  STD_LOGIC);
end sumador;

architecture Behavioral of sumador is
signal uno: std_logic;
signal dos: std_logic;
signal tres: std_logic;
begin
  uno<=a xor b;
  dos<=a and b;
  tres<=cin and uno;
  sum<=uno xor cin;
  cout<=dos or tres;
   


end Behavioral;

