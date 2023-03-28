//#include "stm32f10x.h"               
//#include "Delay.h"
//#include "OLED.h"
//#include "AD.h"
//#include "Serial.h"

//uint16_t ADValue;
//float Voltage;


//int sensor[6]={0,0,0,0,0,0};

//int main(void)
//{
//	OLED_Init();
//	AD_Init();
////	Serial_Init();
////	Serial_SendByte(0x41);
////	printf("\r\n%d", 22);
//	
//	OLED_ShowString(1, 1, "ADValue:");
//	OLED_ShowString(2, 1, "Volatge:00.00V");
//	
//	while (1)
//	{
//		ADValue = AD_GetValue();
//		Voltage = (float)ADValue / 4095 * 12;
//		
////		printf("\r\n%d", -ADValue);
//		OLED_ShowNum(1, 9, ADValue, 4);
//		OLED_ShowNum(2, 9, Voltage, 2);
//		OLED_ShowNum(2, 12, (uint16_t)(Voltage * 100) % 100, 2);
//		
//		Delay_ms(100);
//	}
//}



#include "stm32f10x.h"           
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "Serial.h"

uint8_t ID;
int16_t AX, AY, AZ, GX, GY, GZ;
int sensor[6]={0,0,0,0,0,0};
int main(void)
{
	OLED_Init();
	MPU6050_Init();
	Serial_Init();
	
	OLED_ShowString(1, 1, "ID:");
	ID = MPU6050_GetID();
	OLED_ShowHexNum(1, 4, ID, 2);
	
	while (1)
	{
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);
		
		OLED_ShowSignedNum(2, 1, AX, 5);
		
		OLED_ShowSignedNum(3, 1, AY, 5);
		
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);
		
		printf("date:%d,", AX);
		printf("%d,", AY);
		printf("%d,", AZ);
		printf("%d,", GX);
		printf("%d,", GY);
		printf("%d\r\n", GZ);
	}
}



//#include "stm32f10x.h"               
//#include "Delay.h"
//#include "OLED.h"
//#include "Serial.h"

//#include "PWM.h"    
//#include "Wheel.h"  

//int sensor[6]={0,0,0,0,0,0};

//int main(void)
//{
//	PWM_Init();
//	Wheel_Init();
//	PWM_SetCompare1(5000);
//	
//	while (1)
//	{
//	forward();
//	}
//}