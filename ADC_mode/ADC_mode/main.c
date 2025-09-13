/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/12/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   ADC		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
/*UTILES*/
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "ADC_interface.h"
#include "DIO_Interface.h"
/*HAL*/
#include "LED_interface.h"



int main(void)
{
	//ADC CONVERTER PIN
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);
	
	//LEDS PINS
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	ADC_init();
	u16 digitalvalue,analogvalue;
    while (1) 
    {
		ADC_getdigitalvalue(ADC_CHANNEL1,&digitalvalue);
		
		analogvalue=(((u32)digitalvalue*5000UL)/1024);
		
		if (analogvalue < 1500)
		{
			LED_ON (DIO_PORTC,DIO_PIN2);
			LED_OFF(DIO_PORTC,DIO_PIN7);
			LED_OFF(DIO_PORTD,DIO_PIN3);
		}
		else if (analogvalue < 3000)
		{
			LED_OFF (DIO_PORTC,DIO_PIN2);
			LED_ON  (DIO_PORTC,DIO_PIN7);
			LED_OFF (DIO_PORTD,DIO_PIN3);
		}
		else
		{
			LED_OFF (DIO_PORTC,DIO_PIN2);
			LED_OFF (DIO_PORTC,DIO_PIN7);
			LED_ON  (DIO_PORTD,DIO_PIN3);
		}
		
		
    }
}

