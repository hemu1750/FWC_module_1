#include <avr/io.h>
#include <stdint.h>

int main(void)
{
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4));
    DDRB |= (1 << PB0);

    while (1)
    {
        uint8_t C = (PIND & (1 << PD4)) ? 1 : 0;

        if (C)
            PORTB |= (1 << PB0);  
        else
            PORTB &= ~(1 << PB0);
    }

    return 0;
}
