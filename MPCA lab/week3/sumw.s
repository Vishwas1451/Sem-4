.DATA
		A:  .WORD 1,4,3,6,4,7,4,8,6,10
		
.TEXT
	LDR R1, =A     
	
	MOV R5,#1
        MOV R6,#0
L1:	LDR R3, [R1]      
	ADD R6, R6,R3
        ADD R1, R1,#4     
	ADD R5, R5, #1   
	CMP R5, #11      
	BNE L1          
	SWI 0X011      
