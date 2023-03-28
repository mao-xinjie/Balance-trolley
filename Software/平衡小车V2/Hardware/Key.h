#ifndef __KEY_H
#define __KEY_H

void Key_Init(void);		//初始化按键函数
uint8_t Key_GetNum(void);	//获取被按下的按键编号

/*
主函数中定义 uint8_t KeyNum;
将Key_GetNum(void)值返回KeyNum
根据KeyNum值判断按键
*/

#endif
