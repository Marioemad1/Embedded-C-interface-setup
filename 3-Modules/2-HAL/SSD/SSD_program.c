/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/10/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   SSD		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "DIO_Interface.h"
#include "SSD_interface.h"

void SSD_init(void)//this init for the ssd of amit kit
{
	DIO_SetPin(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	DIO_SetPin(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void SSD_displaynymber(u8 desirednumber)//this display for amit KIT
{
	SSD_writeHalfport(desirednumber);
}

void SSD_writeHalfport(u8 value)
{
	if(1==READ_BIT(value,0))
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D4_PIN,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D4_PIN,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,1))
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D5_PIN,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D5_PIN,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,2))
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D6_PIN,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D6_PIN,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,3))
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D7_PIN,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(SSD_DATA_PORT,SSD_D7_PIN,DIO_PIN_LOW);
	}
}