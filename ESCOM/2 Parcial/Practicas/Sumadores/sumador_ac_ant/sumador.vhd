
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity sumador is
    Port ( a : in  STD_LOGIC_vector(4 downto 0);
           b : in  STD_LOGIC_vector(4 downto 0);
           cin : inout  STD_LOGIC;
           cout : inout  STD_LOGIC_vector(5 downto 0);
           suma : out  STD_LOGIC_vector(5 downto 0));
end sumador;

architecture Behavioral of sumador is
begin
 
  process(a,b,cin)
   variable n: natural := 0; 
   begin

    for n in 0 to 4 loop
	  if n=0 then 
	   cout(n)<=cin;
	  else
		cout(n)<=(a(n-1) and b(n-1))or((a(n-1) xor b(n-1))and cout(n-1));
	  end if;
	  suma(n)<=a(n) xor b(n) xor cout(n);
	 end loop;
	 suma(n+1)<=(a(n) and b(n))or((a(n) xor b(n))and cout(n));
  end process;

-- process(a,b,cin) 
--   begin
--	  sum<=a xor b ;
--	  cout<=(a and b)or cin;
--end process;
end Behavioral;

