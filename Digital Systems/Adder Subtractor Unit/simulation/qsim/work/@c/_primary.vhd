library verilog;
use verilog.vl_types.all;
entity C is
    port(
        S               : in     vl_logic_vector(3 downto 0);
        L               : out    vl_logic_vector(3 downto 0)
    );
end C;
