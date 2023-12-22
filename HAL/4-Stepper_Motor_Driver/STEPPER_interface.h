/*
 * STEPPER_interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Waled Farouk
 */
#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define CW     0u
#define CCW    1u

typedef struct
{
	uint8 port;
	uint8 blue;
	uint8 pink;
	uint8 yellow;
	uint8 orange;
}stepper_t;

uint8 StepperRotate(const stepper_t * Copy_pStepperCfg , uint16 Angle , uint8 Direction);

#endif
