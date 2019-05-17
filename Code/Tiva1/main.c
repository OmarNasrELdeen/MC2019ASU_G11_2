#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "UART.h"
#include "stdint.h"
#include "PWM.h"
#include "cstring"
#include "Temp.h"
#include "stdio.h"
#include "delay.h"
#include "Stepper_Motor.h"
#include "ports.h"
#include "Mcal.h"
#include "types.h"
#include "DIO.h"


char command_recived [10];
int duty=0;
int step = 0;
const char steps[ ] = {0x9, 0x3, 0x6, 0xC};

void SystemInit(void){
	PLL_Init();
  UART0_Init();
  UART7_Init();
  Blue_PWM1_Init();
	Temp_Init();
	STEPPER_MOTOR_voidInit();
 __enable_irq();
}
int main(void){
	
/*TEMPRATURE*/
	
	 char reading[10];
	 int i=0;
   int temp=Temp_Read();
	 int old_temp_read=0;
   sprintf(reading, "%d", temp); 
	 while(1)
	 {

 		  temp=Temp_Read();
		 
		 sprintf(reading, "%d", temp);
		 i=0;
		 if(temp>(old_temp_read+2) || temp<(old_temp_read-2) )
		 {
		 while(reading[i]!='\0')
		 {
				UART7_Write(reading[i]);
			  UART0_Write(reading[i]);
			  delay_milli(5);
			   i++;
		 }
			old_temp_read=temp;
       UART7_Write('\0');
		   UART0_Write('\0');
			  delay_milli(5);
	 }
	
	 if(UART7_Available())
	 {
	 UART7_Read_String(command_recived);
		 delay_milli(10);
       /*STEPPER MOTOR*/
	 if(! strcmp(command_recived,"r"))
	 {
			/*STEPPER_MOTOR_MOVE_30(RIGHT);*/
							int k=0;
							for(k=0;k<174;k++)
							{
							GPIO_PORTB_DATA_R=(steps[i++&3]);
							delay_milli(10);
							}
	 }
	 else if(! strcmp(command_recived,"l"))
	 {
		/*	STEPPER_MOTOR_MOVE_30(LEFT);  */
		 
							int k=0;
							for(k=0;k<174;k++)
							{
							GPIO_PORTB_DATA_R  = (steps[i-- & 3]);
							delay_milli(10);
							}
	 }
            /*PWM*/
	 else if(command_recived[0]=='p')
	 {
			char c[10];int i=1;
		  while(command_recived[i]!= '\0'){c[i-1]=command_recived[i];i++;}c[i-1]='\0';
			 duty=StringToInt(c);
			 BlueLED_SetDutyCycle(duty);
	 }
	 }
 }
}

/*
 void UART7_Handler(void)
 {
    UART7_Read_String(command_recived);
 
	 if(! strcmp(command_recived,"r"))
	 {
			STEPPER_MOTOR_MOVE_30(RIGHT);
	 }
	 else if(! strcmp(command_recived,"l"))
	 {
			STEPPER_MOTOR_MOVE_30(LEFT);
	 }
    
 
	 else if(command_recived[0]=='p')
	 {
			char c[10];int i=1;
		  while(command_recived[i]!= '\0'){c[i-1]=command_recived[i];i++;}c[i-1]='\0';
			 duty=StringToInt(c);
			 BlueLED_SetDutyCycle(duty);
	 }
    //clear the interrupt
	  UART7_ICR_R=0x0010;

 }
*/