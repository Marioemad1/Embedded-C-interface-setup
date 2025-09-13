/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date    :   9/9/2025				*************************************************
**************************************************    Name    :   Mario Emad Boles	 	*************************************************
**************************************************    Version :   1.0            		*************************************************
**************************************************    SWC     :   EXTIN		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
//the libs we need
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "EXTIN_interface.h"

void (*INT0pcallback)(void)= NULL;
void (*INT1pcallback)(void)= NULL;
void (*INT2pcallback)(void)= NULL;

void EXTIN_enable(u8 extinsource,u8 extintregar)
{
	switch(extinsource)
	{
		case EXTIN0:
			switch(extintregar)
			{
				case RISING_EDGE:
				SET_BIT(MCUCR,0); //BIT 0
				SET_BIT(MCUCR,1); //BIT 1
				break;
				
				case FALLING_EDGE:
				CLR_BIT(MCUCR,0); //BIT 0
				SET_BIT(MCUCR,1); //BIT 1
				break;
				
				case LOGICAL_CHANGE:
				SET_BIT(MCUCR,0); //BIT 0
				CLR_BIT(MCUCR,1); //BIT 1
				break;
				
				case LOW_LEVEL:
				CLR_BIT(MCUCR,0); //BIT 0
				CLR_BIT(MCUCR,1); //BIT 1
				break;
			}
		
		SET_BIT(GICR,6); //enable the interaptur INT0
		break;
		
		case EXTIN1:
		
			switch(extintregar)
			{
				case RISING_EDGE:
				SET_BIT(MCUCR,2); //BIT 2
				SET_BIT(MCUCR,3); //BIT 3
				break;
				
				case FALLING_EDGE:
				CLR_BIT(MCUCR,2); //BIT 2
				SET_BIT(MCUCR,3); //BIT 3
				break;
				
				case LOGICAL_CHANGE:
				SET_BIT(MCUCR,2); //BIT 2
				CLR_BIT(MCUCR,3); //BIT 3
				break;
				
				case LOW_LEVEL:
				CLR_BIT(MCUCR,2); //BIT 2
				CLR_BIT(MCUCR,3); //BIT 3
				break;
			}
		SET_BIT(GICR,7); //enable the interaptur INT1
		break;
		
		case EXTIN2:
			switch(extintregar)
			{
				case RISING_EDGE:
				SET_BIT(MCUCSR,6);
				break;
				
				case FALLING_EDGE:
				CLR_BIT(MCUCSR,6);
				break;
			}
		
		SET_BIT(GICR,5); //enable the interaptur INT2
		break;
	}
}

void EXTIN_disable(u8 extinsource)
{
	switch(extinsource)
	{
		case EXTIN0:
		
		CLR_BIT(GICR,6);//disable the interaptur INT0
		
		break;
		
		case EXTIN1:
		
		CLR_BIT(GICR,7);//disable the interaptur INT1
		
		break;
		
		case EXTIN2:
		
		CLR_BIT(GICR,5); //disable the interaptur INT2
		
		break;
		
	}
}

void EXTIN0_callback(void(*ptr)(void))
{
	INT0pcallback=ptr;
}

void EXTIN1_callback(void(*ptr)(void))
{
	INT1pcallback=ptr;
}

void EXTIN2_callback(void(*ptr)(void))
{
	INT2pcallback=ptr;
}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	INT0pcallback();
}

void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{
	INT1pcallback();
}

void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{
	INT2pcallback();
}