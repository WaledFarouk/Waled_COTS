/*
 * STEPPER_program.c
 *
 *  Created on: Dec 21, 2023
 *      Author: The Engineer
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "STEPPER_interface.h"

#include <util/delay.h>

uint8 StepperRotate(const stepper_t * Copy_pStepperCfg , uint16 Angle , uint8 Direction)
{
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16Counter;
	uint16 Local_u16Steps = (uint16)((uint32)Angle * 2048ul /360ul);

    if (Direction == CW)
	{
		for(Local_u16Counter=0;Local_u16Counter<Local_u16Steps;Local_u16Counter++)
		{
			if(Local_u16Counter % 4 == 0)
			{
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}
			else if(Local_u16Counter % 4 == 1)
			{
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}
			else if(Local_u16Counter % 4 == 2)
			{
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
				_delay_ms(2);
			}
			else if(Local_u16Counter % 4 == 3)
			{
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_LOW);
				_delay_ms(2);
			}
		}
	}
	else if(Direction == CCW)
		{
			for(Local_u16Counter=0;Local_u16Counter<Local_u16Steps;Local_u16Counter++)
			{
				if(Local_u16Counter % 4 == 0)
				{
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_LOW);
					_delay_ms(2);
				}
				else if(Local_u16Counter % 4 == 1)
				{
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u16Counter % 4 == 2)
				{
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u16Counter % 4 == 3)
				{
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->blue,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->pink,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->yellow,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pStepperCfg->port,Copy_pStepperCfg->orange,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	return Local_u8ErrorState;
}
