
LDR  R1, =A
strprint:  LDRB  R0, [R1], #1

                 CMP R0, #0

                 SWINE 0x00              // display a character on the screen.

             BNE   strprint
              SWI  0x11
/*
LDR  R1, =A
LDR  R0, [R1]
          SWI 0x02             // display a character on the screen.

         
              SWI  0x11
*/
.DATA

   A:   .asciz "HELLO WORLD"
