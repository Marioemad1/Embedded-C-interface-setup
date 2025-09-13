/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/6/2025				*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   LCD		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/

//the libs we need
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
/*HAL*/
#include "LCD_Interface.h"
#include "LCD_Config.h"
#define  F_CPU 16000000
#include <util/delay.h>



int main(void)
{
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	
	LCD_init();
	LCD_gotoposition(2,0);
	LCD_sendword("MARIO");	
	
    /* Replace with your application code */
    while (1) 
    {
		LCD_shift(LCD_SHIFT_LEFT);
		_delay_ms(500);
		LCD_clearscreen();
    }
}

