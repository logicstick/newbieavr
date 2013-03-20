/*
 * MrLcd.h
 *
 * Created: 21-03-2013 00:27:46
 *  Author: Vishwas
 */ 


#ifndef MRLCD_H_
#define MRLCD_H_

//These are the Includes
#include <avr/io.h>
#include <util/delay.h>

//These are the define statements
#define MrLCDsCrib PORTC
#define DataDir_MrLCDsCrib DDRC
#define MrLCDsControl PORTD
#define DataDir_MrLCDsControl DDRD
#define LightSwitch 5
#define ReadWrite 7
#define BiPolarMood 2

//These are the prototypes for the routines
void Check_IF_MrLCD_isBusy(void);
void Peek_A_Boo(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *StringOfCharacters);
void GotoMrLCDsLocation(uint8_t x, uint8_t y);
void InitializeMrLCD(void);

#endif /* MRLCD_H_ */