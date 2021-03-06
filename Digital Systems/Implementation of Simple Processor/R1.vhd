library ieee;
use ieee.std_logic_1164.all;

entity R1 is
	port(
		D		: in std_logic_vector(7 downto 0);
		LD_R1	: in std_logic;
		clk	: in std_logic;
		Q		: out std_logic_vector(7 downto 0)
		);
end R1;

architecture Behavior of R1 is
begin
	process (LD_R1)
	begin	
		if (clk'EVENT and clk = '1') then
			if (LD_R1 = '1') then
				Q <= D;
			end if;
		end if;
	end process;
end Behavior;