library ieee;
use ieee.std_logic_1164.all;

entity decodmodified is
	port (w		:		in			std_logic_vector (2 downto 0);
				En		:		in		std_logic;
				y		:		out std_logic_vector (0 to 7));
end decodmodified;

architecture Behavior of decodmodified is
		component dec2to4
			port (w	:		in		std_logic_vector (1 downto 0);
						En	:		in			std_logic;
						y	:		out std_logic_vector (3 downto 0));
			end component;
			
begin
	dec0:		dec2to4 port map (w(1 downto 0), not w(2) and En, y(0 to 3));
	dec1:	dec2to4	  port map (w(1 downto 0), En and w(2), y(4 to 7));

end Behavior;