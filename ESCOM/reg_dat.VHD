-- Módulo del registro de datos 
-- Almacena un dato proveniente de la memoria de programa
--

library ieee;
use ieee.std_logic_1164.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity reg_dat is port(
     B:   in std_logic;
     RO: in std_logic_vector(7 downto 0);--proveniente de memoria de programa
     RD: out std_logic_vector(7 downto 0));--hacia la ALU
 end reg_dat;
 architecture a_dat of reg_dat is
	begin
    process (B) 
	 begin
      if  (B'event and B ='1') then
          RD <= RO;
      end if;
    end process;
   end a_dat;

 