// Program to transfer a block of data from location A to location B.
.DATA
		A:  .WORD 23,43
		B:  .WORD 0,0,0,0,0,0,0
.TEXT
	LDR R4, =A     //INITIALIZATION OF THE BLOCK ADDRESSES
	LDR R5, =B
loop: LDMIA R4!, {R0-R1}
		  STMIA R5!, {R0-R1}
		  CMP R11,#16
 		  BNE   loop
