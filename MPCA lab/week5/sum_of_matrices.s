//TO FIND SUM OF N DATA ITEMS IN THE MEMORY.STORE THE RESULY
//USING PRE-INDEXING ADDRESSING WITH WRITE BACK MODE

.DATA
A: .WORD 1,2,3,4
B: .WORD 1,2,3,4
SUM: .WORD 0,0,0,0

.TEXT

MOV R2,#0
LDR R8, =A
LDR R9,=B
LDR R10, =SUM
MOV R11,#1
SUB R8,R8,#4
SUB R9,R9,#4
SUB R10,R10,#4
MOV R12,#1

LOOP: LDR R6,[R8,#4]!
      LDR R7,[R9,#4]!
	ADD R2,R6,R7
	ADD R11,R11,#1
        STR R2,[R10,#4]!
	CMP R11,#5
	BNE LOOP
SWI 0X011
.END