



;Write a program in ARM7TDMI-ISA to generate a diagonal matrix.
;         Note: do not read the matrix elements.
.DATA 
A: .WORD 0,0,0,0,0,0,0,0,0

.TEXT
	LDR R0,=A ; ARRAY A
; LET THE DIAGONAL VALUE BE 2 
	MOV R1,#2
    MOV R2,#0	; ROW NUMBER
	MOV R3,#0   ; COL NUMBER
	MOV R5,#3   ; NUMBER OF ELEMENTS IN THE ROW
	MOV R6,#4   ; MULTIPLICATION FACTOR
	
LOOP:CMP R2,R3
	 BEQ ASSIGN
L1:  ADD R3,R3,#1
	 CMP R3,#3
	 BNE LOOP
	 MOV R3,#0
	 ADD R2,R2,#1
	 CMP R2,#3
	 BNE LOOP
	 SWI 0X011
	
ASSIGN:MLA R4,R2,R5,R3 
       MUL R4,R6,R4
       STR R1,[R0,R4] ; STORE 2 IN THE DIAGONAL POSITION
	   B L1
	
	.END