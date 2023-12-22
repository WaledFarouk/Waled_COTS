/*
 * SSD_program.c
 *
 *  Created on: Nov 25, 2023
 *      Author: The Engineer
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_reg.h"

#include "SSD_interface.h"
#include "SSD_prv.h"

/**
 * @brief This Function is used to set number on seven segment
 * @param Type This parameter is used to determine types for seven segment
 * @param Port  This parameter is used to choose the required port among DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD
 * @param LEDAPin This parameter is used to determine the start of connection of seven segment SSD_StartPin0 or SSD_StartPin1
 * @param number The number you want to appear on Seven Segment
 */
void SSD_SetNumber(uint8 Type, uint8 Port, uint8 LEDAPin, uint8 number)
{
	uint8 seg[]={	0b0111111, // 0
					0b0000110, // 1
					0b1011011, // 2
					0b1001111, // 3
					0b1100110, // 4
					0b1101101, // 5
					0b1111101, // 6
					0b0000111, // 7
					0b1111111, // 8
					0b1101111};// 9
	if(LEDAPin==SSD_StartPin0)
	{
		if(Type == Anode)
		{
			switch (Port)
			{
			/*0x80=ob10000000  || 0x7F=0b01111111
			PORTD = (PORTD & 0x80) | (segmentPatterns[digit] & 0x7F); updates only pins 0 to 6 of Port D based on the segment pattern,
			while keeping the state of pin 7 unchanged.*/
			case DIO_u8PORTA: PORTA = (PORTA & 0x80) | (~(seg[number]) & 0x7F);break;
			case DIO_u8PORTB: PORTB = (PORTB & 0x80) | (~(seg[number]) & 0x7F);break;
			case DIO_u8PORTC: PORTC = (PORTC & 0x80) | (~(seg[number]) & 0x7F);break;
			case DIO_u8PORTD: PORTD = (PORTD & 0x80) | (~(seg[number]) & 0x7F);break;
			}
		}
		else if(Type == Cathode)
		{
			switch (Port)
			{
			/*PORTD = (PORTD & 0x80) | (segmentPatterns[digit] & 0x7F); updates only pins 0 to 6 of Port D based on the segment pattern,
			  while keeping the state of pin 7 unchanged.*/
			case DIO_u8PORTA: PORTA = (PORTA & 0x80) | (seg[number] & 0x7F);break;
			case DIO_u8PORTB: PORTB = (PORTB & 0x80) | (seg[number] & 0x7F);break;
			case DIO_u8PORTC: PORTC = (PORTC & 0x80) | (seg[number] & 0x7F);break;
			case DIO_u8PORTD: PORTD = (PORTD & 0x80) | (seg[number] & 0x7F);break;
			}
		}
	}
	else if(LEDAPin==SSD_StartPin1)
	{
		if(Type == Anode)
		{
			switch (Port)
			{
			/*0x80=ob10000000  || 0x7F=0b01111111
			PORTD = (PORTD & 0x80) | (segmentPatterns[digit] & 0x7F); updates only pins 0 to 6 of Port D based on the segment pattern,
			while keeping the state of pin 7 unchanged.*/
			case DIO_u8PORTA: PORTA = (PORTA & 0b00000001) | ((~(seg[number])<<1)& 0b11111110);break;
			case DIO_u8PORTB: PORTB = (PORTB & 0b00000001) | ((~(seg[number])<<1)& 0b11111110);break;
			case DIO_u8PORTC: PORTC = (PORTC & 0b00000001) | ((~(seg[number])<<1)& 0b11111110);break;
			case DIO_u8PORTD: PORTD = (PORTD & 0b00000001) | ((~(seg[number])<<1)& 0b11111110);break;
			}
		}
		else if(Type == Cathode)
		{
			switch (Port)
			{
			/*PORTD = (PORTD & 0x80) | (segmentPatterns[digit] & 0x7F); updates only pins 0 to 6 of Port D based on the segment pattern,
			  while keeping the state of pin 7 unchanged.*/
			case DIO_u8PORTA: PORTA = (PORTA & 0b00000001) | ((seg[number]<<1) & 0b11111110);break;
			case DIO_u8PORTB: PORTB = (PORTB & 0b00000001) | ((seg[number]<<1) & 0b11111110);break;
			case DIO_u8PORTC: PORTC = (PORTC & 0b00000001) | ((seg[number]<<1) & 0b11111110);break;
			case DIO_u8PORTD: PORTD = (PORTD & 0b00000001) | ((seg[number]<<1) & 0b11111110);break;
			}
		}
	}
}
/**
 * @brief This Function is used to on seven segment
 * @param Type This parameter is used to determine types for seven segment
 * @param Port This parameter is used to choose the required port among DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD
 * @param Pin This parameter is used to choose the required pin from PIN0 to PIN7 to connect com in seven segment
 */
void SSD_On(uint8 Type, uint8 Port, uint8 Pin)
{
	if(Type == Anode)
	{
		switch (Port)
		{
		case DIO_u8PORTA: SET_BIT(PORTA,Pin);break;
		case DIO_u8PORTB: SET_BIT(PORTB,Pin);break;
		case DIO_u8PORTC: SET_BIT(PORTC,Pin);break;
		case DIO_u8PORTD: SET_BIT(PORTD,Pin);break;
		}

	}
	else if(Type == Cathode)
	{
		switch (Port)
		{
		case DIO_u8PORTA: PORTA = CLR_BIT(PORTA,Pin);break;
		case DIO_u8PORTB: PORTB = CLR_BIT(PORTB,Pin);break;
		case DIO_u8PORTC: PORTC = CLR_BIT(PORTC,Pin);break;
		case DIO_u8PORTD: PORTD = CLR_BIT(PORTD,Pin);break;
		}
	}

}
/**
 * @brief This Function is used to off seven segment
 * @param Type This parameter is used to determine types for seven segment
 * @param Port This parameter is used to choose the required port among DIO_u8PORTA,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PORTD
 * @param Pin This parameter is used to choose the required pin from PIN0 to PIN7 to connect com in seven segment
 */
void SSD_Off(uint8 Type, uint8 Port, uint8 Pin)
{
	if(Type == Cathode)
	{
		switch (Port)
		{
		case DIO_u8PORTA: SET_BIT(PORTA,Pin);break;
		case DIO_u8PORTB: SET_BIT(PORTB,Pin);break;
		case DIO_u8PORTC: SET_BIT(PORTC,Pin);break;
		case DIO_u8PORTD: SET_BIT(PORTD,Pin);break;
		}

	}
	else if(Type == Anode)
	{
		switch (Port)
		{
		case DIO_u8PORTA: PORTA = CLR_BIT(PORTA,Pin);break;
		case DIO_u8PORTB: PORTB = CLR_BIT(PORTB,Pin);break;
		case DIO_u8PORTC: PORTC = CLR_BIT(PORTC,Pin);break;
		case DIO_u8PORTD: PORTD = CLR_BIT(PORTD,Pin);break;
		}
	}

}

