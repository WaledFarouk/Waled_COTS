/*
 * TIMER_reg.h
 *
 *  Created on: Jan 7, 2023
 *      Author: Waled Farouk
 */
#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define TCCR0					*((volatile uint8*)0x53) 	/*@brief Timer/Counter0 Control Register - TCCR0*/
#define TCCR0_FOC0				7							/*@brief Bit 7 – FOC0: Force Output Compare*/
#define TCCR0_WGM00				6							/*@brief Bit 6 – WGM00: Waveform Generation Mode*/
#define TCCR0_WGM01				3							/*@brief Bit 3 – WGM01: Waveform Generation Mode*/
#define TCCR0_COM00				4							/*@brief Bit 4 – COM00: Compare Match Output Mode*/
#define TCCR0_COM01				5							/*@brief Bit 5 – COM01: Compare Match Output Mode*/
#define TCCR0_CS00				0							/*@brief Bit 0 – CS00: Clock Select*/
#define TCCR0_CS01				1							/*@brief Bit 1 – CS01: Clock Select*/
#define TCCR0_CS02				2							/*@brief Bit 2 – CS02: Clock Select*/

#define TCNT0 					*((volatile uint8*)0x52)	/*@brief Timer/Counter Register – TCNT0*/

#define OCR0 					*((volatile uint8*)0x5C)	/*@brief Output Compare Register – OCR0*/

#define TIMSK 					*((volatile uint8*)0x59)	/*@brief Timer/Counter Interrupt Mask Register – TIMSK*/
#define TIMSK_OCIE0				1							/*@brief Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0				0							/*@brief Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable*/

#define TIFR 					*((volatile uint8*)0x58)	/*@brief Timer/Counter Interrupt Flag Register – TIFR*/
#define TIFR_OCF0				1							/*@brief Bit 1 – OCF0: Output Compare Flag 0*/
#define TIFR_TOV0				0							/*@brief Bit 0 – TOV0: Timer/Counter0 Overflow Flag*/

#endif
