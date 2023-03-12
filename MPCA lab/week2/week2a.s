.text
MOV r0,#7
MOV r1,#7
CMP r0,r1
BEQ L1
SUB r2,r0,r1
B L2
L1:ADD r2,r0,r1
L2:.end