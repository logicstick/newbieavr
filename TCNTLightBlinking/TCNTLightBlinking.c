/*
 * TCNTLightBlinking.c
 *
 * Created: 20-03-2013 15:50:24
 *  Author: Vishwas
 */ 


#include <avr/io.h>

int main(void)
{
	// TODO: We have to initialize 7 LED on each side
	DDRB = 0b00000001;
	PORTB = 0b00000000;
	// TODO: Initialize the counter 16 bits i.e. TCNT1
	TCCR1B |= (1 << CS10);  // Set pre-scaling of 1
	
    while(1)
    {
        //TODO:: Blink the led at appropriate times
		if (TCNT1 > 10000)
		{
			// After it has counter to 10,000 make the counter zero
			TCNT1 = 0;
			PORTB ^= (1 << PINB0);
		}
    }
}