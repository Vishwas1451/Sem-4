.DATA
A: .WORD 1,2,3,4,5,6,7
B: .asciz "UNSUCCESSFUL SEARCH"
C: .asciz "SUCCESSFUL SEARCH"

.TEXT
LDR R6,=A
MOV R1,#7
MOV R4,#1
MOV R12,#4
LDR R2,[R6]
LDR R3,[R6,#24]
L1:ADD R5,R1,R4
   MOV R5,R5,LSR#1
   MUL R11,R12,R5
   SUB R11,R11,#4
   LDR R10,[R6,R11]
   CMP R10,#9
   BEQ L5
   CMP R10,#9
   BGT L2
   CMP R10,#9
   BLT L3

L2:SUB R1,R5,#1
   CMP R4,R1
   BLE L1
   B L4

L3:ADD R4,R5,#1
   CMP R4,R1
   BLE L1
   B L4

L4:LDR R7,=B
strprints:  LDRB  R0, [R7], #1
           CMP R0, #0
           SWINE 0x00              
           BNE   strprints
           SWI  0x11
L5:LDR R9,=C
strprint:  LDRB  R0, [R9], #1
           CMP R0, #0
           SWINE 0x00              
           BNE   strprint
           SWI  0x11