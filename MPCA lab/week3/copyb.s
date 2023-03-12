// Program to transfer a block of data from location A to location B.
.DATA
		A:  .byte 23,43,65,34,76,87,55,36,55,98
		B:  .byte 0,0,0,0,0,0,0,0,0,0
.TEXT
	LDR R1, =A     //INITIALIZATION OF THE BLOCK ADDRESSES
	LDR R2, =B

	MOV R5,#1
L1:	LDRB R3, [R1]      //BACKWARD=PC=PC+4-OFFSET, FORWARD=PC=PC+4+OFFSET
	STRB R3, [R2]
	ADD R1, R1,#1     //ADDRESS TO THE NEXT DATA
	ADD R2, R2,#1
	
	ADD R5, R5, #1   // INCREMENT THE COUNT REGISTER
	CMP R5, #11      //CHECK WHETHER ALL NUMBERS ARE ADDED
	BNE L1          // EKSE BRANCH TO L1 LOCATION
	SWI 0X011      //LOGICAL END OF THE PROGGRAM
