/*
 * ADC_reg.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Waled Farouk
 */
#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX				*((volatile uint8*)0x27) 	/*@brief ADC multiplexer selection register ADMUX*/
#define ADMUX_REFS0			6							/*@brief Voltage Reference Selection Bit*/
#define ADMUX_REFS1			7							/*@brief Voltage Reference Selection Bit*/
#define ADMUX_ADLAR			5							/*@brief ADC Left Adjust Result 0 -> ADCL 0:7 or 1 -> ADCH 2:9*/
#define ADMUX_MUX0			0							/*@brief Analog Channel and Gain Selection Bit*/
#define ADMUX_MUX1			1							/*@brief Analog Channel and Gain Selection Bit*/
#define ADMUX_MUX2			2							/*@brief Analog Channel and Gain Selection Bit*/
#define ADMUX_MAX3			3							/*@brief Analog Channel and Gain Selection Bit*/
#define ADMUX_MAX4			4							/*@brief Analog Channel and Gain Selection Bit*/

#define ADCSRA 				*((volatile uint8*)0x26)	/*@brief ADC Control and Status Register A – ADCSRA*/
#define ADCSRA_ADEN			7							/*@brief ADC Enable*/
#define ADCSRA_ADSC			6							/*@brief ADC Start Conversion*/
#define ADCSRA_ADATE		5							/*@brief ADC Auto Trigger Enable*/
#define ADCSRA_ADIF			4							/*@brief ADC Interrupt Flag*/
#define ADCSRA_ADIE			3							/*@brief ADC Interrupt Enable*/
#define ADCSRA_ADPS2		2							/*@brief ADC Prescaler Select Bit*/
#define ADCSRA_ADPS1		1							/*@brief ADC Prescaler Select Bit*/
#define ADCSRA_ADPS0		0							/*@brief ADC Prescaler Select Bit*/

#define ADCH				*((volatile uint8*)0x25)	/*@brief ADC Data Register High Byte*/
#define ADCL				*((volatile uint8*)0x24)	/*@brief ADC Data Register Low Byte*/
#define ADC					*((volatile uint16*)0x24)	/*@brief ADC Data Register*/
#endif
