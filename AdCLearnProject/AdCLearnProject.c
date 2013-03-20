/*
 * AdCLearnProject.c
 *
 * Created: 21-03-2013 00:58:30
 *  Author: Vishwas
 */ 


#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "MrLcd.h"

int main(void)
{
	InitializeMrLCD();
	
	//Configure the ADC
	ADCSRA |= 1<<ADIE;					//Enable interrupt function in ADC
	ADMUX |= 1 << ADLAR;				//8bit or 10bit results
	ADMUX |= 1<<REFS0;
	ADCSRA |= 1 << ADPS2;				// Enable a prescaler- determined by the internal/external clock
										// 1,000,0000/ 5KHz to 200kHz
	ADCSRA |= (1 << ADEN);				// Turn on the ADC features
	
	sei();								// Enable the global interrupts	
	ADCSRA |= 1<<ADSC;					// Start the first conversion

    while(1)
    {
        //TODO:: Please write your application code 
    }
}

//////////////////////////////////////////////////////////////////////////
// Add the interrupt routine //
//////////////////////////////////////////////////////////////////////////
//LCD String variable declaration
ISR(ADC_vect)
{
	char adcResult[4];
	itoa(ADCH, adcResult, 10);		// Convert a ADC
	GotoMrLCDsLocation(1,1);						// Select the location on the LCD to display the number
	Send_A_String(adcResult);						// STart the next conversion	
	ADCSRA |= 1<<ADSC;					// Start the first conversion
}

//////////////////////////////////////////////////////////////////////////