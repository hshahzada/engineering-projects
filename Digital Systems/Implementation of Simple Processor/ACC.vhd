library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ACC is
	port(
		D		: in unsigned (7 downto 0);
		SHL_ACC, SHR_ACC, clk, reset	: in std_logic;
		Q		: out unsigned (7 downto 0));
end ACC;

architecture Behavior of ACC is
signal store_signal:	unsigned (7 downto 0)	:= (others => '0');
begin
	process (SHL_ACC, clk, reset, SHR_ACC, D)
	begin	
		if (reset = '0') then
			store_signal <= "00000000";
		elsif ((reset = '1') and (rising_edge(clk))) then
				store_signal <= D;
				if (SHL_ACC = '1') then
					store_signal <= store_signal sll 1;
				end if;
				if (SHR_ACC = '1') then
					store_signal <= store_signal srl 1;
				end if;
			end if;
		end process;
		Q <= store_signal;
	end Behavior;