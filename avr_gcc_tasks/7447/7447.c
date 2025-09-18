#include <avr/io.h>

int main(void) {
    DDRD &= ~((1<<PD2) | (1<<PD3) | (1<<PD4));
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1) | (1<<PB2) | (1<<PB3);

    while (1) {
        uint8_t A = (PIND & (1<<PD2)) ? 1 : 0;
        uint8_t B = (PIND & (1<<PD3)) ? 1 : 0;
        uint8_t C = (PIND & (1<<PD4)) ? 1 : 0;
        uint8_t F = C;
        if (F)
            PORTB |= (1<<PB0);
        else
            PORTB &= ~(1<<PB0);
        if (A) PORTB |= (1<<PB1); else PORTB &= ~(1<<PB1);
        if (B) PORTB |= (1<<PB2); else PORTB &= ~(1<<PB2);
        if (C) PORTB |= (1<<PB3); else PORTB &= ~(1<<PB3);
    }
}
