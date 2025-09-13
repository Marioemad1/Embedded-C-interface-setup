/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/6/2025				*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   LCD_INTER           	*************************************************
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


void LCD_sendcmnd(u8 cmnd)
{
	//set the RS to 0 for command lines 
	DIO_SetPin(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	//SET THE R/W REG TO 0 FOR WRITEING
	DIO_SetPin(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	//THE MOST FIRST
	LCD_writeHalfport(cmnd>>4);
	
	//DELAY
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//THE LEAST
	LCD_writeHalfport(cmnd);
	
	//DELAY
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	
}

void LCD_sendchar(u8 data)
{
	//set the RS to 1 for Data lines
	DIO_SetPin(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	
	//SET THE R/W REG TO 0 FOR WRITEING
	DIO_SetPin(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	//THE MOST FIRST
	LCD_writeHalfport(data>>4);
	
	//DELAY
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//THE LEAST
	LCD_writeHalfport(data);
	
	//DELAY
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void LCD_init(void)
{
	_delay_ms(40);
	//set the RS to 0 for Command lines
	DIO_SetPin(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	//SET THE R/W REG TO 0 FOR WRITEING
	DIO_SetPin(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	LCD_writeHalfport(0b0010);
	
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPin(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	LCD_sendcmnd(0b00101000);
	
	_delay_us(45);
	
	//00001display,courser,blink
	LCD_sendcmnd(0b00001111);
	
	_delay_us(45);
	
	LCD_sendcmnd(0b00000001);
	
	_delay_ms(2);
	
	LCD_sendcmnd(0b00000110);
	_delay_ms(50);

	
}

void LCD_writeHalfport(u8 value)
{
	if(1==READ_BIT(value,0))
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,1))
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN5,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN5,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,2))
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN6,DIO_PIN_LOW);
	}
	
	if(1==READ_BIT(value,3))
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPin(DIO_PORTB,DIO_PIN7,DIO_PIN_LOW);
	}
}

void LCD_sendword(u8* ptr)
{
	u8 counter=0;
	while(ptr[counter]!='\0')
	{
		LCD_sendchar(ptr[counter]);
		counter++;
	}
}
void LCD_clearscreen(void)
{
	LCD_sendcmnd(0b00000001);
	_delay_ms(2);
}

void LCD_shift(u8 shiftdir)
{
	if(LCD_SHIFT_LEFT == shiftdir )
	{
		LCD_sendcmnd(0b00011000);
		_delay_us(45);
	}
	else if (LCD_SHIFT_RIGHT == shiftdir )
	{
		LCD_sendcmnd(0b00011100);
		_delay_us(45);
	}
}
void LCD_gotoposition(u8 line,u8 position)
{
	if(1 == line)
	{
		LCD_sendcmnd(0x80 + position);
		
	}
	else if(2 == line)
	{
		LCD_sendcmnd (0xC0+ position);
		
	}
}