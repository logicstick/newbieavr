/*
 * GccApplication1.c
 *
 * Created: 19-03-2013 20:02:06
 *  Author: Vishwas
 */ 

/*
 * Glow a LED
 */

#include <avr/io.h>

int main(void)
{
	// TODO: Do some initialization here
	
	// TODO: Prepare PORTB pin 0 for output
	DDRB = 0b00000001;  // Set direction
	PORTB = 0b00000001; // Assigning 5v to pin 0
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
	// TODO: Create the following circuit
}