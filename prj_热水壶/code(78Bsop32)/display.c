#define __display_c
#include "includeAll.h"

/**************************************************
P_led1、P_led2分别置为1或0，控制相应LED灯的亮或灭
led1、led2灯IO模式初始化为
P1_2(LED2):P1MODL = 0xa8;
P1_4(LED1):P1MODH = 0xaa;
**************************************************/
//同时打开LED1、LED2
void LED1_and_LED2() {
		//初始化Led灯,将P1_0置为0
		F_ledcom_On();
	
		P_led1=1;
		P_led2=1;
}

//打开LED1
void LED1_ON() {
		//初始化Led灯,将P1_0置为0
		F_ledcom_On();
	
		P_led1=1;
		P_led2=0;
}

//打开LED2
void LED2_ON() {
		//初始化Led灯,将P1_0置为0
		F_ledcom_On();
	
		P_led1=0;
		P_led2=1;
}