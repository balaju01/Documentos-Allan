library IEEE;
use IEEE.STD_LOGIC_1164.all;

package micros_package is

component mp4
generic (ram_addr_bits:integer:=5; ram_width:integer:=8);
    Port ( clk : in  STD_LOGIC;
			  reset : in STD_LOGIC;
			  ACC : out STD_LOGIC_VECTOR(ram_width-1 downto 0);
			  RFLAGS: out std_logic_vector (2 downto 0);
			  data_ready: out std_logic);

end component;

component gcm port(
 CLK,RESET: in std_logic;
 A,B,C,D,E: out std_logic;
 Q: inout std_logic_vector (3 downto 0));
 
end component;

component pcount 
generic (ram_addr_bits:integer:=5);
port (
      E: in std_logic;
     DI: in std_logic_vector (0 to 9);
     PC: out std_logic_vector (ram_addr_bits-1 downto 0));
	  
end component;

component reg_ins port (
 A: in std_logic;
 RO: in std_logic_vector (7 downto 0);
 RI: out std_logic_vector (7 downto 0));

end component;

component reg_dat port(
     B:   in std_logic;
     RO: in std_logic_vector(7 downto 0);
     RD: out std_logic_vector(7 downto 0));
	  
end component;

component acct port (
        C: in std_logic;
       OP: in std_logic_vector (7 downto 0);
      ACT: out std_logic_vector (7 downto 0));

end component;

component acum port (
      D: in std_logic;
    ACT: in std_logic_vector (7 downto 0);
    ACC: out std_logic_vector (7 downto 0));
	 
end component;

component deco_ins port(
 RI: in std_logic_vector (7 downto 0);
 DI: out std_logic_vector (0 to 9));

end component;

component alu port(
     DI: in std_logic_vector (0 to 9);--proveniente del decodificador de instrucciones
     RD: in std_logic_vector (7 downto 0);--proveniente del registro de datos
    ACC: in std_logic_vector (7 downto 0);--proveniente del acumulador permanente
     OP: inout std_logic_vector (7 downto 0);--resultado de la operacion
	  RE: inout std_logic_vector (2 downto 0));--registro de estado ZVC
end component;

component flags port (
      D: in std_logic;
	  RE: in std_logic_vector (2 downto 0);--registro de estado ZVC
	  RFLAGS: out std_logic_vector (2 downto 0)--registro de banderas ZVC
	);-- acumulador permanente, hacia la ALU
end component;

component RAM_mem1 
generic (ram_addr_bits:integer:=5; ram_width:integer:=8);
port(
		ram_enable, write_enable : in std_logic;		
		address : in std_logic_vector (ram_addr_bits-1 downto 0);
		data_in : in std_logic_vector(ram_width-1 downto 0);
		data_out : out std_logic_vector(ram_width-1 downto 0);
		data_ready : out std_logic
);

end component;

end micros_package;


