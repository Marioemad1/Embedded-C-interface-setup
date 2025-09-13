/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/7/2025 9:31:51 	*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   KPD		          	*************************************************
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
#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"

int main(void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN4,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_INPUT);
    /* Replace with your application code */
    while (1) 
    {
		
		{
			
		}
    }
}

