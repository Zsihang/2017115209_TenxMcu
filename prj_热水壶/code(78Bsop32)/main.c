#define __main_c
#include "includeAll.h"

//===============================main主函数====================================
void main() {
		modeValue = 1; //初始状态为1

		SysInit();				//芯片系统初始化
		VarsInit();
		F_turnOnWDT();    //使能看门狗

//=============================功能整合：热水壶煮水
		smg_init();		//初始化数码管	
	
//==========通电时
		Buzz_ON();		//蜂鸣器响声一次		
		LED1_ON();		//点亮LED1
		smg_display_on_of(0);		//显示of，表示热水壶关闭，未开始煮水
	
//==========开始煮水	
		while (1) {		
			F_clearWDT();	  //清除看门狗
			TimeProcess();	//时间处理，获取按键
			BoilWater();		//煮水
		}
}
//============================================================================

//==========================煮水按键功能函数
void BoilWater() {
		int i,m,n;
	
		if(Keyx == 1){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
					Buzz_ON();		//蜂鸣器响声一次		
					smg_display_num(2,0);		//右数码管显示0
					Delay(200);
					//加水，数码管从0跳到0.3，表示加水0.3L
					for(i=1;i<=3;i++){
						smg_display_num(1,0);
						smg_display_num(2,i);
					}
				}
			}
		}
		else if(Keyx == 2){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
					Buzz_ON();		//蜂鸣器响声一次		
					LED2_ON();		//点亮LED2
					smg_display_on_of(1);		//显示on，表示热水壶开启，开始煮水
				}
			}
		}			
		else if(Keyx == 3){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
					Buzz_ON();		//蜂鸣器响声一次		
					LED2_ON();		//点亮LED2
					//初始温度30，煮水逐渐加到99，表示水已经煮开
					for(m=3;m<=9;m++){
						for(n=0;n<=9;n++){
							smg_display_num(1,m);
							smg_display_num(2,n);
						}
					}
					//温度达到99，蜂鸣器常响且LED2闪烁提醒
					while(1){	
						Buzz_ON();
						Delay(100);						
						LED2_ON();
						Delay(1000);
						LED2_OFF();
						Delay(1000);
					}
				}
			}
		}
		else if(Keyx == 4){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
					Buzz_ON();		//蜂鸣器响声一次		
					LED1_ON();		//点亮LED1
					smg_display_on_of(0);		//显示of
				}
			}
		}
		else {
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
						modeValue = ~modeValue;			//改变状态
				}
			}
		}
}
//==========================================

//=============================实现LED灯点亮
//		//同时点亮LED1和LED2
//		LED1_and_LED2();
//	
//		//点亮LED1
//		LED1_ON();
//		
//		//点亮LED2
//		LED2_ON();
//==========================================
	
//=============================实现控制蜂鸣器	
//	while(1){	
//			Buzz_ON();
//	}
//===========================================

//=============================实现数码管显示
//		smg_init();		//初始化数码管
//		
//		//数码管显示，选择右数码管显示从0-9的数字
//		for(i=0;i<=9;i++){
//				smg_display_num(2,i);
//		}
//		
//		//显示of，表示热水壶关闭，未开始煮水
//		smg_display_num(SMG_OFF);
//	
//===========================================
	
//===============================实现按键控制
//		while (1) {		
//			F_clearWDT();	  //清除看门狗
//			TimeProcess();
//			TaskSetting();
//			//TaskProcess();
//			//DisplayProcess();	
//		}
//===========================================

//=============================================================================

//===========================定义时间处理函数==================================
//控制时钟
void TimeProcess() {
	static uint8_t timer5ms = 0;		//按键计时

  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
  }
	
  if (timer5ms >= 5) {
		timer5ms = 0;
		P1MODL = 0xa8;	//设置IO模式为上拉输入
		P1MODH = 0x2a;
    GetKeys();			//获取按键
  }
}
//=============================================================================

//=============================================================================
void TaskProcess() {}
//=============================================================================
	
//=============================定义按键控制函数================================
//===================任务：实现按键控制led亮灭和蜂鸣器开关===================//
void TaskSetting() {
		if (Keyx == 1){
			if(modeValue == 1) {
				//LED状态转换
				if(D_keyValue1 == keyValue1){
						Key1();		//按下KEY1,同时点亮LED1和LED2
				}
			}
		}
		else if(Keyx == 2){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
						Key2();		//按下KEY2,点亮LED1
				}
			}
		}			
		else if(Keyx == 3){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
						Key3();		//按下KEY3,点亮LED2
				}
			}
		}
		else if(Keyx == 4){
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
						Key4();		//按下KEY4，打开蜂鸣器
				}
			}
		}
		else {
			if(modeValue == 1) {
				if(D_keyValue1 == keyValue1){
						modeValue = ~modeValue;			//改变状态
				}
			}
		}
}
//=============================================================================

//=============================================================================
void DisplayProcess() {}
//=============================================================================

//===============================定义延时函数==================================
void Delay(uint16_t time) {
     uint16_t i, j;
     for (i = 0; i < time; i++) {
           for (j = 0; j < 1000; j++) {
              /* code */
             F_clearWDT();
           }
     }
}
//=============================================================================
