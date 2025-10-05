/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/28/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  EEPROM_TEST	        *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/

#define F_CPU 16000000UL
#include <util/delay.h>

//the libs we need 
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "TWI_interface.h"
/*HAL*/
#include "EEPROM_interface.h"

void EEPROM_WriteData(u16 addressword,u8 data)
{
	//this line will add the 1010 fixed address with the plus three bits of the word address (A2,A1,A0)
	u8 adress = ((u8) EEPROM_FIXED_ADDRESS | (u8) (addressword>>8));
	
	//start condation
	TWI_startcondetion();
	
	//send the slave and the word address (A2,A1,A0)
	TWI_sendaddwithwrite(adress);
	
	//send data and it the rest of word address
	TWI_SendDataWithWrite((u8) addressword);
	
	//send the actual data you want 
	TWI_SendDataWithWrite(data);
	
	//stop condation
	TWI_stopcondetion();
	
	//delay 5m between every command send 
	_delay_ms(5);
}
void EEPROM_ReadData(u16 addressword,u8* data)
{
	//this line will add the 1010 fixed address with the plus three bits of the word address (A2,A1,A0)
	u8 adress = ((u8) EEPROM_FIXED_ADDRESS | (u8) (addressword>>8));
	
	//start condition
	TWI_startcondetion();
	
	//send the slave and the word address (A2,A1,A0)
	TWI_sendaddwithwrite(adress);
	
	//send data and it the rest of word address
	TWI_SendDataWithWrite((u8) addressword);
	
	//restart condition
	TWI_repstartcondetion();
	
	//send the slave and the word address (A2,A1,A0)
	TWI_sendaddwithread(adress);
	
	//recvie
	TWI_ReciveDataWithRead(data);
	
	//stop condition
	TWI_stopcondetion();
	
	//delay 5m between every command send 
	_delay_ms(5);
	
}