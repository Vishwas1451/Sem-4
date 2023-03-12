
.DATA
		A:  .WORD 65
		B:  .WORD 65
		C:  .WORD 45
		D:  .WORD 0
		E:  .WORD 0
		
.TEXT
	LDR R1, =A     
	LDR R2, =B 
	LDR R3, =C 
	LDR R4, =D
	LDR R9, =E
	LDR R5, [R1]
	LDR R6, [R2]
	LDR R7, [R3]
	LDR R8, [R4]
	LDR R10, [R9]
	CMP R5,R6
	BEQ L1
	CMP R6,R7
	BEQ L2
	MUL R10, R5,R6
        B L3
L1:	ADDS R7, R5, R6
	B L3
L2:	SUBS R8, R5, R6
L3:	SWI 0X011	

     
