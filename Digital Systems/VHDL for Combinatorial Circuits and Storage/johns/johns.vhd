library ieee;
use ieee.std_logic_1164.all;

entity johns is
	port (Clrn, E, Clkn	:	in std_logic;
			STUDENT_ID 		:	out std_logic_vector(3 downto 0);
			Q					:	out std_logic_vector(0 to 2));
end johns;

architecture Behavior of johns is
	signal Qreg	:	std_logic_vector (0 to 2);
begin
	process (Clrn, Clkn)
	begin
		if(Clrn = '0') then
			Qreg <= "000";
		elsif (Clkn 'event and Clkn = '0') then
			if E = '1' then
				Qreg (0) <= not Qreg (2);
				Qreg (1) <= Qreg (0);
				Qreg (2) <= Qreg (1);
			else
				Qreg <= Qreg;
			end if;
		end if;
									-- the last 6 digits of my student ID are 953004
									--	modify the next case statement so that it gives
									-- the last 6 digits of your student ID based on the
									--	corresponding states of the johnson counter.
		
		case Qreg is
			when "000" => STUDENT_ID <= "1001"; -- 9
			when "100" => STUDENT_ID <= "0101"; -- 5
			when "110" => STUDENT_ID <= "0011"; -- 3
			when "111" => STUDENT_ID <= "0000"; -- 0
			when "011" => STUDENT_ID <= "0000"; -- 0
			when "001" => STUDENT_ID <= "0100"; -- 4
			when others => STUDENT_ID <= "----"; -- error
		end case;
	end process;
	Q <= Qreg;
End Behavior;