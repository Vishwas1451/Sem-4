//TO FIND SUM OF N DATA ITEMS IN THE MEMORY.STORE THE RESULY
//USING PRE-INDEXING ADDRESSING MODE

.DATA
A: .WORD 1,2,3,4
SUM: .WORD 0

.TEXT

MOV R2,#0
LDR R1, =A
LDR R3, =SUM
MOV R5,#0
MOV R6,#1

LOOP: LDR R4,[R1,R5]
	ADD R2,R2,R4
	ADD R5,R5,#4
	ADD R6,R6,#1
	CMP R6,#5
	BNE LOOP
STR R2,[R3]
SWI 0X011
.END