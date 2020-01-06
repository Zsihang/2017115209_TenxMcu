#define __display_c
#include "includeAll.h"
#include "display.h"

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


/**********************************
SMG_COM1控制左数码管
SMG_COM2控制右数码管
其他管脚分别控制相应位置led的亮灭
**********************************/
//数码管初始化
void smg_init() {
		//初始化各个灯脚，赋值为0
		SMG_A=0;
		SMG_B=0;
		SMG_C=0;
		SMG_D=0;
		SMG_E=0;
		SMG_F=0;
		SMG_G=0;
		SMG_DG=0;
	
		F_ledcom_Off();
}

//数码管选择
void smg_choice(uint8_t smgx) { 
    //选择左数码管
		if(smgx == SMG_L)         
    {
        SMG_COM1 = 0;
        SMG_COM2 = 1;
    }
		//选择右数码管
    if(smgx == SMG_R)
    {
        SMG_COM1 = 1;
        SMG_COM2 = 0;
    }
}

//选择数码管并显示数字0-9
void smg_display_num(uint8_t smgx,int num) {
		//选择左数码管
		if(smgx == SMG_L)         
    {
				smg_choice(1);
    }
		//选择右数码管
    if(smgx == SMG_R)
    {
				smg_choice(2);
    }
		
		switch(num)
		{
			case 0:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 1;
						 SMG_F = 1;
						 SMG_G = 0;
						 SMG_DG = 1;
						 break;
			
			case 1:SMG_A = 0;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 0;
						 SMG_E = 0;
						 SMG_F = 0;
						 SMG_G = 0;
						 SMG_DG = 1;
						 break;
			
			case 2:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 0;
						 SMG_D = 1;
						 SMG_E = 1;
						 SMG_F = 0;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;

			case 3:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 0;
						 SMG_F = 0;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;

			case 4:SMG_A = 0;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 0;
						 SMG_E = 0;
						 SMG_F = 1;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;
			case 5:SMG_A = 1;
						 SMG_B = 0;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 0;
						 SMG_F = 1;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;

			case 6:SMG_A = 1;
						 SMG_B = 0;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 1;
						 SMG_F = 1;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;
						 
			case 7:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 0;
						 SMG_E = 0;
						 SMG_F = 0;
						 SMG_G = 0;
						 SMG_DG = 1;
						 break;
			
			case 8:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 1;
						 SMG_F = 1;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;
				
			case 9:SMG_A = 1;
						 SMG_B = 1;
						 SMG_C = 1;
						 SMG_D = 1;
						 SMG_E = 0;
						 SMG_F = 1;
						 SMG_G = 1;
						 SMG_DG = 1;
						 break;
		}
}


//数码管显示on(开)和of(关)
void smg_display_num(uint8_t On_or_Of) {
		if(On_or_Of == SMG_ON){
				smg_choice(1);
				SMG_A = 1;
				SMG_B = 1;
				SMG_C = 1;
				SMG_D = 1;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 0;
				SMG_DG = 0;
	
				smg_choice(2);
				SMG_A = 1;
			  SMG_B = 1;
				SMG_C = 1;
				SMG_D = 0;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 0;
				SMG_DG = 0;
		}
		else if(On_or_Of == SMG_OFF){
				smg_choice(1);
				SMG_A = 1;
				SMG_B = 1;
				SMG_C = 1;
				SMG_D = 1;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 0;
				SMG_DG = 0;
	
				smg_choice(2);
				SMG_A = 1;
			  SMG_B = 0;
				SMG_C = 0;
				SMG_D = 0;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 1;
				SMG_DG = 0;
		}
		else
		{
				smg_choice(1);
				SMG_A = 1;
			  SMG_B = 1;
				SMG_C = 1;
				SMG_D = 0;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 0;
				SMG_DG = 0;
	
				smg_choice(2);
				SMG_A = 1;
				SMG_B = 1;
				SMG_C = 1;
				SMG_D = 1;
				SMG_E = 1;
				SMG_F = 1;
				SMG_G = 0;
				SMG_DG = 0;
		}
}
