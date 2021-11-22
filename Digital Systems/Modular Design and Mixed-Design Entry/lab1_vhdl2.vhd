library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity lab1_vhdl2 is
port (
w1, w2, w3, w4			: in std_logic;
g, h			: out std_logic
		);
end lab1_vhdl2;

architecture Behavior of lab1_vhdl2 is
begin
	g <= (w1 and w2) or (w3 and w4);
	h <= (w1 and w3) or (w2 and w4);
end Behavior;