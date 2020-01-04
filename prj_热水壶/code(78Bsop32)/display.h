#ifndef __display_h
#define __display_h
// Hal: exp: #define P_ledcom P10 -----------------
#define P_ledcom P1_0
#define P_led1 P1_4
#define P_led2 P1_2

// Const: exp: #define D_data 1 ----------------
#define D_ledcom_Off 1  //高电平灭
#define D_ledcom_On 0 //低电平亮
// Globle Var -----------------------------------------
#ifdef __display_c

#else

#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledcom_On() P_ledcom = D_ledcom_On         
#define F_ledcom_Off() P_ledcom = D_ledcom_Off      //ledcom初始值
#define F_ledcom_Neg() P_ledcom = ~P_ledcom
// Function ------------------------------------

#endif