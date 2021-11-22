library ieee;
use ieee.std_logic_1164.all;

entity lab6 is
	port(
			Clock, Resetn	:  in std_logic;
			data_in			:  in std_logic;
			student_id		:	out std_logic_vector(3 downto 0);
			current_state	:	out std_logic_vector(3 downto 0)
			);
end lab6;


architecture Behavior of lab6 is
	type state_type is (s0, s1, s2, s3, s4, s5, s6, s7);
	signal y				: state_type;
begin
	process (Clock, Resetn)
	begin
		if (Resetn = '0') then
			y <= s0;
		elsif (Clock'event and Clock = '1') then
			case y is
				when s0 =>
					case data_in is
						when '0' => y <= s4;
						when '1' => y <= s1;
						when others => y <= s0;
					end case;
				when s1 =>
					case data_in is
						when '0' => y <= s6;
						when '1' => y <= s2;
						when others => y <= s1;
					end case;
				when s2 =>
					case data_in is
						when '0' => y <= s3;
						when '1' => y <= s6;
						when others => y <= s2;
					end case;
				when s3 =>
					case data_in is
						when '0' => y <= s3;
						when '1' => y <= s3;
						when others => y <= s3;
					end case;
				when s4 =>
					case data_in is
						when '0' => y <= s5;
						when '1' => y <= s6;
						when others => y <= s4;
					end case;
				when s5 =>
					case data_in is
						when '0' => y <= s2;
						when '1' => y <= s7;
						when others => y <= s5;
					end case;
				when s6 =>
					case data_in is
						when '0' => y <= s6;
						when '1' => y <= s6;
						when others => y <= s6;
					end case;
				when s7 =>
					case data_in is
						when '0' => y <= s7;
						when '1' => y <= s3;
						when others => y <= s7;
					end case;
				end case;
			end if;
		end process;

		process (y, data_in)
		begin
			case y is
				when s0 =>
						student_id    <= X"5"; -- 1st digit of student id
						current_state <= X"0";
				when s1 =>
						student_id    <= X"0"; -- 2nd digit of student id
						current_state <= X"1";
				when s2 =>
						student_id    <= X"0"; -- 3rd digit of student id
						current_state <= X"2";
				when s3 =>
						student_id    <= X"9"; -- 4th digit of student id
						current_state <= X"3";
				when s4 =>
						student_id    <= X"5"; -- 5th digit of student id
						current_state <= X"4";
				when s5 =>
						student_id    <= X"3"; -- 6th digit of student id
						current_state <= X"5";
				when s6 =>
						student_id    <= X"0"; -- 7th digit of student id
						current_state <= X"6";
				when s7 =>
						student_id    <= X"0"; -- 8th digit of student id
						current_state <= X"7";
			end case;
		end process;
end Behavior;