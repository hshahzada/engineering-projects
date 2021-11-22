library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity ALU is
	port(
		A,B		: in std_logic_vector (7 downto 0);
		ALU_Opcode: in std_logic_vector (3 downto 0);
		Output_bus : out	std_logic_vector(7 downto 0)
		);
end ALU;

architecture Behavior of ALU is
	signal ALU_Result :	std_logic_vector (7 downto 0);
begin
	process (A, B, ALU_Opcode)
	begin
		case (ALU_Opcode) is
			when "0000" => ALU_Result <= B;
			when "0001" => ALU_Result <= B;
			when "0010" => ALU_Result <= A+B;
			when "0011" => ALU_Result <= A-B;
			when "0100" => ALU_Result <= A + 1;
			when "0101" => ALU_Result <= A - 1;
			when "0110" => ALU_Result <= B;
			when "0111" => ALU_Result <= A and B;
			when "1000" => ALU_Result <= A or B;
			when "1001" => ALU_Result <= A xor B;
			when "1010" => ALU_Result <= A nand B;
			when "1011" => ALU_Result <= B;
			when "1100" => ALU_Result <= B;
			when "1101" => ALU_Result <= B;
			when "1110" => ALU_Result <= B;
			when "1111" => ALU_Result <= B;
		end case;	
	end process;
	Output_bus <= ALU_Result;
end Behavior;