/*
 * TCNTLightBlinking.c
 *
 * Created: 20-03-2013 15:50:24
 *  Author: Vishwas
 */ 


#include <avr/io.h>

int main(void)
{
	// DONE: We have to initialize 7 LED on each side
	DDRB = 0b01111111;
	DDRD = 0b01111111;
	
	PORTB = 0b00000000;
	PORTD = 0b00000000;

	// DONE: Initialize the counter 16 bits i.e. TCNT1
	TCCR1B |= (1 << CS10) | (1 << CS11);  // Set pre-scaling of 64

	int LedNumber[2];
	
    while(1)
    {
        //DONE:: Blink the led at appropriate times
		if (TCNT1 > 2232)
		{
			// After it has counter to 10,000 make the counter zero
			TCNT1 = 0;
			PORTB ^= (1 << LedNumber[0]);
			LedNumber[0]++;
			if (LedNumber[0] > 6)
			{
				LedNumber[0] = 0;
				PORTD = 1 << LedNumber[1];
				LedNumber[1]++;
				if (LedNumber[1] > 6)
				{
					LedNumber[1] = 0;
				}
			}
		}
    }
}