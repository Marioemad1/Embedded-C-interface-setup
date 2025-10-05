/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   9/14/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   TMR		           	*************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/ 
//UTILES
#include "STO_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"
/* MCAL*/
#include "TMR_interface.h"
#include "TMR_config.h"

/*TIMER 0 FUNCTIONS*/

void(* TMR_0_OVR_global_ptr)(void)= NULL;
void(* TMR_0_CTC_global_ptr)(void)= NULL;
void TMR_timer0_init (void)
{
#if  TIMER_0_MODE == TIMER_0_OVR_MODE
	//set timer0 mode to Normal 
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	
	TCNT0 = PRELOAD_OVERFLOW_VALUE;
	
	//set the interrupt of the overflow
	SET_BIT(TIMSK,0);
	
	
#elif  TIMER_0_MODE == TIMER_0_CTC_MODE
	//set timer0 mode to CTC 
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	//set the interrupt of the Compare To Match
	SET_BIT(TIMSK,1);
	
#elif  TIMER_0_MODE == TIMER_0_FAST_PMW
	////set timer0 mode to the fast_pwm 
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	//this is the non inverting mode from the fast PWM
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	
#endif
	// set the prescaler=64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}


/*                                         THE COMPARE MATCH VALUE 
NOTE: IN THE CALLING OF THIS MODE YOU MUST CALL THIS FUNCTION FIRST
 */
void TMR_timer0_set_compareMatchValue(u8 matchvalue)
{
	OCR0 = matchvalue;
}

/*Over flow passing the function to global*/
void TMR_TIMER0_overflow_pcallback(void(* ptr)(void))
{
	TMR_0_OVR_global_ptr = ptr;
}

/*Compare match passing the function to global*/
void TMR_TIMER0_CTC_pcallback(void(* ptr)(void))
{
	TMR_0_CTC_global_ptr = ptr;
}


/*THE ISR OVR FOR THE TIMER 0*/

void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	
	static u16 counter=0;
	counter++;
	
	if(TIMER_0_NUM_OFOVERFLOW==counter)
	{
		//set back the counter to 112
		TCNT0 = PRELOAD_OVERFLOW_VALUE;
		
		//set back the counter
		counter=0;
		
		// call the function of the ISR
		TMR_0_OVR_global_ptr();
		
		
	}
	
}

/*THE ISR CTC FOR THE TIMER 0*/

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	
	static u16 counter=0;
	counter++;
	
	if(TIMER_0_NUMOF_CTC==counter)
	{
		
		//set back the counter
		counter=0;
		
		// call the function of the ISR
		TMR_0_CTC_global_ptr();
		
		
	}
	
}


/*TIMER 1 FUNCTIONS*/

void TMR_timer1_init(void)
{
	//Choose the normal (fast PWM mode) FORM TIMER1 modes
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	//NON INVERTING MODE INSIDE THE FAST PWM
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	
	//THE FREQUNCE OF SERVO 50HZ SO 20MS TIME OF THE FULL CYCLE
	ICR1_u16 =4999;
	
	//CHOOSE THE PRESCALER TO 64 TO SIT THE HZ TO 250KHZ
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
}

void TMR_timer1_set_compareMatchValue(u16 OCR1A_VALUE)
{
	OCR1A_u16= OCR1A_VALUE;
}
