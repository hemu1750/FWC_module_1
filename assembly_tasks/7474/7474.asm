.include "m328pdef.inc"

ldi r16, (1<<PD2)
out PORTD, r16
ldi r16, 0x00
out DDRD, r16
ldi r16, 0x0F
out DDRB, r16
ldi r17, 0x00


loop:
    in  r18, PIND
    lsr r18
    andi r18, 0x01

    com r17
    andi r17, 0x01

    mov r19, r17
    and r19, r18
    in  r20, PORTB
    andi r20, 0xF0

    or  r20, r19
    out PORTB, r20
    mov r17, r18
    
    rjmp loop
