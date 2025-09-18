.include "/sdcard/fwc_module_1/assembly/m328Pdef.inc"

ldi r16, 0b11111100
out DDRD, r16

ldi r16, 0b00000001
out DDRB, r16

LoopDigits:
    ldi r17, 0b00000011
    out PORTD, r17
    ldi r16,0b00000001
    out PORTB,r16
    rcall Delay

    ldi r17, 0b11100111
    out PORTD, r17
    ldi r16,0b00000001
    out PORTB,r16
    rcall Delay

    ldi r17, 0b10010011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b11000011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b01100111
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b01001011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b00001011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b11100011
    out PORTD, r17
    ldi r16,0b00000001
    out PORTB,r16
    rcall Delay

    ldi r17, 0b00000011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    ldi r17, 0b01000011
    out PORTD, r17
    ldi r16,0b00000000
    out PORTB,r16
    rcall Delay

    rjmp LoopDigits

Delay:
    ldi r18, 0xFF
DelOuter:
    ldi r19, 0xFF
DelMiddle:
    ldi r20, 0xFF
DelInner:
    dec r20
    brne DelInner
    dec r19
    brne DelMiddle
    dec r18
    brne DelOuter
    ret
