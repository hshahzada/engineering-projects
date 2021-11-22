library ieee;
use ieee.std_logic_1164.all;

entity encod is
	port (w	:	in std_logic_vector(3 downto 0);
			y		:		out std_logic_vector(1 downto 0);
			z			: out std_logic);
end encod;

architecture Behavior of encod is
begin
	process(w)
	begin
		y <= "00";
		if w(1) = '1' then y <= "01"; end if; -- w3 w2 w1 w0
		if w(2) = '1' then y <= "10"; end if; -- 	1	1	1	
		if w(3) = '1' then y <= "11"; end if; 
		
		z <= '1';
		
		if w = "0000" then z<= '0'; end if;
	end process;
end Behavior;