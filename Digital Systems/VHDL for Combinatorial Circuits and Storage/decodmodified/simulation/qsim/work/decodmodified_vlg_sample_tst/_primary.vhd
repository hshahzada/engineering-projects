library verilog;
use verilog.vl_types.all;
entity decodmodified_vlg_sample_tst is
    port(
        En              : in     vl_logic;
        w               : in     vl_logic_vector(2 downto 0);
        sampler_tx      : out    vl_logic
    );
end decodmodified_vlg_sample_tst;
