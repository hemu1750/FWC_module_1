.equ PORTB = 0x05
.equ DDRB  = 0x04
.equ PIND  = 0x09
.equ DDRD  = 0x0A

.def tmp   = r16
.def state = r17
.def data  = r18

.equ S0 = 0
.equ S1 = 1
.equ S2 = 2

.equ SEG_0 = 0x3F
.equ SEG_1 = 0x06

.org 0x0000
    rjmp RESET

RESET:
    ldi tmp, 0x00
    out DDRD, tmp

    ldi tmp, 0x7F
    out DDRB, tmp

    ldi state, S0

MAIN_LOOP:
    in tmp, PIND
    andi tmp, 0x01
    mov data, tmp

    cpi state, S0
    breq STATE0
    cpi state, S1
    breq STATE1
    cpi state, S2
    breq STATE2
    rjmp MAIN_LOOP

STATE0:
    cpi data, 1
    brne SHOW0
    ldi state, S1
    rjmp SHOW1

STATE1:
    ldi state, S2
    rjmp SHOW1

STATE2:
    cpi data, 0
    brne SHOW0
    ldi state, S0
    rjmp SHOW0

SHOW0:
    ldi tmp, SEG_0
    out PORTB, tmp
    rjmp MAIN_LOOP

SHOW1:
    ldi tmp, SEG_1
    out PORTB, tmp
    rjmp MAIN_LOOP
