#include "stm32f10x.h"                  // Device header


//LED引脚初始化函数
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	/*
	PB3和PB4一直处于高电平
	原因是PB3和PB4在系统复位时候，分别默认为SYS_JIDO和SYS_HJTRST；
	所以需要通过用户自行禁止其功能；
	也就是想要正常使用PB3和PB4的主功能的时候。
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOB, GPIO_Pin_1 | GPIO_Pin_3);
}


//绿色LED  /开 、关 、转换
void LEDG_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
}

void LEDG_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_3);
}

void LEDG_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_3) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	}
}


//蓝色LED  /开 、关 、转换

void LEDB_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_1);
}

void LEDB_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_1);
}

void LEDB_Turn(void)
{
	if (GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_1);
	}
}
