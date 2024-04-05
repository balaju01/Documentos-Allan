library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.pack.all;

entity main is

		port (A: in std_logic_vector(3 downto 0);
				Ci: in std_logic;
				--S1: in std_logic;
				--S2: in std_logic;
				clk: in std_logic;
				clk2: out std_logic;
				Sa: out std_logic_vector(3 downto 0)
		);
		
end main;

architecture acum  of main is

signal B: std_logic_vector(3 downto 0);
signal J: std_logic_vector(3 downto 0):="0000";
signal K: std_logic_vector(3 downto 0):="1111";
signal Cout: std_logic_vector(3 downto 0);
signal Sal: std_logic_vector(3 downto 0);
signal vclk6: std_logic;

begin

reloj: vclk port map(clk, vclk6);
clk2 <= vclk6;
registro: reg port map(J, K, vclk6, B);
bitS1: suma port map(A(0), B(0), Ci, Sal(0), Cout(0));
bitS2: suma port map(A(1), B(1), Cout(0), Sal(1), Cout(1));
bitS3: suma port map(A(2), B(2), Cout(1), Sal(2), Cout(2));
bitS4: suma port map(A(3), B(3), Cout(2), Sal(3), Cout(3));
	
	
J(0) <= Ci xor A(0);
J(1) <= Ci xor A(1);
J(2) <= Ci xor A(2);
J(3) <= Ci xor A(3);

K(0) <=  (not B(0));
K(1) <=  (not B(1));
K(2) <=  (not B(2));
K(3) <=  (not B(3));
	--	J(0) <= Sal(0) or ((not Ci) and S1);
	--	J(1) <= Sal(1) or ((not Ci) and S1);
	--	J(2) <= Sal(2) or ((not Ci) and S1);
	--J(3) <= Sal(3) or ((not Ci) and S1);
	
	--K(0) <= ((not S1) and Sal(0)) or (Ci and Sal(0));
	--K(1) <= ((not S1) and Sal(1)) or (Ci and Sal(1));
	--K(2) <= ((not S1) and Sal(2)) or (Ci and Sal(2));
	--K(3) <= ((not S1) and Sal(3)) or (Ci and Sal(3));
Sa <= B;
end acum;


