/*
 * ADC_programm.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Waled Farouk
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "defines.h"

#include "ADC_private.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"
#include "ADC_interface.h"

void ADC_voidInit(void)
{
#if ADC_u8REF_VOLT == AREF_REF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8REF_VOLT == AVCC_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_u8REF_VOLT == INTERNAL_2560mV_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
	#error Wrong ADC_u8REF_VOLT configuration option
#endif

#if	ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8RESOLUTION == TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);

#else
	#error Wrong ADC_u8RESOLUTION configuration option
#endif

#if	ADC_u8INT_ENABLE == DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#elif	ADC_u8INT_ENABLE == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#else
	#error Wrong ADC_u8INT_ENABLE configuration option
#endif

	/*configure the Prescaler*/
	ADCSRA &= PRECALER_MASK;
	ADCSRA |= ADC_u8INT_ENABLE;

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

uint16 ADC_u16GetChannelReading(uint8 Copy_u8Channel)
{
	/*configure the analog channel*/
	ADMUX &= CHANNEL_MASK;
	ADMUX |= Copy_u8Channel;

	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*wait until the conversion is complete */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#if ADC_u8RESOLUTION == EIGHT_BITS
	return ADCH;
#elif ADC_u8RESOLUTION == TEN_BITS
	return ADC;
#endif
}
