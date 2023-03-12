.text
MOV r1, #8
ANDS r2,r1,#1
BEQ L1
MOV r0,#0xFF
B L2
L1: MOV r0, #0x00
L2: SWI 0x011
.end