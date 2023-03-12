// Program to transfer a block of data from location A to location B.
.DATA
		A:  .WORD 23,43,65,34,76,87,55,36,55,98
		B:  .WORD 0,0,0,0,0,0,0,0,0,0
.TEXT
	LDR R1, =A     //INITIALIZATION OF THE BLOCK ADDRESSES
	LDR R2, =B

	MOV R5,#1
L1:	LDR R3, [R1]      //BACKWARD=PC=PC+4-OFFSET, FORWARD=PC=PC+4+OFFSET
	STR R3, [R2]
	ADD R1, R1,#4     //ADDRESS TO THE NEXT DATA
	ADD R2, R2,#4
	
	ADD R5, R5, #1   // INCREMENT THE COUNT REGISTER
	CMP R5, #11      //CHECK WHETHER ALL NUMBERS ARE ADDED
	BNE L1          // EKSE BRANCH TO L1 LOCATION
	SWI 0X011      //LOGICAL END OF THE PROGGRAM
