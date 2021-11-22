library verilog;
use verilog.vl_types.all;
entity C_vlg_check_tst is
    port(
        L               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end C_vlg_check_tst;
