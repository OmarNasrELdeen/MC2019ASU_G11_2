#include "DIO.h"
#include "Mcal.h"
#include "types.h"

int Button_IsPressed(uint8 port_index,uint8 pins_mask,Button_Type type)
{
			if((type==PULL_UP)&&(DIO_ReadPort(port_index ,pins_mask))==0){
				return 1;
			}
			else if(type==PULL_DOWN&&(DIO_ReadPort(port_index ,pins_mask))==1){
			return 1;
			}
			
			return 0;
}