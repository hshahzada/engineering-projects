library ieee;
use ieee.std_logic_1164.all;

entity C is
port(
	S	:	in		std_logic_vector(3 downto 0);
	L	:	out	std_logic_vector(3 downto 0)
	);
end C;

architecture Behavior of C is
begin
	L(3) <= (S(0) and S(1) and not S(2) and not S(3));
	L(2) <= (not S(0) and not S(1) and not S(2)) or
	(not S(0) and not S(1) and not S(3));
	L(1) <= (S(0) and not S(1) and S(2) and not S(3));
	L(0) <= (not S(1) and S(2) and not S(3)) or 
	(not S(0) and not S(1) and not S(3)) or 
	(S(0) and S(1) and not S(2) and not S(3));
end Behavior;