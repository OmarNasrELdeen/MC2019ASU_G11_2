
#include "Mcal.h"
/******type declation*****/
uint8 DIO_ReadPort(uint8 port_index,uint8 pins_mask)
{
	switch(port_index){
		case PortA:
		return (GPIO_PORTA_DATA_R&pins_mask)>0;
		case PortB:
		return (GPIO_PORTB_DATA_R&pins_mask)>0;
		case PortC:
		return (GPIO_PORTC_DATA_R&pins_mask)>0;
		case PortD:
		return (GPIO_PORTD_DATA_R&pins_mask)>0;
		case PortE:
		return (GPIO_PORTE_DATA_R&pins_mask)>0;
		case PortF:
		return (GPIO_PORTF_DATA_R&pins_mask)>0;
		default:return -1;
		}
}