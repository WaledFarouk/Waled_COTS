/**************************************************************/
/**************************************************************/
/*********		Author: Waled Farouk		*******************/
/*********		File: KPD_program.c	    	*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_cfg.h"

/**
 * @brief This Function is used to determine which key pressed from 1 to 16 keys
 * @return Error state
 */
uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8PressedKey=KPd_u8NO_PRESSED_KEY_VAL;
	uint8 Local_u8RowCounter , Local_u8ColCounter , Local_u8KeyState;
	static uint8 Local_u8RowArr[KPD_u8ROW_NUM]= {DIO_u8PIN4 , DIO_u8PIN5 , DIO_u8PIN6 , DIO_u8PIN7};
	static uint8 Local_u8ColArr[KPD_u8COL_NUM]= {DIO_u8PIN2 , DIO_u8PIN3 , DIO_u8PIN4 , DIO_u8PIN5};
	static uint8 Local_u8KPDArr[KPD_u8ROW_NUM][KPD_u8COL_NUM]= KPD_u8BUTTON_ARR;

	/*Activate column pins and read the rows*/
	for(Local_u8ColCounter=0;Local_u8ColCounter<KPD_u8COL_NUM;Local_u8ColCounter++)
	{
		/*Activate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_Port,Local_u8ColArr[Local_u8ColCounter],DIO_u8PIN_LOW);

		for(Local_u8RowCounter=0;Local_u8RowCounter<KPD_u8ROW_NUM;Local_u8RowCounter++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KPD_u8ROW_Port,Local_u8RowArr[Local_u8RowCounter],&Local_u8KeyState);

			/*of current row is low, button is pressed*/
			if(Local_u8KeyState==DIO_u8PIN_LOW)
			{
				Local_u8PressedKey= Local_u8KPDArr[Local_u8RowCounter][Local_u8ColCounter];

				/*wait until key is released*/
				while(Local_u8KeyState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KPD_u8ROW_Port,Local_u8RowArr[Local_u8RowCounter],&Local_u8KeyState);
				}

				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_Port,Local_u8ColArr[Local_u8ColCounter],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
