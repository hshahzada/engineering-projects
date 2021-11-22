library ieee;
use ieee.std_logic_1164.all;

entity PC_comb_ckt_example1 is
	port(
		Clock, Resetn		: in std_logic;
		RC : in std_logic_vector(7 downto 0);
		s:	out std_logic_vector (3 downto 0);
		Dec_RC, LD_R1, LD_RC, SHL_Acc, SHR_Acc : out std_logic
		);
end PC_comb_ckt_example1;

architecture Behavior of PC_comb_ckt_example1 is
	type state_type is (s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10,
	s11, s12, s13);
	signal y:	state_type;
	signal control_signal :	std_logic_vector(8 downto 0);
	signal Op:					std_logic_vector(7 downto 0)	:= X"00";
	begin
		process (Clock, Resetn)
		begin
			if (Resetn = '0') then
				y <= s0;
			elsif (Clock 'EVENT and Clock = '1') then
				case y is
				when s0 => y <= s1;
				when s1 => y <= s2;
				when s2 => y <= s3;
				when s3 => y <= s4;
				when s4 => y <= s5;
				when s5 => y <= s6;
				when s6 => y <= s7;
				when s7 => y <= s8;
				when s8 => y <= s9;
				when s9 => y <= s10;
				when s10 => y <= s11;
				when s11 => y <= s12;
				when s12 => y <= s13;
				when s13 =>
					if (Resetn = '0') then
						y <= s0;
					end if;
				end case;
			end if;
		end process;
		
		process(y)
		begin
			case y is
				when s0 => Op <= X"0F"; -- rest
				when s1 => Op <= X"00"; -- load R1 0
				when s2 => Op <= X"07"; -- and
				when s3 => Op <= X"00"; -- load X1
				when s4 => Op <= X"02"; -- add
				when s5 => Op <= X"00"; -- load X2
				when s6 => Op <= X"02"; -- add
				when s7 => Op <= X"00"; -- load X3
				when s8 => Op <= X"02"; -- add
				when s9 => Op <= X"00"; -- load X4
				when s10 => Op <= X"02"; -- add
				when s11 => Op <= X"0C"; -- SRA
				when s12 => Op <= X"0C"; -- SRA
				when s13 => Op <= X"0F"; -- rest
			end case;
			case Op is
				when X"00" => control_signal <= "000010000"; -- LDR1
				when X"01" => control_signal <= "000100000"; -- LDRC
				when X"02" => control_signal <= "000000010"; -- ADDA
				when X"03" => control_signal <= "000000011"; -- SUBA
				when X"04" => control_signal <= "000000100"; -- INCA
				when X"05" => control_signal <= "000000101"; -- DECA
				when X"06" => control_signal <= "001000000"; -- DEC_RC
				when X"07" => control_signal <= "000000111"; -- ANDA
				when X"08" => control_signal <= "000001000"; -- ORA
				when X"09" => control_signal <= "000001001"; -- XORA
				when X"0A" => control_signal <= "000001010"; -- NANDA
				when X"0B" => control_signal <= "010000000"; -- SLA
				when X"0C" => control_signal <= "100000000"; -- SRA
				when X"0D" => control_signal <= "000000000"; -- BNEQ
				when others => control_signal <= "000000000"; -- REST
			end case;
		end process;
		s <= control_signal (3 downto 0);
		LD_R1 <= control_signal (4);
		LD_RC <= control_signal (5);
		Dec_RC <= control_signal (6);
		SHL_Acc <= control_signal (7);
		SHR_Acc <= control_signal (8);
	end Behavior;


			