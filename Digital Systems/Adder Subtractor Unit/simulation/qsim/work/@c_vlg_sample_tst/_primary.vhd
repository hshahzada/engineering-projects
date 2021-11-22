library verilog;
use verilog.vl_types.all;
entity C_vlg_sample_tst is
    port(
        S               : in     vl_logic_vector(3 downto 0);
        sampler_tx      : out    vl_logic
    );
end C_vlg_sample_tst;
