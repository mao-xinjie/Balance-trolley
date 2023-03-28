#ifndef __AD_H
#define __AD_H

void AD_Init(void);
uint16_t AD_GetValue(void);
float Get_Voltage(void);

/*
低电压报警
当电压低于10.8V时，绿色LED灯亮起，提示该电池电量低

使用方法
1.在主函数中初始化AD以及LED
2.在定时器中断中调用该函数，便可以实现低电压检测功能
*/  
void Detect_low_voltages(void);
	
#endif
