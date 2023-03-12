;Write a program in ARM7TDMI-ISA to check the parity of  given 32 bit 
;number using function subprogram PARITYCHECK. Display appropriate  
;messages as ODD PARITY or EVEN PARITY number.

.DATA
    ODD: .ASCIZ "ODD PARITY NUMBER"
   EVEN: .ASCIZ "EVEN PARITY NUMBER"
      A: .WORD 0X000000000
	  
.TEXT
     LDR R2,=A
	 LDR R3,[R2]
	 MOV R6,#0  ; COUNT REGISTER
	 MOV R4,#0  ; COUNT NUMBER OF 1S.
	     
L2:  TST R3,#1
	 BNE L1
LOOP:MOV R3,R3,LSR #1
     ADD R6,R6,#1
     CMP R6,#32
	 BNE L2
	 TST R4,#1
	 BEQ L3
	 LDR R0,=ODD
	 SWI 0X02
	 B EXIT
 L3: LDR R0,=EVEN
	 SWI 0X02
	 
EXIT:SWI 0X011
	 
  L1:ADD R4,R4,#1
     B LOOP
	 
.END
	 
	 
	 
	 
	 
	 
	 