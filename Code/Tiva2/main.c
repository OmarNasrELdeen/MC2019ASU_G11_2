#include "tm4c123gh6pm.h"
#include "ADC.h"
#include "PLL.h"
#include "UART.h"
#include <stdint.h>
#include "ports.h"
#include <stdio.h> 
#include "Mcal.h"
#include "Button.h"
#include "LCD.h"
#include "cstring"
#include "delay.h"
uint16_t AIN0_DValue;
float	AIN0_AValue;



void LCD_Print(uint32_t out);
void SystemInit(void){
	PLL_Init();
	LCD_Init();
	UART0_Init();
	UART7_Init();
	ADC0_Init();
//
	Button_Init( PortF, mask0 ,PULL_UP);
	Button_Init( PortF, mask4 ,PULL_UP);

}






int main(void){
	int result=0,i,j,si,prevTemp=100,nowPot,prevPot;
	char s;
	char TempValue[6];
	char PotValue[6];
	LCD_Data(' ');
	while(1){
		
		
					if(Button_IsPressed(PortF, mask0 ,PULL_UP) && !Button_IsPressed(PortF, mask4 ,PULL_UP) ) // SW2-PF0 elli 3la elymeen
					{
						UART0_Write('r');
						UART7_Write('r');
						delay_milli(5);
						UART7_Write('\0');
						delay_milli(5);
						UART0_Write('\n');
						UART0_Write('\r');
						while(Button_IsPressed(PortF, mask0 ,PULL_UP)); // Send on bress only
					}
					
					else if (!Button_IsPressed(PortF, mask0 ,PULL_UP) && Button_IsPressed(PortF, mask4 ,PULL_UP) ) // SW1-PF4 elli 3la elshmal
					{
						UART0_Write('l');
						UART7_Write('l');
						delay_milli(5);
						UART7_Write('\0');
						delay_milli(5);
						UART0_Write('\n');
						UART0_Write('\r');
						while(Button_IsPressed(PortF, mask4 ,PULL_UP));
					}
					
				/*---------------------------------------------------------------------*/
					
				ADC0_SS3_In(&AIN0_DValue);
				AIN0_AValue = AIN0_DValue * ADC_RESOLUTION;
				nowPot = (int)((AIN0_AValue/3.3)*100);
				
				if ( nowPot < prevPot+2 && nowPot > prevPot-2 )  {}
				else
				{
					sprintf(PotValue , "%d" , nowPot);
					UART7_Write('p');
					delay_milli(5);
					UART0_Write('p');
					for(i=0 ; i<4 ; i++)
					{
						UART7_Write(PotValue[i]);
						
						UART0_Write(PotValue[i]);
						if(PotValue[i] == '\0') break;
					}
					UART0_Write('\n');
					UART0_Write('\r');					
					prevPot = nowPot ;
					}
				
		if(UART7_Available())
		{
				result=0;
				for( j=0 ; j<10 ; j++)
				{
					s = UART7_Read();
					si = s-'0';
					if(s	== '\0') break ;
					else result=result*10+si ;
				}
				LCD_Print(result);
				//UART0_Write('\n');
				//UART0_Write('\r');
		}
		
	}
}


void LCD_Print(uint32_t out)
{
		uint8_t i ;
		char y[4];
		
		LCD_Cmd(0x01);
		LCD_Cmd(0x14);
		LCD_Cmd(0x14);
		
		sprintf(y,"%d",out);
		for( i=0;i<4;i++)
		{
			if(y[i]=='\0')	break;
			LCD_Data(y[i]);
		}
	/*	for( i=0;i<4;i++)
		{
			if(y[i]=='\0')	break;
			UART0_Write(y[i]);	
		}
			UART0_Write('\n');
			UART0_Write('\r');	*/
}


