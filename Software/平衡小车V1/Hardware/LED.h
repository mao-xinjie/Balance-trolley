#ifndef __LED_H
#define __LED_H

void LED_Init(void);			//初始化LED函数

void LEDG_ON(void);				//打开绿色LED
void LEDG_OFF(void);			//关闭绿色LED
void LEDG_Turn(void);			//取反绿色LED

void LEDB_ON(void);				//打开蓝色LED
void LEDB_OFF(void);			//关闭蓝色LED
void LEDB_Turn(void);			//取反蓝色LED

#endif
