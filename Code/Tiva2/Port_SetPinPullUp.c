#include "types.h"
#include "tm4c123gh6pm.h"
#include "ports.h"
void Port_SetPinPullUp(uint8 port_index,uint8 pins_mask,uint8 enable)
{
	switch(port_index)
	{
		case PortA :
			if(enable==0){
				GPIO_PORTA_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTA_PUR_R |= pins_mask;
			}
			break;

		case PortB :
			if(enable==0){
				GPIO_PORTB_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTB_PUR_R |= pins_mask;
			}
			break;

		case PortC :
			if(enable==0){
				GPIO_PORTC_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTC_PUR_R |= pins_mask;
			}
			break;

		case PortD :
			if(enable==0){
				GPIO_PORTD_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTD_PUR_R |= pins_mask;
			}
			break;

		case PortE :
			if(enable==0){
				GPIO_PORTE_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTE_PUR_R |= pins_mask;
			}
			break;

		case PortF :
			if(enable==0){
				GPIO_PORTF_PUR_R &= (~(pins_mask));

			}
			else if(enable==1){
			GPIO_PORTF_PUR_R |= pins_mask;
			}
			break;
	}

}

