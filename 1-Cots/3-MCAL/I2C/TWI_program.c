/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/25/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  TWI_TEST	          	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/
//the libs we need 
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "TWI_interface.h"

void TWI_initMasrer(void)
{
	//sets the prescaler to 1
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	
	//sets the scl fquz to 400KHZ
	TWBR =12;
	
	//Enable the ACK
	SET_BIT(TWCR,6);
	
	//Enable the TWI
	SET_BIT(TWCR,2);
	
}

void TWI_initSlave(u8 address)
{
	//set the address of the slave
	TWAR = address<<1;
	
	//Enable the ACK
	SET_BIT(TWCR,6);
	
	//Enable the TWI
	SET_BIT(TWCR,2);
}

void TWI_startcondetion(void)
{
	//send start condation 
	SET_BIT(TWCR,5);
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the start condation ACKNOLGED
	while((TWSR & 0xF8) != 0x08);
}

void TWI_repstartcondetion(void)
{
	//send start condation 
	SET_BIT(TWCR,5);
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the repeated start condation ACKNOLGED
	while((TWSR & 0xF8) != 0x10);
	
	
}

void TWI_stopcondetion(void)
{
	//send Stop condation 
	SET_BIT(TWCR,4);
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
}
void TWI_sendaddwithread(u8 address)
{
	//send the addeess on the data reg to call the slave 
	TWDR = address<<1;
	//set the op to read from the slave
	SET_BIT(TWDR,0);
	
	//clear start condation 
	CLR_BIT(TWCR,5);
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the ACKNOLGED
	while((TWSR & 0xF8) != 0x40);
}
void TWI_sendaddwithwrite(u8 address)
{
	//send the addeess on the data reg to call the slave 
	TWDR = address<<1;
	//set the op to write to the slave
	CLR_BIT(TWDR,0);
	
	//clear start condation 
	CLR_BIT(TWCR,5);
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the ACKNOLGED
	while((TWSR & 0xF8) != 0x18);
}
void TWI_SendDataWithWrite(u8 data)
{
	
	
	 TWDR = data;
	
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the ACKNOLGED
	while((TWSR & 0xF8) != 0x28);
}
void TWI_ReciveDataWithRead(u8* data)
{
	//clear the flag to make the current action
	SET_BIT(TWCR,7);
	
	//stuck untile the flag is up
	while(0==READ_BIT(TWCR,7));
	
	//stuck untile the ACKNOLGED
	while((TWSR & 0xF8) != 0x50);
	
	*data=TWDR;
}