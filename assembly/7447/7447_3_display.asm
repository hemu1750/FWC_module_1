.include "/sdcard/fwc_module_1/assembly/m328Pdef.inc"

        ldi r17, 0b11000011
        out DDRB,r17
        ldi r17, 0b11111111
        out PORTB,r17
        in r17,PINB

        ldi r16, 0b00111100 
        out DDRD,r16            
Start:
in r17,PINB
andi r17,0b00111100
out PORTD,r17
rjmp Start
