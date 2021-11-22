library verilog;
use verilog.vl_types.all;
entity decodmodified_vlg_check_tst is
    port(
        y               : in     vl_logic_vector(0 to 7);
        sampler_rx      : in     vl_logic
    );
end decodmodified_vlg_check_tst;
