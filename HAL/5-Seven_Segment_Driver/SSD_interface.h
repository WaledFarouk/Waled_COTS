/*
 * SSD_interface.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Waled Farouk
 */
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_PortA		0u
#define SSD_PortB		1u
#define SSD_PortC		2u
#define SSD_PortD		3u

void SSD_SetNumber(uint8 Type, uint8 Port, uint8 LEDAPin, uint8 number);
void SSD_On(uint8 Type, uint8 Port, uint8 Pin);
void SSD_Off(uint8 Type, uint8 Port, uint8 Pin);

#endif

