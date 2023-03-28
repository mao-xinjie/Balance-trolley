#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);

void M1PWM(int16_t Compare);
void M2PWM(int16_t Compare);
void Car_RUN(int16_t Speed1,int16_t Speed2);
#endif
