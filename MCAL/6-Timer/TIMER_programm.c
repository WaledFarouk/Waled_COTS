/*
 * TIMER_programm.c
 *
 *  Created on: Jan 7, 2023
 *      Author: Waled Farouk
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "TIMER_private.h"
#include "TIMER_cfg.h"
#include "TIMER_reg.h"
#include "TIMER_interface.h"

static  void (*TIMERS_pvCallBackFuncArr[8])(void) = {NULL};

void TIMER0_voidInit(void)
{
	/*Set Compare Mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*  Compare Output Mode Normal port operation, OC0 disconnected.*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);

	/*Clock Select 64 (From prescaler)*/
	TCCR0 &= PRECALER_MASK;
	TCCR0 |= DIVISION_BY_64;

	/*Timer/Counter0 Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set Output Compare Flag 0*/
	SET_BIT(TIFR,TIFR_OCF0);

	/*Set Every 1msec generate interrupt*/
	OCR0 = 250;
}

uint8 TIMERS_u8SetCallBack(TIMERS_Int_Src_t Copy_u8TmrIntSource, void(*Copy_pvCallBackFunc)(void))
{
	uint8 Local_ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFuncArr[Copy_u8TmrIntSource] = Copy_pvCallBackFunc;
	}
	else
	{
		Local_ErrorState = NULL_PTR_ERR;
	}
	return Local_ErrorState;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
	}
}
