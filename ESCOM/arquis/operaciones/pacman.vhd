library IEEE;
use IEEE.STD_LOGIC_1164.all;

package pacman is

component sumador Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Ci : in  STD_LOGIC;
           Co : out  STD_LOGIC;
           F : out  STD_LOGIC);
			  end component;

end pacman;

