;Write a program in ARM7TDMI-ISA to find the sum of all the positive 
;numbers in the array. Use subroutine SUMPOSITIVE for the same.

.DATA
        A: .WORD 1,-2,3,4,5,-6,7,8,-9,-10
	  SUM: .WORD 0
	 
.TEXT 
      LDR R0,=A  ; ARRAY
	  MOV R1,#0  ; INDEX VARIABLE
	  MOV R2,#0   ; SUM VARIABLE
	  LDR R4,=SUM
	  
      BL LOOP
	  STR R2,[R4]
	  SWI 0X011
	  
	  
LOOP: LDR R3,[R0],#4
      
	MOVS R3,R3
	  BPL POSITIVE
  L1: ADD R1,R1,#1  
      CMP R1,#10
	  BNE LOOP
	  MOV PC,LR
	  	  
POSITIVE: ADD R2,R2,R3
          B L1
	 