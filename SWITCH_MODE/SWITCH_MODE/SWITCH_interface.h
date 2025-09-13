/*
 * SWITCH_interface.h
 *
 * Created: 9/3/2025 9:43:32 AM
 *  Author: emadm
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define SWITCH_PRESSED       DIO_PIN_HIGH
#define SWITCH_NOT_PRESSED   DIO_PIN_LOW

/*APIS*/
void SWITCH_init(u8 PortId,u8 PinId);
void SWITCH_state(u8 PortId,u8 PinIdu8,u8* switch_state);



#endif /* SWITCH_INTERFACE_H_ */