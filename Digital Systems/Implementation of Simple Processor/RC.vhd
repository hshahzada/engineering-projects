library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity RC is
	port(
		D		: in unsigned (7 downto 0);
		LD_RC	: in std_logic;
		Dec_RC: in std_logic;
		clk	: in std_logic;
		Q		: out unsigned (7 downto 0));
end RC;

architecture Behavior of RC is
signal Q_signal:	unsigned (7 downto 0);
begin
	process (clk, LD_RC, Dec_RC)
	begin	
		if (clk'EVENT and clk = '1') then
			if (LD_RC = '1') then
				Q_signal <= D;
			elsif (Dec_RC = '1') then
				Q_signal <= Q_signal - 1;
			end if;
		end if;
	end process;
	Q <= Q_signal;
end Behavior;