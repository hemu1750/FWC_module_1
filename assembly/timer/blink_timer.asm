.include "/sdcard/fwc_module_1/assembly/m328Pdef.inc"

sbi DDRD, 7
ldi r16, 0b00000101
out TCCR0B, r16 

clr r18

ldi r20,0b10000000

loop:
    eor r18, r20
    out PORTD, r18 
    ldi r19, 0b01000000
    rcall PAUSE
    rjmp loop
	
PAUSE:
lp2:
    in r16, TIFR0
    ldi r17, 0b00000010
    and r16, r17
    breq PAUSE 
    out TIFR0, r17
    dec r19
    brne lp2
    ret
