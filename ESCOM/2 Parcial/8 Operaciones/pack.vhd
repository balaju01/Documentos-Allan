library IEEE;
use IEEE.STD_LOGIC_1164.all;

package pack is

component sumaC Port ( b1 : in  STD_LOGIC;
           b2 : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           Cout : out  STD_LOGIC;
           Sal : out  STD_LOGIC);
end component;

end pack;
