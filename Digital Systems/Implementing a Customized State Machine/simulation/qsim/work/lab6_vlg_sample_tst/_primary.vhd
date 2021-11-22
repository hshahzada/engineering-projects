library verilog;
use verilog.vl_types.all;
entity lab6_vlg_sample_tst is
    port(
        Clock           : in     vl_logic;
        data_in         : in     vl_logic;
        Resetn          : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end lab6_vlg_sample_tst;
