// #include "stm32f10x.h"               
// #include "Delay.h"
// #include "OLED.h"
// #include "AD.h"
// #include "Serial.h"
// #include "LED.h"



// int sensor[6]={0,0,0,0,0,0};

// int main(void)
// {
// 	OLED_Init();
// 	AD_Init();
// 	LED_Init();
// 	OLED_ShowString(1, 1, "ADValue:");
// 	OLED_ShowString(2, 1, "Volatge:00.00V");
	
// 	while (1)
// 	{



// 	}
// }



// #include "stm32f10x.h"           
// #include "Delay.h"
// #include "OLED.h"
// #include "MPU6050.h"
// #include "Serial.h"

// uint8_t ID;
// int16_t AX, AY, AZ, GX, GY, GZ;
// int sensor[6]={0,0,0,0,0,0};
// int main(void)
// {
// 	OLED_Init();
// 	MPU6050_Init();
// 	Serial_Init();
//	
// 	OLED_ShowString(1, 1, "ID:");
// 	ID = MPU6050_GetID();
// 	OLED_ShowHexNum(1, 4, ID, 2);
//	
// 	while (1)
// 	{
// 		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
//		
// 		OLED_ShowSignedNum(2, 1, AX, 5);
//		
// 		OLED_ShowSignedNum(3, 1, AY, 5);
//		
// 		OLED_ShowSignedNum(4, 1, AZ, 5);
// 		OLED_ShowSignedNum(2, 8, GX, 5);
// 		OLED_ShowSignedNum(3, 8, GY, 5);
// 		OLED_ShowSignedNum(4, 8, GZ, 5);
//		
// 		printf("date:%d,", AX);
// 		printf("%d,", AY);
// 		printf("%d,", AZ);
// 		printf("%d,", GX);
// 		printf("%d,", GY);
// 		printf("%d\r\n", GZ);
// 	}
// }



#include "stm32f10x.h"               
//#include "Delay.h"
#include "PWM.h"    
#include "Wheel.h"  
#include "OLED.h"
//#include "AD.h"
//#include "LED.h"
#include "Timer.h"
#include "Encoder.h"

int16_t Speed;
int sensor[6]={0,0,0,0,0,0};


int main(void)
{
	PWM_Init();
	Wheel_Init();
	OLED_Init();
	//AD_Init();
	//LED_Init();
	Timer_Init();
	Encoder_Init();
	OLED_ShowString(1, 1, "Speed:");
	
	while (1)
	{
		Car_RUN(90,-90);
		OLED_ShowSignedNum(1, 7, Speed, 5);
	}
}

void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Speed = Encoder_Get();
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
