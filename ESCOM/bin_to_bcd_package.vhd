-------------------------------------------------------
-- Design Name : User Package
-- File Name   : bin_to_bcd_package.vhd
-- Function    : 8 bit Binary to BCD converter - Double Dabble algorithm
-------------------------------------------------------
library ieee;
    use ieee.std_logic_1164.all;
    use ieee.std_logic_unsigned.all;
    
package bin_to_bcd_package is

	function to_bcd ( bin : std_logic_vector(7 downto 0) ) return std_logic_vector;
	
	COMPONENT bcd_ASCII IS
	PORT(
	 BCD : IN STD_LOGIC_VECTOR(3 downto 0);	     
     ASCII : OUT STD_LOGIC_VECTOR(7 downto 0)
	);
	END COMPONENT;		

	COMPONENT bcd_7seg IS
		PORT(BCD : IN STD_LOGIC_VECTOR(3 downto 0);	     
			 D7seg : OUT STD_LOGIC_VECTOR(6 downto 0)
		);
	END COMPONENT;	
end;

package body bin_to_bcd_package is

	function to_bcd ( bin : std_logic_vector(7 downto 0) ) return std_logic_vector is
		variable i : integer:=0;
		variable bcd : std_logic_vector(11 downto 0) := (others => '0');
		variable bint : std_logic_vector(7 downto 0) := bin;

	begin
		for i in 0 to 7 loop  -- repeating 8 times.
			bcd(11 downto 1) := bcd(10 downto 0);  --shifting the bits.
			bcd(0) := bint(7);
			bint(7 downto 1) := bint(6 downto 0);
			bint(0) :='0';

			if(i < 7 and bcd(3 downto 0) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(3 downto 0) := bcd(3 downto 0) + "0011";
			end if;

			if(i < 7 and bcd(7 downto 4) > "0100") then --add 3 if BCD digit is greater than 4.
				bcd(7 downto 4) := bcd(7 downto 4) + "0011";
			end if;

			if(i < 7 and bcd(11 downto 8) > "0100") then  --add 3 if BCD digit is greater than 4.
				bcd(11 downto 8) := bcd(11 downto 8) + "0011";
			end if;			
		end loop;
		return bcd;
	end to_bcd;
		
end package body;

--The scratch space is initialized to all zeros, and then the value to be converted is copied into the "original register" space on the right.
--0000 0000 0000 11110011
--
--Then, the algorithm iterates n times. On each iteration, the entire scratch space is left-shifted one bit. 
--However, before the left-shift is done, any BCD digit which is greater than 4 is incremented by 3. 
--The increment ensures that a value of 5, incremented and left-shifted, becomes 16, thus correctly "carrying" into the next BCD digit.
--
--The double-dabble algorithm, performed on the value 243, looks like this:
--0000 0000 0000 11110011      Initialization
--0000 0000 0001 11100110      Shift
--0000 0000 0011 11001100      Shift
--0000 0000 0111 10011000      Shift
--0000 0000 1010 10011000      Add 3 to ONES, since it was 7
--0000 0001 0101 00110000      Shift
--0000 0001 1000 00110000      Add 3 to ONES, since it was 5
--0000 0011 0000 01100000      Shift
--0000 0110 0000 11000000      Shift
--0000 1001 0000 11000000      Add 3 to TENS, since it was 6
--0001 0010 0001 10000000      Shift
--0010 0100 0011 00000000      Shift