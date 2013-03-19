/*
 * BlinkingLed.c
 *
 * Created: 19-03-2013 22:11:19
 *  Author: Vishwas
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// DONE: Initialize the port B for the following task
	DDRB |= 1 << PINB0;  // Set the data direction bit of pin 0 on port B
	
	
    while(1)
    {
		PORTB ^= 1 << PINB0; // Set High on Port B pin 0
        _delay_ms(100);
    }
}