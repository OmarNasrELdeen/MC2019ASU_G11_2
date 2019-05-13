#ifndef __UART_H__
#define	__UART_H__

#include "stdint.h"

void UART0_Init(void);

uint8_t UART0_Available(void);

uint8_t UART0_Read(void);

void UART0_Write(uint8_t data);

void UART5_Init(void);

void UART5_Write(uint8_t data);

void UART7_Init(void);

uint8_t UART5_Available(void);

uint8_t UART5_Read(void);

void UART5_Write(uint8_t data);

uint8_t UART7_Available(void);

uint8_t UART7_Read(void);

void UART7_Write(uint8_t data);

void UART0_Read_String (char c[]);

void UART7_Read_String (char c[]);

uint8_t StringToInt(char c[]);

#endif // __UART_H__
