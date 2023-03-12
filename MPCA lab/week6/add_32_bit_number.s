.data
    A: .WORD 2312
    B: .WORD 0xCCCCCCCD

.text
    mov r0,#0
    LDR r1,=A 
    LDR r2,[r1]
    ldr r4,=B
    LDR r5,[r4]

l1:
    CMP r2,#10
    BLT L4
    MOV r3,r2
    B L2
L2:
    CMP r3,#10
    BLT L3
    SUB r3,r3,#10
    B L2


L3:
    ADD r0,r0,r3
    UMULL r6,r2,r2,r5
    MOV r2,r2,LSR #3
    B l1
L4: 
    ADD r0,r0,r2
    .end