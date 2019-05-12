#include "DIO.h"
#include "Mcal.h"
#include "types.h"

void Button_Init(uint8 port_index,uint8 pins_mask,Button_Type type){

		 Port_Init(port_index);
		 Port_SetPinDirection( port_index,  pins_mask,PORT_PIN_IN) ;
			if(type==PULL_UP){
				Port_SetPinPullUp( port_index,  pins_mask, 1);
				Port_SetPinPullDown( port_index,  pins_mask, 0);
			}
			else if(type==PULL_DOWN){
			Port_SetPinPullUp( port_index,  pins_mask, 0);
				Port_SetPinPullDown( port_index,  pins_mask, 1);
			}
}


