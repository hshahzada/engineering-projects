onerror {quit -f}
vlib work
vlog -work work decodmodified.vo
vlog -work work decodmodified.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.decodmodified_vlg_vec_tst
vcd file -direction decodmodified.msim.vcd
vcd add -internal decodmodified_vlg_vec_tst/*
vcd add -internal decodmodified_vlg_vec_tst/i1/*
add wave /*
run -all
