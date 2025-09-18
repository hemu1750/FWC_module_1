.include "/sdcard/fwc_module_1/assembly/m328Pdef.inc"

ldi r16, 0b00111100 
out DDRD,r16		
ldi r16,0b00000011	
rcall comp	
ldi r20, 0b00000000	
rcall loopw		 
out PORTD,r16		 

Start:
rjmp Start

loopw:	lsl r16			 
	dec r20			 
	brne	loopw	 
	ret
comp:
	mov r0,r16			 
	ldi r16,0b00000001	 
	eor r16,r0			 
	ret 				 

