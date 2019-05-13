#ifndef MCAL
#define MCAL

#include "types.h"
#include "tm4c123gh6pm.h"
#include "ports.h"
void Port_Init(uint8 port_index);
void Port_SetPinDirection(uint8 port_index,uint8 pins_mask,Port_PinDirectionType pins_direction) ;
void Port_SetPinPullUp(uint8 port_index,uint8 pins_mask,uint8 enable);
void Port_SetPinPullDown(uint8 port_index,uint8 pins_mask,uint8 enable);

#endif
