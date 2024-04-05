library IEEE;
use IEEE.STD_LOGIC_1164.all;

package pack is

component sumador Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           F : out  STD_LOGIC;
           Cout : out  STD_LOGIC); 

end component;

end pack;