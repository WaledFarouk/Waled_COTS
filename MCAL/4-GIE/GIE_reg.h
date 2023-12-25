/*
 * GIE_reg.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Waled Farouk
 */
#ifndef GIE_REG_H_
#define GIE_REG_H_

#define SREG		*((volatile uint8*)0x5F)	/*Status register*/
#define SREG_I		7u							/*Interrupt bit*/
#endif


