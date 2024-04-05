library IEEE;
use work.micros_package.all;
use IEEE.STD_LOGIC_1164.ALL;


entity mp4 is
generic (ram_addr_bits:integer:=5; ram_width:integer:=8);
    Port ( clk : in  STD_LOGIC;
			  reset : in STD_LOGIC;
			  ACC : out STD_LOGIC_VECTOR(ram_width-1 downto 0);
			  RFLAGS: out std_logic_vector (2 downto 0);
			  data_ready: out std_logic);
end mp4;

architecture arc_micro of mp4 is

signal Q: std_logic_vector (3 downto 0):="0000";
signal A,B,C,D,E: std_logic;
signal DI: std_logic_vector(0 to 9);
signal PC: std_logic_vector(ram_addr_bits-1 downto 0);
signal RO: std_logic_vector(7 downto 0);
signal ROI: std_logic_vector(7 downto 0);
signal ROD: std_logic_vector(7 downto 0);
signal RI: std_logic_vector(7 downto 0);
signal RD: std_logic_vector(7 downto 0);
signal OP: std_logic_vector(7 downto 0);
signal ACT: std_logic_vector(7 downto 0);
signal ACC2 : STD_LOGIC_VECTOR(ram_width-1 downto 0);
signal RE: std_logic_vector(2 downto 0);
signal ram_enable: std_logic:='1';
signal write_enable: std_logic:='0';
signal data_in: std_logic_vector(ram_width-1 downto 0);



begin

gcm1: gcm port map (clk,reset,A,B,C,D,E,Q);

regint1: reg_ins port map (A,ROI,RI);
regdat1: reg_dat port map (B,ROD,RD);
acct1: acct port map(C,OP,ACT);
acum1: acum port map(D,ACT,ACC2);
pcount1: pcount port map (E,DI,PC);

Memori: RAM_mem1 port map(ram_enable,write_enable,PC,data_in,RO,data_ready);

decoins1: deco_ins port map(RI,DI);
flags1: flags port map(D,RE,RFLAGS);
alu1: alu port map(DI,RD,ACC2,OP,RE);

ACC <= ACC2;

process(PC)
begin

	if PC(0) = '0' then
		ROI <= RO;
	else
		ROD <= RO;
	end if;
	
end process;
end arc_micro;

