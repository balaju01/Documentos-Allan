-- Modúlo de banderas
--
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity flags is port (
      D: in std_logic;
	  RE: in std_logic_vector (2 downto 0);--registro de estado ZVC
	  RFLAGS: out std_logic_vector (2 downto 0)--registro de banderas ZVC
	);-- acumulador permanente, hacia la ALU
end flags;
architecture a_flags of flags is
begin
     process (D) begin
        if (D' event and D= '1') then
             RFLAGS<= RE;
        end if;
      end process;
end a_flags;
