#include <avr/io.h>

int main(void) {
    DDRD &= ~(1<<PD2);
    DDRB |= (1<<PB0);

    uint8_t Q1 = 0;
    uint8_t Q2 = 0;

    while (1) {
        uint8_t DATA = (PIND & (1<<PD2)) ? 1 : 0;
        Q2 = Q1;
        Q1 = DATA;
        uint8_t Y = (Q1 && !Q2);
        if (Y)
            PORTB |= (1<<PB0);  
            PORTB &= ~(1<<PB0);  
    }
}
