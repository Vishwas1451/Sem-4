;R7 HOLDS THE NUMBER OF OCCURENCES

.DATA
A: .asciz "MY NAME IS BOND"
B: .asciz "N"



.TEXT
	LDR R1, =A     
	LDR R2, =B
        MOV R7,#0 
L1:	LDRB R3, [R1]      
	LDRB R4, [R2]
        CMP R3,R4
        BEQ L2 
        ADD R1, R1,#1  	 
	CMP R3, #0    
	BNE L1   
        SWI 0X11
L2:     ADD R7,R7,#1 
        ADD R1, R1,#1   
        B L1       
	      

