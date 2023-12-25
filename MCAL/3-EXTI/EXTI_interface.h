/*
 * EXIT_interface.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Waled Farouk
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0					1u
#define EXTI_u8INT1					2u
#define EXTI_u8INT2					3u

#define EXTI_u8RISING_EDGE 			4u
#define EXTI_u8FALLING_EDGE 		5u
#define EXTI_u8LOW_LEVEL 			6u
#define	EXTI_u8ON_CHANGE 			7u

void EXTI_voidInitInt0(void);
void EXTI_voidInitInt1(void);
void EXTI_voidInitInt2(void);

uint8 EXTI_u8SetSenseControl(uint8 Copy_u8IntNum,uint8 Copy_u8SenceControl);
uint8 EXTI_u8InterruptEnable(uint8 Copy_u8IntNum);
uint8 EXTI_u8InterruptDisable(uint8 Copy_u8IntNum);


#endif

