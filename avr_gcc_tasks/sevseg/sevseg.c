
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define SEG_0 0b00111111  
#define SEG_1 0b00000110  

typedef enum { S0 = 0, S1 = 1, S2 = 2 } state_t;

int main(void)
{
    DDRD &= ~(1 << PD2);
    DDRB |= 0x7F;   

    state_t state = S0;

    for (;;)
    {
        uint8_t data = (PIND & (1 << PD2)) ? 1 : 0;

        switch (state)
        {
            case S0: 
                if (data) {
                    state = S1;
                    PORTB = SEG_1;   
                } else {
                    PORTB = SEG_0;   
                }
                break;

            case S1: 
                state = S2;
                PORTB = SEG_0;       
                break;

            case S2: 
                if (!data)
                    state = S0;
                PORTB = SEG_0;
                break;

            default:
                state = S0;
                PORTB = SEG_0;
                break;
        }
    }

    return 0;
}
