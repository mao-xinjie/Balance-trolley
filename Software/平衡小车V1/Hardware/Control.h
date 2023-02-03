#ifndef __CONTROL_H
#define __CONTROL_H

int Position_PID (int Encoder,int Target);
void Run_PID(void);
void TIM2_IRQHandler(void);

#endif