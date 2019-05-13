#include "types.h"
#include "ports.h"
#include "DIO.h"
#include "delay.h"
#include "LCD.h"
void LCD_Init()
{
		Port_Init(PortE);
		Port_Init(PortB);
	
		Port_SetPinDirection(PortE,mask2,PORT_PIN_OUT);  //RS->E2 
		Port_SetPinDirection(PortE,mask5,PORT_PIN_OUT);  //E->E5
		Port_SetPinDirection(PortE,mask4,PORT_PIN_OUT);  //RW->E4

		Port_SetPinDirection(PortB,0xff,PORT_PIN_OUT);
	
	 delay_micro(80);
	
		LCD_Cmd(0x01);
		LCD_Cmd(0x38);
		LCD_Cmd(0x0F);
	  LCD_Cmd(0x06);
		LCD_Cmd(0x0C);
		/*LCD_Cmd(0x30);delay_milli(10);	LCD_Cmd(0x30);delay_milli(10);	LCD_Cmd(0x30);

		LCD_Cmd(0x80);*/
   

}
