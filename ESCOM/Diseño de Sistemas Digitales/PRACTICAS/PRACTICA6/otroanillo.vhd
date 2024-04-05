entity anillo is
	port(
			clr, clk: in std_logic;
			q:inout std_logic_vector(2 downto 0);
			C:in std_logic_vector(2 downto 0);
			F:in std_logic_vector(3 downto 0);
			DISP:out std_logic_vector(7 downto 0)
		);
end anillo;

architecture contador of anillo is
begin
	anillo: process(clr,clk)
	begin	
		if(clr ='1')then
			q<="001"
		elsif(clk'event and clk='1')then
			q<to_stdlogicvector (to_bitvector(q) rol1);
		end if;
	end process;
end anillo