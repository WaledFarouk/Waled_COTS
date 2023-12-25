/*
 * EXIT_programm.c
 *
 *  Created on: Dec 24, 2023
 *      Author: Waled Farouk
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "EXTI_cfg.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"

static void (*EXTI_pfIntFuncPtr[3]) (void) = {NULL};	/*Array of pointer to functions to hold ISR callbacks*/

void EXTI_voidInitInt0(void)
{
	/*implement INT0 sense control configuration*/
#if INT0_SENCE_CTRL == EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_u8ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_u8RISING_EDGE_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
#error Wrong INT0_SENCE_CTRL configuration option
#endif

	/*implement INT0 initial state configuration*/
#if INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#else
#error Wrong INT0_INITIAL_STATE configuration option
#endif
}
void EXTI_voidInitInt1(void)
{
	/*implement INT1 sense control configuration*/
#if INT1_SENCE_CTRL == EXTI_u8LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENCE_CTRL == EXTI_u8ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENCE_CTRL == EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENCE_CTRL == EXTI_u8RISING_EDGE_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
#error Wrong INT1_SENCE_CTRL configuration option
#endif

	/*implement INT1 initial state configuration*/
#if INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#elif INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#else
#error Wrong INT1_INITIAL_STATE configuration option
#endif
}
void EXTI_voidInitInt2(void)
{
	/*implement INT2 sense control configuration*/
#if INT2_SENCE_CTRL == EXTI_u8FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENCE_CTRL == EXTI_u8RISING_EDGE_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
#error Wrong INT2_SENCE_CTRL configuration option
#endif

	/*implement INT2 initial state configuration*/
#if INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#elif INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#else
#error Wrong INT2_INITIAL_STATE configuration option
#endif
}

uint8 EXTI_u8SetSenseControl(uint8 Copy_u8IntNum,uint8 Copy_u8SenseControl)
{
	uint8 Local_u8ErrorState = OK;
	/*configure Sense Control trigger on INT0/INT1 */
	switch(Copy_u8IntNum)
	{
	case EXTI_u8INT0:
		switch(Copy_u8SenseControl)
		{
		case EXTI_u8LOW_LEVEL:	   CLR_BIT(MCUCR,MCUCR_ISC00);	CLR_BIT(MCUCR,MCUCR_ISC01);	break;
		case EXTI_u8ON_CHANGE:	   SET_BIT(MCUCR,MCUCR_ISC00);	CLR_BIT(MCUCR,MCUCR_ISC01);	break;
		case EXTI_u8FALLING_EDGE:  CLR_BIT(MCUCR,MCUCR_ISC00);	SET_BIT(MCUCR,MCUCR_ISC01);	break;
		case EXTI_u8RISING_EDGE:   SET_BIT(MCUCR,MCUCR_ISC00);	SET_BIT(MCUCR,MCUCR_ISC01);	break;
		default:Local_u8ErrorState = NOK;	break;
		}
		break;
	case EXTI_u8INT1:
		switch(Copy_u8SenseControl)
		{
		case EXTI_u8LOW_LEVEL:	   CLR_BIT(MCUCR,MCUCR_ISC10);	CLR_BIT(MCUCR,MCUCR_ISC11);	break;
		case EXTI_u8ON_CHANGE:	   SET_BIT(MCUCR,MCUCR_ISC10);	CLR_BIT(MCUCR,MCUCR_ISC11);	break;
		case EXTI_u8FALLING_EDGE:  CLR_BIT(MCUCR,MCUCR_ISC10);	SET_BIT(MCUCR,MCUCR_ISC11);	break;
		case EXTI_u8RISING_EDGE:   SET_BIT(MCUCR,MCUCR_ISC10);	SET_BIT(MCUCR,MCUCR_ISC11);	break;
		default:Local_u8ErrorState = NOK;	break;
		}
		break;
	case EXTI_u8INT2:
		switch(Copy_u8SenseControl)
		{
		case EXTI_u8FALLING_EDGE:  CLR_BIT(MCUCSR,MCUCSR_ISC2);	break;
		case EXTI_u8RISING_EDGE:   SET_BIT(MCUCSR,MCUCSR_ISC2);	break;
		default:Local_u8ErrorState = NOK;	break;
		}
		break;
	}
	return Local_u8ErrorState;
}
uint8 EXTI_u8InterruptEnable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;

	/*Enable INT0/INT1/INT2 Interrupt*/
	switch(Copy_u8IntNum)
	{
	case EXTI_u8INT0:	SET_BIT(GICR,GICR_INT0);	break;
	case EXTI_u8INT1:	SET_BIT(GICR,GICR_INT1);	break;
	case EXTI_u8INT2:	SET_BIT(GICR,GICR_INT2);	break;
	default:Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}
uint8 EXTI_u8InterruptDisable(uint8 Copy_u8IntNum)
{
	uint8 Local_u8ErrorState = OK;

	/*Enable INT0/INT1/INT2 Interrupt*/
	switch(Copy_u8IntNum)
	{
	case EXTI_u8INT0:	CLR_BIT(GICR,GICR_INT0);	break;
	case EXTI_u8INT1:	CLR_BIT(GICR,GICR_INT1);	break;
	case EXTI_u8INT2:	CLR_BIT(GICR,GICR_INT2);	break;
	default:Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}

uint8 EXTI_u8SetCallBack(uint8 Copy_u8IntNum, void (*Copy_pfFunPtr)(void))
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pfFunPtr != NULL)
	{
		EXTI_pfIntFuncPtr[Copy_u8IntNum] = Copy_pfFunPtr;
	}
	else
	{
		return Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
/**
 * @brief INT0 ISR
 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pfIntFuncPtr[EXTI_u8INT0] != NULL)
	{
		EXTI_pfIntFuncPtr[EXTI_u8INT0]();
	}
}
/**
 * @brief INT1 ISR
 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pfIntFuncPtr[EXTI_u8INT1] != NULL)
	{
		EXTI_pfIntFuncPtr[EXTI_u8INT1]();
	}
}
/**
 * @brief INT2 ISR
 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pfIntFuncPtr[EXTI_u8INT2] != NULL)
	{
		EXTI_pfIntFuncPtr[EXTI_u8INT2]();
	}
}
