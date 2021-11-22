library ieee;
use ieee.std_logic_1164.all;

entity lab1_vhdl1 is
port (
		x1, x2, x3		: in	std_logic;
		f					: out std_logic
		);
		
end lab1_vhdl1;

architecture Behavior of lab1_vhdl1 is
begin
	f <= (x1 and x2) or (not x2 and x3);
end Behavior;