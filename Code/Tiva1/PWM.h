#include "types.h"
#ifndef PWM_H
#define PWM_H
#define GPIO_PF2_M	0x04
void Blue_PWM1_Init();
void BlueLED_SetDutyCycle(uint8_t duty_cycle);
void servo_center(uint32_t duty_cycle);

#endif