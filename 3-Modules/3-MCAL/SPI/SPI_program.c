/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/23/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  SPI_TEST	          	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
//the libs we need 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "SPI_interface.h"


void SPI_init(u8 mode)
{
	switch(mode)
	{
		case SPI_MASTER:
		
			//THIS MAKE THE MSB BIT TRANSMITED FIRST
			CLR_BIT(SPCR,5);
			
			//THIS TO SELECT THE MASTER MODE
			SET_BIT(SPCR,4);
			
			//THIS IS TO SELECT THE POLARITY OF THE CLK =  Leading Edge:Rising , Trailing Edge:Falling
			CLR_BIT(SPCR,3);
			
			//THIS IS TO SELECT THE PHASE OF CLK : SAMPLE->SETUP
			CLR_BIT(SPCR,2);
			
			//CLK PRESCALLER /64 ->250KHZ
			CLR_BIT(SPCR,0);
			SET_BIT(SPCR,1);
			CLR_BIT(SPSR,0);
			
			//THIS ENABLE THE SPI 
			SET_BIT(SPCR,6);
		break;
		
		case SPI_SLAVE:
		
			//THIS MAKE THE MSB BIT TRANSMITED FIRST
			CLR_BIT(SPCR,5);
			
			//THIS TO SELECT THE SLAVE	MODE
			CLR_BIT(SPCR,4);
			
			//THIS IS TO SELECT THE POLARITY OF THE CLK =  Leading Edge:Rising , Trailing Edge:Falling
			CLR_BIT(SPCR,3);
			
			//THIS IS TO SELECT THE PHASE OF CLK :  SAMPLE->SETUP
			CLR_BIT(SPCR,2);
			
			//THIS ENABLE THE SPI 
			SET_BIT(SPCR,6);
		break;
	}
}

void SPI_trancive(u8* data_send,u8* data_in)
{
	SPDR=*data_send;
	
	while(0==READ_BIT(SPSR,7));
	
	*data_in=SPDR;
	
	_delay_ms(1);
	
	
}

void SPI_sendwords(u8* data_send,u8* data_in)
{
	u8 counter=0;
	
	while(data_send[counter]!='\0')
	{
		SPI_sendrecivewords(&data_send[counter],&data_in[counter]);
		
		counter++;
	}
	
}