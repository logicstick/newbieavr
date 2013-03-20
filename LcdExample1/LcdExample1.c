/*
 * LcdExample1.c
 *
 * Created: 20-03-2013 18:18:26
 *  Author: Vishwas
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define MrLCDsCrib				PORTC
#define DataDirectionCrib		DDRC
#define MrLCDsControl			PORTD
#define DataDirectionControl	DDRD

#define LightSwitch		PIND5
#define ReadWrite		PIND7
#define BiPolarMood		PIND2

void CheckIfMrLCDisBusy(void);
void PeekABoo(void);
void SendACommand(unsigned char command);
void SendACharacter(unsigned char character);

int main(void)
{
	DataDirectionControl |= (1 << LightSwitch) | (1 << ReadWrite) | (1 << BiPolarMood);
	_delay_ms(15);
	
	SendACommand(0x01);			// Clears the screen
	_delay_ms(2);
	SendACommand(0x38);			// We are going to use 8 data pins
	_delay_us(50);
	SendACommand(0b00001100);
	_delay_us(50);
	
	SendACharacter(0x41);		// Display the character A
	SendACharacter(0x41);		// Display the character A
	SendACharacter(0x41);		// Display the character A
	SendACharacter(0x41);		// Display the character A
	SendACharacter(0x41);		// Display the character A
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

void CheckIfMrLCDisBusy(void)
{
	DataDirectionCrib = 0;
	MrLCDsControl |= (1 << ReadWrite);
	MrLCDsControl &= ~(1 << BiPolarMood);
	
	while(MrLCDsCrib >= 0x80)    // Do something when not busy
	{
		PeekABoo();
	}
	
	DataDirectionCrib = 0xFF;	//0xff means all 0b11111111
}

void PeekABoo(void)
{
	MrLCDsControl |= (1 << LightSwitch);
	asm volatile ("nop");
	asm volatile ("nop");
	MrLCDsControl &= ~( 1 << LightSwitch);
}	

void SendACommand(unsigned char command)
{
	MrLCDsCrib = command;
	MrLCDsControl &= ~((1 << ReadWrite) | (1 << BiPolarMood)) ;
	PeekABoo();
	MrLCDsCrib = 0;
}

void SendACharacter(unsigned char character)
{
	MrLCDsCrib = character;
	MrLCDsControl &= ~(1 << ReadWrite) ;
	MrLCDsControl |= (1 << BiPolarMood);
	PeekABoo();
	MrLCDsCrib = 0;
}