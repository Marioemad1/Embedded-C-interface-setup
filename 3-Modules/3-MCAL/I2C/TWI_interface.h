/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/25/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version  :   1.0	            	*************************************************
**************************************************    SWC      :  TWI_TEST	          	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

//initiate the mode
void TWI_initMasrer(void);
void TWI_initSlave(u8 address);

//start the frame and restart to change the R/W and the Slave
void TWI_startcondetion(void);
void TWI_repstartcondetion(void);

//stop the frame
void TWI_stopcondetion(void);

//call the Slave to address and select the R/W
void TWI_sendaddwithread(u8 address);
void TWI_sendaddwithwrite(u8 address);

//receive or send from or to the slave 
void TWI_SendDataWithWrite(u8 data);
void TWI_ReciveDataWithRead(u8* data);



#endif /* TWI_INTERFACE_H_ */