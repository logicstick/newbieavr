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
	// DONE: Do some initialization here
	
	// DONE: Prepare PORTB pin 0 for output
	DDRB = 0b00000001;  // Set direction
	PORTB = 0b00000001; // Assigning 5v to pin 0
	
    while(1)
    {
        //DONE:: Please write your application code 
    }
	// DONE: Create the following circuit
}