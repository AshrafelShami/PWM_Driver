
#ifndef PWM_CONFIG_H_
#define PWM_CONFIG_H_

#include "Functions_Prototypes.h"
#include "Datatypes.h"
#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>

typedef enum{
	Normal,
	PWM_Phase_Correct,
	CTC,
	Fast_PWM
	
}Waveform_Gen_Mode;

typedef enum{
	WGM_Normal__Normal_Port_Operation,
	WGM_Normal__Toggle_On_CMP_Match,
	WGM_Normal__Clear_On_CMP_Match,
	WGM_Normal__Set_On_CMP_Match,
	
	WGM_Fast_PWM__Normal_Port_Operation,
	WGM_Fast_PWM__Non_Invertin_Mode,
	WGM_Fast_PWM__Inverting_Mode,
	
	WGM_Phase_Correct__Normal_Port_Operation,
	WGM_Phase_Correct__Non_Invertin_Mode,
	WGM_Phase_Correct__Inverting_Mode
	
}CMP_Match;

typedef enum{
	No_Clock_Source,
	Division_Factor_OFF,
	Division_Factor_8,
	Division_Factor_64,
	Division_Factor_256,
	Division_Factor_1024,
	External_Clk_Src_Falling_egde,
	External_Clk_Src_Rising_egde
	
}Clk_Select;

typedef struct{
	Waveform_Gen_Mode	Waveform_Generation_Mode;
	CMP_Match			Compare_Output_Mode;
	Clk_Select			Prescaler_Select;
}Struct_PWM;

void PWM_Init (Struct_PWM);

#endif /* PWM_CONFIG_H_ */