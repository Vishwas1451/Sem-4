
.DATA
A: .WORD 1,2,3,4,5,6,7,8,9
SUM: .WORD 0,0,0

.TEXT

MOV R2,#0
LDR R8, =A
LDR R10, =SUM
MOV R11,#1
SUB R8,R8,#4
SUB R10,R10,#4


LOOP: LDR R6,[R8,#4]!
	ADD R2,R2,R6
	ADD R11,R11,#1
	CMP R11,#4
	BNE LOOP
        STR R2,[R10,#4]!
        MOV R2,#0
        ADD R3,R3,#1
        CMP R3,#3 
        SUB R11,R11,#3
        BNE LOOP
SWI 0X011
.END