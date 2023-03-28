#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	//选择时基单元的时钟  内部时钟 可以不写因为上电默认内部时钟
	TIM_InternalClockConfig(TIM1);
	//配置是时基单元 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;	//自动重装
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1; //分频
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM1, TIM_FLAG_Update);
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM1, ENABLE);
}




// void TIM1_UP_IRQHandler(void)
// {
// 	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
// 	{

// 		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
// 	}
// }
