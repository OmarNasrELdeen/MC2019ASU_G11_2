#include "types.h"
#include "ports.h"
#include "DIO.h"
#include "delay.h"


void LCD_Data(char data)
{
		DIO_WritePort(PortE,mask2,STD_HIGH); //RS=1
		DIO_WritePort(PortE,mask4,STD_LOW);//RW=0
		 GPIO_PORTB_DATA_R=data;//write command
			
		DIO_WritePort(PortE,mask5,STD_HIGH);//E=1
				delay_milli(2);

		DIO_WritePort(PortE,mask5,STD_LOW);//E=0
			delay_milli(2);

}