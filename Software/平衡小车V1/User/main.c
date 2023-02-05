#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t ADValue;
float Voltage;

int sensor[6]={0,0,0,0,0,0};

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "ADValue:");
	OLED_ShowString(2, 1, "Volatge:00.00V");
	
	while (1)
	{
		ADValue = AD_GetValue();
		Voltage = (float)ADValue / 4095 * 12;
		
		OLED_ShowNum(1, 9, ADValue, 4);
		OLED_ShowNum(2, 9, Voltage, 2);
		OLED_ShowNum(2, 12, (uint16_t)(Voltage * 100) % 100, 2);
		
		Delay_ms(100);
	}
}
