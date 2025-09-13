/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   8/23/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   ATMEGA32_REG          *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_
					/*DIO_REGS*/
/* DIRECT MEM*/
#define DDRA (*(volatile u8*)0x3A)
#define DDRB (*(volatile u8*)0x37)
#define DDRC (*(volatile u8*)0x34)
#define DDRD (*(volatile u8*)0x31)

/*OUTPUT MEM*/
#define PORTA (*(volatile u8*)0x3B)
#define PORTB (*(volatile u8*)0x38)
#define PORTC (*(volatile u8*)0x35)
#define PORTD (*(volatile u8*)0x32)

/*INPUT MEM*/
#define PINA (*(volatile u8*)0x39)
#define PINB (*(volatile u8*)0x36)
#define PINC (*(volatile u8*)0x33)
#define PIND (*(volatile u8*)0x30)


/*EXTIRANL INTERRPTURES*/

/*STATUS REG*/
#define SREG   (*(volatile u8*)0x5F)

/*GENERAL INTERRPTURE CONTROL REG*/
#define GICR   (*(volatile u8*)0x5B)

/*GENERAL INTERRPTURE FLAG REG*/
#define GIFR   (*(volatile u8*)0x5A)

/*MCU CONTROL REGESTER*/
#define MCUCR  (*(volatile u8*)0x55)

/*MCU CONTROL AND STATUS REG*/
#define MCUCSR (*(volatile u8*)0x54)






#endif /* ATMEGA32_REG_H_ */