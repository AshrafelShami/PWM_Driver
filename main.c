#include "PWM_Config.h"

int main(void){
	
	Struct_PWM PWM_Init_Struct;
	
	PWM_Init_Struct.Waveform_Generation_Mode = Fast_PWM;
	PWM_Init_Struct.Compare_Output_Mode	 = WGM_Fast_PWM__Non_Invertin_Mode;
	PWM_Init_Struct.Prescaler_Select	 = Division_Factor_1024;
	
	PWM_Init(PWM_Init_Struct);

	while (1){
		PWM_Duty_Cycle(1);
	}
}

