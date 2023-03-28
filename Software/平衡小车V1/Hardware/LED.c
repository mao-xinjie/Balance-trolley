#include "stm32f10x.h"                  // Device header


//LED引脚初始化函数

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_8 | GPIO_Pin_9);
}


//绿色LED  /开 、关 、转换

void LEDG_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
}

void LEDG_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_8);
}

void LEDG_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_8) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	}
}


//蓝色LED  /开 、关 、转换

void LEDB_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_9);
}

void LEDB_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_9);
}

void LEDB_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_9) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_9);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	}
}
