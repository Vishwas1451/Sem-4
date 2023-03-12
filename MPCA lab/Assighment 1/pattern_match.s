/*PATTERN MATCHING*/

.DATA
A: .asciz "MY NAME IS BOND"
B: .asciz "JAMES"
C: .asciz "STRING ABSENT"
D: .asciz "STRING PRESENT"

.TEXT
	LDR R1, =A     
	LDR R2, =B
        MOV R7,#1 
L1:	LDRB R3, [R1]      
	LDRB R4, [R2]
        CMP R3,R4
        BEQ L2 
        ADD R1, R1,#1  	 
	CMP R3, #0    
	BNE L1   
        B L4      
L2:LDRB R3, [R1]      
   LDRB R4, [R2]
   CMP R3,R4
   ADDEQ R7,R7,#1
   CMP R7,#6
   BEQ L3
   CMP R3,#0
   BEQ L4 
   CMP R3,R4
   ADD R1, R1,#1 
   ADD R2, R2,#1
   BEQ L2
   CMP R4,#0
   BEQ L3
   LDR R2, =B
   ADD R1, R1,#1
   ADD R2, R2,#1
   B L1	      

L3:LDR R7,=D
strprints:  LDRB  R0, [R7],#1
           CMP R0, #0
           SWINE 0x00             
           BNE strprints
           SWI  0x11

L4:LDR R9,=C
strprint:  LDRB  R0, [R9], #1
           CMP R0, #0
           SWINE 0x00              
           BNE   strprint
           SWI  0x11

