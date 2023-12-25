/*
 * GIE_programm.c
 *
 *  Created on: Dec 24, 2023
 *      Author: Waled Farouk
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_reg.h"
#include "GIE_interface.h"

void GIE_voidEnableGlobal(void)
{
	//SET_BIT(SREG,SREG_I);
	__asm __volatile("SEI");	/*Inline assembly instruction to set I bit*/
}
void GIE_voidDisableGlobal(void)
{
	//CLR_BIT(SREG,SREG_I);
	__asm __volatile("CLI");	/*Inline assembly instruction to clear I bit*/
}

