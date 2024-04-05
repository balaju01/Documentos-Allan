library ieee;
use iee.std_logic_1164.all;

entity secuencia is
	PORT(CLK,CLR,X: IN STD_LOGIC;
	AN0: OUT STD_LOGIC;
	DISPLAY: OUT STD_LOGIC_VECTOR (6 DOWNTO 0));

end secuencia;

architecture detector of secuencia is
SIGNAL Q0,Q1,Y:STD_LOGIC;
begin
	FSM:PROCESS(CLK,CLR)
	BEGIN
		IF (CLR='1')THEN
			Q0<='0';
			Q1<='0';
		ELSIF(CLK'EVENT AND CLK='1')THEN
			Q0<=(NOT Q1 AND X) OR (Q0 AND X);
			Q1<=(Q0 AND X) OR (Q1 AND Q0);
		END IF;
	END PROCESS FSM;
	Y<=Q1 AND NOT Q0 AND X;
	DISPLAY <= 	"0001000" WHEN( Y = '0' )ELSE 
				"0110000";
end detector;