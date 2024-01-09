/*
 * TIMER_interface.h
 *
 *  Created on: Jan 7, 2023
 *      Author: Waled Farouk
 */
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef enum
{
	TIMER0_OVF=0,
	TIMER0_COMP
}TIMERS_Int_Src_t;

void TIMER0_voidInit(void);
uint8 TIMERS_u8SetCallBack(TIMERS_Int_Src_t Copy_u8TmrIntSource, void(*Copy_pvCallBackFunc)(void));

#endif


