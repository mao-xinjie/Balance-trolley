#include "stm32f10x.h"                  // Device header

void Wheel_Init(void)//对相应的IO口进行初始化,
{

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOA的时钟	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//输出模式为推挽输出，电平可高可低
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//管脚传输速度
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

void forward(void)//小车两个电机正转
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);										//PA0高电平	     1
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);										//PA1低电平   0
	GPIO_SetBits(GPIOB,GPIO_Pin_14);											//PA4高电平	     1
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);										//PA5低电平   0
}

void M1_forward(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);									
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);																			
}

void M1_backward(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);										
	GPIO_SetBits(GPIOB,GPIO_Pin_12);																				
}

void M2_forward(void)
{										
	GPIO_SetBits(GPIOB,GPIO_Pin_14);											
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);										
}

void M2_backward(void)
{										
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);										
	GPIO_SetBits(GPIOB,GPIO_Pin_15);										
}
