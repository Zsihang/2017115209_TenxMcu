/*******LED灯点亮--LED灯的闪烁实验*******/
#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
      //对芯片进行系统初始化  
      SysInit();

      while (1) {
            //打开LED等并延时1000毫秒
            F_ledOn();
            Delay(1000);

            //关闭LED等并延时1000毫秒
            F_ledOff();
            Delay(1000);
      }
}
//=============================================================================
void Delay(uint16_t time) {
     uint16_t i, j;
     for (i = 0; i < time; i++) {
           for (j = 0; j < 1000; j++) {
              /* code */
             // F_turnOnWDT();
           }
     }
}
