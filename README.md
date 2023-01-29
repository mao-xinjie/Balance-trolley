# 基于STM32的平衡车控制板V1.0

![屏幕截图 2023-01-29 172510](https://s2.loli.net/2023/01/29/hDbSvN27rcKAO39.png)



#### 资料说明（更新日期23-1-29）

- 已添加PCB源文件
- 已添加PCB可视化BOM表
- 已添加各芯片数据手册（位于Sources文件夹中）

### 关于硬件设计

硬件PCB设计参考了[ROS机器人仓库](https://github.com/fan-ziqi/My_ROS_Robot)的电路和布局。

主控采用STM32F103C6T6,一个TB6612实现驱动两路电机，板载MPU6050以及CH340N串口芯片实现与电脑通信。

### 关于软件设计

- 逐步完善中。。。