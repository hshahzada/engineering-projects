onerror {quit -f}
vlib work
vlog -work work johns.vo
vlog -work work johns.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.johns_vlg_vec_tst
vcd file -direction johns.msim.vcd
vcd add -internal johns_vlg_vec_tst/*
vcd add -internal johns_vlg_vec_tst/i1/*
add wave /*
run -all
