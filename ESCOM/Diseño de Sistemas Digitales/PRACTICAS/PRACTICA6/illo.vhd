entity anillo is
	port(
			clr, clk: in std_logic;
			q:inout std_logic_vector(3 downto 0)
		)
end anillo;

architecture contador of anillo is
begin
	anillo: process(clr,clk)
	begin	
		if(clr ='1')then
			q<="0001"
		elsif(clk'event and clk='1')then
			q<to_stdlogicvector (to_bitvector(q) roll);
		end if;
	end process;
end anillo