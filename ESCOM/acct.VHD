-- Modúlo del acumulador temporal
--
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity acct is port (
        C: in std_logic;
       OP: in std_logic_vector (7 downto 0);-- resultado de la operacion proveniente de la ALU
      ACT: out std_logic_vector (7 downto 0));-- hacia el acumulador permanente
end acct;
architecture a_acct of acct is
begin
     process (C) begin
         if (C'event and C= '1') then
           ACT<= OP;
         end if;
        end process;
    end a_acct;