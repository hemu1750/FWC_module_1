#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

#define ClearBit(x,y) ( (x) &= ~_BV(y) )
#define SetBit(x,y)   ( (x) |=  _BV(y) )

#define LCD_RS 0
#define LCD_E  1
#define DAT4   2
#define DAT5   3
#define DAT6   4
#define DAT7   5

#define CLEARDISPLAY 0x01

static void PulseEnableLine(void)
{
    SetBit(PORTB, LCD_E);
    _delay_us(2);
    ClearBit(PORTB, LCD_E);
    _delay_us(50);
}

static void SendNibble(byte data)
{
    PORTB &= ~((1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7));

    if (data & (1<<4)) SetBit(PORTB, DAT4);
    if (data & (1<<5)) SetBit(PORTB, DAT5);
    if (data & (1<<6)) SetBit(PORTB, DAT6);
    if (data & (1<<7)) SetBit(PORTB, DAT7);

    PulseEnableLine();
}

static void SendByte(byte data)
{
    SendNibble(data & 0xF0);
    SendNibble((data & 0x0F) << 4);
}

void LCD_Cmd(byte cmd)
{
    ClearBit(PORTB, LCD_RS);
    SendByte(cmd);
    _delay_ms(2);
}

void LCD_Char(byte ch)
{
    SetBit(PORTB, LCD_RS);
    SendByte(ch);
    _delay_ms(2);
}

void LCD_Init(void)
{
    PORTB &= ~((1<<LCD_RS)|(1<<LCD_E)|(1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7));

    _delay_ms(50);

    LCD_Cmd(0x33);
    LCD_Cmd(0x32);
    LCD_Cmd(0x28);
    LCD_Cmd(0x0C);
    LCD_Cmd(0x06);
    LCD_Cmd(CLEARDISPLAY);
    _delay_ms(3);
}

void LCD_Clear(void)
{
    LCD_Cmd(CLEARDISPLAY);
    _delay_ms(3);
}

void LCD_Message(const char *text)
{
    while (*text) {
        LCD_Char((byte)*text++);
    }
}

void LCD_Integer(int data)
{
    char st[8];
    itoa(data, st, 10);
    LCD_Message(st);
}

int main(void)
{
    DDRB |= (1<<LCD_RS)|(1<<LCD_E)|(1<<DAT4)|(1<<DAT5)|(1<<DAT6)|(1<<DAT7);

    LCD_Init();

    LCD_Clear();
    LCD_Char('8');

    while (1) {
        _delay_ms(1000);
    }

    return 0;
}
