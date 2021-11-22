library verilog;
use verilog.vl_types.all;
entity decodmodified is
    port(
        w               : in     vl_logic_vector(2 downto 0);
        En              : in     vl_logic;
        y               : out    vl_logic_vector(0 to 7)
    );
end decodmodified;
