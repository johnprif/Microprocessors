onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/we
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/re
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/datawr
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/addr
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/instraddr
add wave -noupdate -radix unsigned -childformat {{{/MCPU_RAMController_tb_v2/datard[7]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[6]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[5]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[4]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[3]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[2]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[1]} -radix unsigned} {{/MCPU_RAMController_tb_v2/datard[0]} -radix unsigned}} -subitemconfig {{/MCPU_RAMController_tb_v2/datard[7]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[6]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[5]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[4]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[3]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[2]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[1]} {-radix unsigned} {/MCPU_RAMController_tb_v2/datard[0]} {-radix unsigned}} /MCPU_RAMController_tb_v2/datard
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/instrrd
add wave -noupdate -radix unsigned /MCPU_RAMController_tb_v2/iscorrect
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {2048 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {1005 ps} {1141 ps}
