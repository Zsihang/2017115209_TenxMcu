#define __main_c
#include "includeAll.h"

//=============================================================================
void main() {
  SysInit();
  VarsInit();
 
  F_turnOnWDT();	//使能看门狗

  while (1) {
    //喂狗
    F_clearWDT();   //清除看门狗
		GetKeys();
  if (D_keyValue1 == keyValue) {
    F_ledNeg();
  }
  keyValue = D_keyNull;
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