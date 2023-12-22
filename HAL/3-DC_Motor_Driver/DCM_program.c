/*
 * DCM_program.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Waled Farouk
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DCM_interface.h"

/**
 * @brief This Function is used to drive the DC motor to rotate clockwise
 * @param Copy_pDCMcfg This parameter is struct carry the DC motor configuration
 * @return Error state
 */
uint8 DCM_u8CW(const DCM_cfg * Copy_pDCMcfg)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pDCMcfg != NULL)
	{
	  DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin2,DIO_u8PIN_LOW);
	  DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin1,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}
/**
 * @brief This Function is used to drive the DC motor to rotate counter-clockwise
 * @param Copy_pDCMcfg This parameter is struct carry the DC motor configuration
 * @return Error state
 */
uint8 DCM_u8CCW(const DCM_cfg * Copy_pDCMcfg)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pDCMcfg != NULL)
	{
		DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin2,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}
/**
 * @brief This Function is used to brake the DC motor
 * @param Copy_pDCMcfg This parameter is struct carry the DC motor configuration
 * @return Error state
 */
uint8 DCM_u8Brake(const DCM_cfg * Copy_pDCMcfg)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pDCMcfg != NULL)
	{
	  DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin1,DIO_u8PIN_HIGH);
	  DIO_u8SetPinValue(Copy_pDCMcfg->DCM_u8Port,Copy_pDCMcfg->DCM_u8Pin2,DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState ;
}
