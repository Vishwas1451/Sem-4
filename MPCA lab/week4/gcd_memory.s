MOV R1,#86
MOV R2,#93

LOOP: CMP R1,R2
      SUBGT R1,R1,R2
      SUBLT R2,R2,R1
      BNE LOOP