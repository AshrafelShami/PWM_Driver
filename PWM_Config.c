#include "PWM_Config.h"


/********************************************************************************************
  Name:     PWM_Init.
  Purpose:  Initialization for Timer0/PWM Registers.
  Entry:    (Struct_PWM) a STRUCT that setup the following.
							1) Wave Generation Mode.
							2) Compare Output Mode.
							3) Pre-scaler.
  Exit:     no parameters
********************************************************************************************/
void PWM_Init( Struct_PWM PWM_Config ){
	DDRB |= (1 << 3);		/*	Set OC0 pin as output	*/
	switch (PWM_Config.Waveform_Generation_Mode){
		case Normal				: TCCR0 &=~(1 << WGM01); TCCR0 &=~(1 << WGM00); break;
		case PWM_Phase_Correct	: TCCR0 &=~(1 << WGM01); TCCR0 |= (1 << WGM00); break;
		case CTC				: TCCR0 |= (1 << WGM01); TCCR0 &=~(1 << WGM00); break;
		case Fast_PWM			: TCCR0 |= (1 << WGM01); TCCR0 |= (1 << WGM00); break;
		default					: TCCR0 |= (1 << WGM01); TCCR0 |= (1 << WGM00); break;
	}
	
	switch (PWM_Config.Compare_Output_Mode){
		case WGM_Normal__Normal_Port_Operation			: TCCR0 &=~ (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Normal__Toggle_On_CMP_Match			: TCCR0 &=~ (1 << COM01); TCCR0 |=  (1 << COM00); break;
		case WGM_Normal__Clear_On_CMP_Match				: TCCR0 |=  (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Normal__Set_On_CMP_Match				: TCCR0 |=  (1 << COM01); TCCR0 |=	(1 << COM00); break;
		
		case WGM_Fast_PWM__Normal_Port_Operation		: TCCR0 &=~ (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Fast_PWM__Non_Invertin_Mode			: TCCR0 |=  (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Fast_PWM__Inverting_Mode				: TCCR0 |=  (1 << COM01); TCCR0 |=	(1 << COM00); break;
		
		case WGM_Phase_Correct__Normal_Port_Operation	: TCCR0 &=~ (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Phase_Correct__Non_Invertin_Mode		: TCCR0 |=  (1 << COM01); TCCR0 &=~ (1 << COM00); break;
		case WGM_Phase_Correct__Inverting_Mode			: TCCR0 |=  (1 << COM01); TCCR0 |=	(1 << COM00); break;
		
		default											: TCCR0 |=  (1 << COM01); TCCR0 |=	(1 << COM00); break;
	}

	switch(PWM_Config.Prescaler_Select){
		case No_Clock_Source				: TCCR0 &=~(1 << CS02); TCCR0 &=~(1 << CS01); TCCR0 &=~(1 << CS00); break;
		case Division_Factor_OFF			: TCCR0 &=~(1 << CS02); TCCR0 &=~(1 << CS01); TCCR0 |= (1 << CS00); break;
		case Division_Factor_8				: TCCR0 &=~(1 << CS02); TCCR0 |= (1 << CS01); TCCR0 &=~(1 << CS00); break;
		case Division_Factor_64				: TCCR0 &=~(1 << CS02); TCCR0 |= (1 << CS01); TCCR0 |= (1 << CS00); break;
		case Division_Factor_256			: TCCR0 |= (1 << CS02); TCCR0 &=~(1 << CS01); TCCR0 &=~(1 << CS00); break;
		case Division_Factor_1024			: TCCR0 |= (1 << CS02); TCCR0 &=~(1 << CS01); TCCR0 |= (1 << CS00); break;
		case External_Clk_Src_Falling_egde	: TCCR0 |= (1 << CS02); TCCR0 |= (1 << CS01); TCCR0 &=~(1 << CS00); break;
		case External_Clk_Src_Rising_egde	: TCCR0 |= (1 << CS02); TCCR0 |= (1 << CS01); TCCR0 |= (1 << CS00); break;
		default								: TCCR0 |= (1 << CS02); TCCR0 &=~(1 << CS01); TCCR0 |= (1 << CS00); break;
	}
}

/********************************************************************************************
  Name:     PWM_Duty_Cycle.
  Purpose:  Initialization for Timer0/PWM Registers.
  Entry:    (u8 Duty_Cycle): Function Takes the DutyCycle (0 ~ 100),
							 and set the Output Compare register.
  Exit:     no parameters
********************************************************************************************/
void PWM_Duty_Cycle ( u8 Duty_Cycle ){
	OCR0 = ((Duty_Cycle*255) / 100);
}
