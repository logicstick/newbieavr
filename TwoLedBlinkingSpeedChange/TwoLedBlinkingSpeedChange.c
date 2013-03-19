/*
 * TwoLedBlinkingSpeedChange.c
 *
 * Created: 19-03-2013 22:48:23
 *  Author: Vishwas
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// TODO: Attach LED on pin0 and pin1 of port B
	DDRB |= (1 << PINB0) | (1 << PINB1);		// Set the direction on these pin as output
	DDRB &= ~(1 << PINB2);						// Set the direction on this pin as input
	
	PORTB |= (1 << PINB0);						// Set the default state of pinb0 to high
	PORTB &= ~(1 << PINB1);						// and the default state of pinb1 to low
	
	// TODO: Attach the button on Pin 2 of Port B
	PORTB |= (1 << PINB2);						// Set the default state of pin b2 to high
	
	uint8_t Pressed = 0;						// Declare the current state of the button 0 means that
												// it is not pressed
    while(1)
    {
        //TODO: When the button is pressed and release switch the LED which is turned on 
		if (bit_is_clear(PINB, PINB2))  // Check if the button is pressed
		{
			// check if already not pressed
			if (Pressed == 0)
			{
				// If pressed is 0 then blink the led connected to pin b0
				PORTB ^= (1 << PINB0);
				PORTB ^= (1 << PINB1);
				// if pressed and released then blinked the led connected to pin b1		
				Pressed = 1;
			}
		} 
		else
		{
			// When button is not pressed
			Pressed = 0;
		}
    }
}