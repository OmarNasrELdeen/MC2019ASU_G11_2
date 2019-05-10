

#include "Mcal.h"
#include "DIO.h"
#include "delay.h"

extern int step;
extern char steps[];
void STEPPER_MOTOR_voidInit(void)
{
	Port_Init(PortB);
	Port_SetPinDirection(PortB,(mask0|mask1|mask2|mask3),PORT_PIN_OUT);
}
 
void STEPPER_MOTOR_MOVE_30(int direction)
{
int k=0;
for ( k=0;k<300;k++)
{
	if (direction)
	GPIO_PORTB_DATA_R  = (steps[step++ & 3]);
	else
	GPIO_PORTB_DATA_R  = (steps[step-- & 3]);
	delay_milli(3);
}
}

 
