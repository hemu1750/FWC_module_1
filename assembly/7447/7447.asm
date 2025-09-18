.include "m328pdef.inc"     
.def temp = r16              
.def Q1   = r17              
.def Q2   = r18              
.def Y    = r19          

.org 0x0000
    rjmp RESET

RESET:
    ldi temp, LOW(RAMEND)
    out SPL, temp
    ldi temp, HIGH(RAMEND)
    out SPH, temp
    cbi DDRD, 0
    sbi DDRB, 0
    clr Q1
    clr Q2

MAIN:
    in temp, PIND
    andi temp, 0x01
    mov Q1, temp
    mov Q2, Q1
    com Q2
    and Q1, Q2
    mov Y, Q1

    sbrc Y, 0
    sbi PORTB, 0
    sbrs Y, 0
    cbi PORTB, 0

    rjmp MAIN
