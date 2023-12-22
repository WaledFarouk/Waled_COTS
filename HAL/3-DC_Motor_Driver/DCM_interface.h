/*
 * DCM_interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Waled Farouk
 */
#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

typedef struct{
	uint8 DCM_u8Port;
	uint8 DCM_u8Pin1;
	uint8 DCM_u8Pin2;
}DCM_cfg;


uint8 DCM_u8CW(const DCM_cfg * Copy_pDCMcfg);
uint8 DCM_u8CCW(const DCM_cfg * Copy_pDCMcfg);
uint8 DCM_u8Brake(const DCM_cfg * Copy_pDCMcfg);

#endif
