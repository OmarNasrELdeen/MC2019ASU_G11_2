#ifndef DIO_H
#define DIO_H

#include "types.h"

uint8 DIO_ReadPort(uint8 port_index,uint8 pins_mask);

void DIO_WritePort(uint8 port_index,uint8 pins_mask,uint8 pins_level);


#endif