/*
 * TwoLedWithButton.c
 *
 * Created: 19-03-2013 22:25:42
 *  Author: Vishwas
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// DONE: Initialize Two port to be output and one port to be input on PORTB
	DDRB |= (1 << PINB0) | (1 << PINB1);	// Set pin 0 as output and pin 2
	
	DDRB &= ~(1 << PINB2);					// Make sure that you have set the pinb2 to input
	// When we press the button, this should register 0 volts
	PORTB |= (1 << PINB2); // Set initially this pin to high
	
	PORTB |= (1 << PINB0);
	PORTB &= ~(1 << PINB1);
	
    while(1)
    {
		if(bit_is_clear(PINB, PINB2)){
			// DONE: Set the LED on pin b1 to high
			PORTB |= (1 << PINB1);
			PORTB &= ~(1 << PINB0);
		} else {
			// DONE: Set the LED on pin b0 to high
			PORTB |= (1 << PINB0);
			PORTB &= ~(1 << PINB1);
		}
		// Add some delay after each operation
		_delay_ms(100);
    }
}