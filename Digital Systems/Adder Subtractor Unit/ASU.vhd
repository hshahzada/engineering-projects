library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity ASU is
	port(Cin 							:	in std_logic;
			X,Y							:	in std_logic_vector(3 downto 0);
			S								:	out std_logic_vector(3 downto 0);
			Cout, Overflow, Sign		:	out std_logic);
end ASU;

architecture Behavior of ASU is
	signal Sum	:	std_logic_vector(4 downto 0);
	signal Yp	:	std_logic_vector (3 downto 0);
begin
	-- If Cin = 0, ASU performs ADD, Yp = Y
	-- If Cin = 1, ASU performs SUB, Yp = not Y to generate 2's complement -Y
	Yp(3) <= Y(3) xor Cin;
	Yp(2) <= Y(2) xor Cin;
	Yp(1) <= Y(1) xor Cin;
	Yp(0) <= Y(0) xor Cin;
	
	Sum <= ('0' & X) + ('0' & Yp) + Cin;
	S <= Sum(3 downto 0);
	Cout <= Sum(4);
	Overflow <= Sum(4) xor X(3) xor Yp(3) xor Sum(3);
	Sign <= Sum(3);
end Behavior;