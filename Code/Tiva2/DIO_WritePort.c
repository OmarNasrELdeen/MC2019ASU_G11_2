#include "Mcal.h"

void DIO_WritePort(uint8 port_index,uint8 pins_mask,uint8 pins_level)
{
	switch(port_index){
		
		case PortA:
			if(pins_level==STD_LOW){
				GPIO_PORTA_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTA_DATA_R|=pins_mask;
			}
			break;
		case PortB:
			if(pins_level==STD_LOW){
				GPIO_PORTB_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTB_DATA_R|=pins_mask;
			}	
						break;

		case PortC:
			if(pins_level==STD_LOW){
				GPIO_PORTC_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTC_DATA_R|=pins_mask;
			}	
						break;

		case PortD:
			if(pins_level==STD_LOW){
				GPIO_PORTD_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTD_DATA_R|=pins_mask;
			}
						break;

		case PortE:
			if(pins_level==STD_LOW){
				GPIO_PORTE_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTE_DATA_R|=pins_mask;
			}	
						break;

		case PortF:
			if(pins_level==STD_LOW){
				GPIO_PORTF_DATA_R&=(~pins_mask);
			}
			else if(pins_level==STD_HIGH){	
			GPIO_PORTF_DATA_R|=pins_mask;
			}
			break;
			
	}
	
}