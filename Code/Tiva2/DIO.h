#ifndef DIO
#define DIO


#include "types.h"
#include "tm4c123gh6pm.h"
#include "ports.h"
#include "Mcal.h"
uint8 DIO_WritePort(uint8 port_index,uint8 pins_mask,uint8 pins_level);
uint8 DIO_ReadPort(uint8 port_index,uint8 pins_mask);
void DIO_FlipPort (uint8 port_index ,uint8 pins_mask);
void DIO_FillPortData(uint8 port_index,uint8 data);
uint8 DIO_GetPortData(uint8 port_index);
#endif