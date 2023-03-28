#include "stm32f10x.h"                  	
#include "PWM.h"
#include "Timer.h"


int LSpeed,RSpeed;
int Basic_PWM = 60;				//100为全速转动
int PID_sd=0;					//小车差速PID控制器的PWM输出值
extern int error;


//差速PID控制器//这里Encoder=error，Target=0;
int Position_PID (int Encoder,int Target)   											
{
	float Position_KP=0,Position_KI=0,Position_KD=0;
	static float Bias,Pwm,Integral_bias,Last_Bias;
		
	//计算偏差   偏差=实际值-目标值
	Bias=Encoder-Target;     
	//求出偏差的积分
	Integral_bias+=Bias;	   
	//位置式PID控制器
	Pwm=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);
	//保存上一次偏差 
	Last_Bias=Bias;          
	//返回PWM值
	return Pwm;                                           							
}


//void RUN_PID(void)				
//{	
//	M1PWM(LSpeed);						
//	M2PWM(RSpeed);													
//}


//采用定时器中断，每隔一段时间查询error进行差速控制
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		PID_sd = Position_PID(error, 0); // 将差速PID控制器输出的PWM值赋值给PID_sd
		LSpeed = Basic_PWM + PID_sd;
		RSpeed = Basic_PWM - PID_sd;
		Car_RUN(LSpeed, RSpeed);
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
