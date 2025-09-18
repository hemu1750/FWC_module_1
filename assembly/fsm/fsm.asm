.include "/sdcard/fwc_module_1/assembly/m328pdef.inc"

.equ A   = 0
.equ B   = 1
.equ C   = 2
.equ D   = 3
.equ CLK = 5

.equ W   = 0
.equ X   = 1
.equ Y   = 2
.equ Z   = 3

ldi r16, (1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<CLK)
out DDRB, r16

ldi r16, 0x00
out DDRD, r16

loop:
    in r17, PIND

    mov r18, r17
    andi r18, (1<<W)
    lsr r18

    mov r19, r17
    andi r19, (1<<X)
    lsr r19
    lsr r19

    mov r20, r17
    andi r20, (1<<Y)
    lsr r20
    lsr r20
    lsr r20

    mov r21, r17
    andi r21, (1<<Z)
    lsr r21
    lsr r21
    lsr r21
    lsr r21

    com r18
    andi r18, 0x01

    mov r22, r19
    com r22
    andi r22, 0x01

    mov r23, r21
    com r23
    andi r23, 0x01

    mov r24, r18
    com r24
    andi r24, 0x01

    mov r25, r24
    and r25, r22
    and r25, r23

    mov r26, r18
    and r26, r19

    or r25, r26
    mov r19, r25

    mov r22, r19
    com r22
    andi r22,0x01
    mov r23,r22
    and r23,r20

    mov r24,r18
    and r24,r20

    mov r25,r24
    and r25,r19
    com r20
    andi r20,0x01
    and r25,r20

    or r23,r24
    or r23,r25
    mov r20,r23

    mov r22,r18
    and r22,r21

    mov r23,r24
    and r23,r19
    and r23,r20

    or r22,r23
    mov r21,r22

    clr r30

    or r30, r18

    lsl r19
    or r30, r19

    lsl r20
    lsl r20
    or r30, r20

    lsl r21
    lsl r21
    lsl r21
    or r30, r21

    in r31, PORTB
    andi r31, 0b11110000
    or r31, r30
    out PORTB, r31

    sbi PORTB, CLK
    rcall delay_500ms
    cbi PORTB, CLK
    rcall delay_500ms

    rjmp loop

delay_500ms:
    ldi r18, 40
outer:
    ldi r19, 200
inner:
    ldi r20, 200
inner2:
    dec r20
    brne inner2
    dec r19
    brne inner
    dec r18
    brne outer
    ret
