#include "stm32f10x.h"                  // Device header

void Wheel_Init(void)//对相应的IO口进行初始化,
{

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能GPIOA的时钟	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//输出模式为推挽输出，电平可高可低
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//管脚传输速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

void forward(void)//小车两个电机正转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);											//PA0高电平	     1
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);										//PA1低电平   0
	GPIO_SetBits(GPIOA,GPIO_Pin_4);											//PA4高电平	     1
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);										//PA5低电平   0
}


void stop(void)//小车两个电机反转，因为越过终点线时，单纯停止电机工作，小车会因为惯性停不下来，所以短时间的反转，能抵消惯性，从而使小车迅速停下来
{
	/*四个管脚设置不同的电平(1为高电平0为低电平)，作为TB6612的逻辑输入，用以控制电机转动状态。 */
	/*打个比方，四个管脚IO分别设置成0 1 0 1，电机反转，那么反过来设置成1 0 1 0时，电机正转*/
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);										//PA0低电平   0
	GPIO_SetBits(GPIOA,GPIO_Pin_1);											//PA1高电平	     1
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);										//PA4低电平	   0
	GPIO_SetBits(GPIOA,GPIO_Pin_5);											//PA5高电平     1
}