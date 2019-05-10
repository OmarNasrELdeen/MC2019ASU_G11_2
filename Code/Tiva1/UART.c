#include "tm4c123gh6pm.h"
#include "stdint.h"

#define GPIO_PA10_M 0x03
#define GPIO_PE10_M 0x03
#define GPIO_PE54_M 0x30
void UART0_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 520;    
  UART0_FBRD_R = 53;
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= GPIO_PA10_M;
}

void UART7_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R7;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	
	UART7_CTL_R &= ~UART_CTL_UARTEN;
	UART7_IBRD_R = 520;    
  UART7_FBRD_R = 53;
	UART7_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART7_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTE_AFSEL_R |= GPIO_PE10_M;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PE1_U7TX | GPIO_PCTL_PE0_U7RX);
	GPIO_PORTE_DEN_R |= GPIO_PE10_M;
	   //interrupt
/*	 UART7_IM_R|=0x10;
	 NVIC_PRI15_R = ( NVIC_PRI15_R & NVIC_PRI15_INTD_M )|0x80000000;
	 NVIC_EN1_R |=0x80000000;  
 */
}

uint8_t UART0_Available(void){
	return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}
uint8_t UART7_Available(void){
	return ((UART7_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART0_Read(void){
	while(UART0_Available() != 1);
	return (uint8_t)(UART0_DR_R&0xFF);
}
uint8_t UART7_Read(void){
	while(UART7_Available() != 1);
	return (uint8_t)(UART7_DR_R&0xFF);
}
void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
void UART7_Write(uint8_t data){
	while((UART7_FR_R&UART_FR_TXFF) != 0);
	UART7_DR_R = data;
}

void UART0_Read_String (char c[]){
     int i =0 ;
	   char s ;
		while(1)
		{
			s = UART0_Read();
			UART0_Write(s);
			if(s	==	13) 
				{
					c[i]='\0';
					UART0_Write('\n');
					break ;
				}
			else 
			{
				c[i] = s ;
				i++ ;
			}
		}
	}

void UART7_Read_String (char c[]){
     int i =0 ;
	   char s ;
		while(1)
		{
			s = UART7_Read();
			UART7_Write(s);
			if(s	==	'\0') //(s	==	13) 
				{
					c[i]='\0';
					//UART7_Write('\n');
					break ;
				}
			else 
			{
				c[i] = s ;
				i++ ;
			}
		}
	}
uint8_t StringToInt(char c[])
{
	uint8_t duty=0;int i=0;
	for(i=0;c[i]!='\0';i++)
		{
			duty=duty*10+(c[i]-'0');
		}
		return duty;
}