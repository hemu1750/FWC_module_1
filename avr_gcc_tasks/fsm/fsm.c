#include <avr/io.h>
#include <stdint.h>

typedef enum { S0 = 0, S1 = 1, S2 = 2 } state_t;

int main(void)
{
    DDRD &= ~(1 << PD2);
    DDRB |=  (1 << PB0);

    state_t state = S0;

    for (;;)
    {
        uint8_t data = (PIND & (1 << PD2)) ? 1 : 0;

        switch (state)
        {
            case S0:
                if (data)
                {
                    state = S1;
                    PORTB |= (1 << PB0);
                }
                else
                {
                    PORTB &= ~(1 << PB0);
                }
                break;

            case S1:
                state = S2;
                PORTB &= ~(1 << PB0);
                break;

            case S2:
                if (!data)
                {
                    state = S0;
                }
                PORTB &= ~(1 << PB0);
                break;

            default:
                state = S0;
                PORTB &= ~(1 << PB0);
                break;
        }
    }

    return 0;
}
