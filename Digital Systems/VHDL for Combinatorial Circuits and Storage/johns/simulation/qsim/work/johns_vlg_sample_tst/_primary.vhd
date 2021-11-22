library verilog;
use verilog.vl_types.all;
entity johns_vlg_sample_tst is
    port(
        Clkn            : in     vl_logic;
        Clrn            : in     vl_logic;
        E               : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end johns_vlg_sample_tst;
