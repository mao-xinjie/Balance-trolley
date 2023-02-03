#include "stm32f10x.h"                  	
#include "PWM.h"
#include "Timer.h"


int M1PWM,M2PWM;
int PID_sd=0;																			//小车差速PID控制器的PWM输出值
extern int error;

int Position_PID (int Encoder,int Target)   											//差速PID控制器//这里Encoder=error，Target=0;
{ 	
	 float Position_KP=150,Position_KI=0.2,Position_KD=1000;
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  								//计算偏差
	 Integral_bias+=Bias;	                                 							//求出偏差的积分
	 Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
	 Last_Bias=Bias;                                       								//保存上一次偏差 
	 return Pwm;                                           								//返回PWM值
}


void Run_PID(void)																		//将OUTPUT，OUTPUT1，OUTPUT2输出出去，使舵机和小车电机受到相应控制
{
		  
		TIM_SetCompare2(TIM2,M1PWM);													//电机控制
	    TIM_SetCompare2(TIM2,M2PWM);													//电机控制
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		PID_sd=Position_PID (error,0);													//将差速PID控制器输出的PWM值赋值给PID_sd       
		Run_PID();		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
