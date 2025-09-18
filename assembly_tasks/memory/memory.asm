.include "m328pdef.inc"

ldi r16, (1<<PD3)|(1<<PD4)
out PORTD, r16
ldi r16, 0x00
out DDRD, r16
ldi r16, 0x0F
out DDRB, r16

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

    sts 0x0100, r18       
    lds r20, 0x0100       

    in  r21, PORTB
    andi r21, 0xF0
    or  r21, r20
    out PORTB, r21

    rjmp loop
