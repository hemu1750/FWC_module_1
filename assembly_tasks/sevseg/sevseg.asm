.include "m328pdef.inc"

ldi r16, (1<<PD3)|(1<<PD4)
out PORTD, r16
ldi r16, 0x00
out DDRD, r16
ldi r16, 0x7F
out DDRC, r16

loop:
    in  r17, PIND
    mov r18, r17
    lsr r18
    lsr r18
    lsr r18
    andi r18, 0x01        

    mov r19, r17
    lsr r19
    lsr r19
    lsr r19
    lsr r19
    andi r19, 0x01        

    com r19
    andi r19, 0x01

    and r18, r19          

    cpi r18, 0x01
    breq show_one

show_zero:
    ldi r20, 0x3F         
    out PORTC, r20
    rjmp loop

show_one:
    ldi r20, 0x06         
    out PORTC, r20
    rjmp loop
