/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   8/16/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   7SEG-CAT           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
#include "SSD_interface.h"


int main(void)
{
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	SSD_init();
	u8 counter;
    while (1) 
    {
		for (counter=0;counter<=10;counter++)
		{
			SSD_displaynymber(counter);
			_delay_ms(250);
		}
    }
}

