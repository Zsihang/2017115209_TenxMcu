#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  F_clearWDT();//清除看门狗
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  
	// IO 模式初始化
  //P1MODL = 0xa8;
  //P1MODH = 0xaa;
	P1MODH = 0x2a;
  P3MODH = 0x28;
  P1MODL = 0x8a;
  P3MODL = 0x84;

  // IO 状态初始化
 
  // T2 初始化
  TH2 = (65536 - 922) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 922) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1;
}
//=============================================================================
void VarsInit() {}
