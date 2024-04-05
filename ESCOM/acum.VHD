-- Modúlo del acumulador permanente
--
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity acum is port (
      D: in std_logic;
    ACT: in std_logic_vector (7 downto 0);-- proveniente del acumulador temporal
    ACC: out std_logic_vector (7 downto 0));-- acumulador permanente, hacia la ALU
end acum;
architecture a_acc of acum is
begin
     process (D) begin
        if (D' event and D= '1') then
             ACC<= ACT;
        end if;
      end process;
end a_acc;
