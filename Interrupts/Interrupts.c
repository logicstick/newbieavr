/*
 * Interrupts.c
 *
 * Created: 20-03-2013 16:53:48
 *  Author: Vishwas
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	sei(); // Enable Interrupt
	
	DDRB |= (1 << PINB0); // Set data direction to output
	
	//Setup clock
	TCCR1B |= (1 << CS10) | (1 << CS11) | (1 << WGM12);
	TIMSK |= 1 << OCIE1A; // This TIMSK will control all events related to timer/counter
	OCR1A = 15624;  // Set the compare register
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(TIMER1_COMPA_vect)
{
	//TODO: Interrupt Code
	PORTB ^= (1 << PINB0);
}	