#include "types.h"
#include "tm4c123gh6pm.h"
#include "ports.h"

void Port_SetPinDirection(uint8 port_index,uint8 pins_mask,Port_PinDirectionType pins_direction)
{
	switch (port_index){

		case PortA:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTA_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTA_DIR_R |= pins_mask;
			}

			break;
			case PortB:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTB_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTB_DIR_R |= pins_mask;
			}

			break;
			case PortC:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTC_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTC_DIR_R |= pins_mask;
			}

			break;
			case PortD:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTD_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTD_DIR_R |= pins_mask;
			}

			break;
			case PortE:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTE_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTE_DIR_R |= pins_mask;
			}

			break;

			case PortF:
			if(pins_direction==PORT_PIN_IN){
				GPIO_PORTF_DIR_R &= (~(pins_mask));
			}

			else if(pins_direction==PORT_PIN_OUT){
				GPIO_PORTF_DIR_R |= pins_mask;
			}
			break;

			default:
				break;


	}

}
