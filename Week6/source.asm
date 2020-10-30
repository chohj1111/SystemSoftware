TEST     START   1000
FIRST    STL     RETADR
         JSUB    SUM
         LDA     TOTAL
         J       LAST
RETADR   RESW    1
SUM      LDA     #0
         STA     TOTAL
         STA     INDEX
LOOP     LDX     INDEX
         LDA     TOTAL
         ADD     TABLE,X
         STA     TOTAL
         LDA     INDEX
         ADD     #3
         STA     INDEX
         COMP    COUNT
         JLT     LOOP
         RSUB
TABLE    WORD    10
         WORD    9
         WORD    8
         WORD    20
         WORD    6
COUNT    WORD    15
TOTAL    RESW    1
INDEX    RESW    1
MAX      RESW    1
LAST     END     FIRST
