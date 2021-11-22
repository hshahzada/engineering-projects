library ieee;
use ieee.std_logic_1164.all;

entity mux2to1 is
	port (w0, w1, s				:	in			std_logic;
				f						:	out		std_logic);

end mux2to1;

architecture Behavior of mux2to1 is
begin
	with s select
		f <= w0 when '0',
				w1 when others;

end Behavior;