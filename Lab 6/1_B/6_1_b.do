onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix unsigned -childformat {{{/MCPU_Alutb_v2/opcode[1]} -radix unsigned} {{/MCPU_Alutb_v2/opcode[0]} -radix unsigned}} -subitemconfig {{/MCPU_Alutb_v2/opcode[1]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/opcode[0]} {-height 15 -radix unsigned}} /MCPU_Alutb_v2/opcode
add wave -noupdate -radix unsigned -childformat {{{/MCPU_Alutb_v2/r1[7]} -radix unsigned} {{/MCPU_Alutb_v2/r1[6]} -radix unsigned} {{/MCPU_Alutb_v2/r1[5]} -radix unsigned} {{/MCPU_Alutb_v2/r1[4]} -radix unsigned} {{/MCPU_Alutb_v2/r1[3]} -radix unsigned} {{/MCPU_Alutb_v2/r1[2]} -radix unsigned} {{/MCPU_Alutb_v2/r1[1]} -radix unsigned} {{/MCPU_Alutb_v2/r1[0]} -radix unsigned}} -subitemconfig {{/MCPU_Alutb_v2/r1[7]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[6]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[5]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[4]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[3]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[2]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[1]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r1[0]} {-height 15 -radix unsigned}} /MCPU_Alutb_v2/r1
add wave -noupdate -radix unsigned -childformat {{{/MCPU_Alutb_v2/r2[7]} -radix unsigned} {{/MCPU_Alutb_v2/r2[6]} -radix unsigned} {{/MCPU_Alutb_v2/r2[5]} -radix unsigned} {{/MCPU_Alutb_v2/r2[4]} -radix unsigned} {{/MCPU_Alutb_v2/r2[3]} -radix unsigned} {{/MCPU_Alutb_v2/r2[2]} -radix unsigned} {{/MCPU_Alutb_v2/r2[1]} -radix unsigned} {{/MCPU_Alutb_v2/r2[0]} -radix unsigned}} -subitemconfig {{/MCPU_Alutb_v2/r2[7]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[6]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[5]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[4]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[3]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[2]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[1]} {-height 15 -radix unsigned} {/MCPU_Alutb_v2/r2[0]} {-height 15 -radix unsigned}} /MCPU_Alutb_v2/r2
add wave -noupdate -radix unsigned /MCPU_Alutb_v2/OVERFLOW
add wave -noupdate -radix unsigned /MCPU_Alutb_v2/CF
add wave -noupdate /MCPU_Alutb_v2/out
add wave -noupdate /MCPU_Alutb_v2/golden_reference
add wave -noupdate /MCPU_Alutb_v2/iscorrect
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {8 ps} 0}
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
WaveRestoreZoom {5 ps} {29 ps}
