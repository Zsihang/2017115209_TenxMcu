#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------
// base 1ms
#define D_5ms 5
#define D_1000ms 1000

// Globle Var -----------------------------------------
#ifdef __main_c
uint8_t ledcom_State;
modeValue;

#else
extern uint8_t ledcom_State;
extern int modeValue;

#endif

// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void TimeProcess();
void TaskSetting();
void TaskProcess();
//void DisplayProcess();
void Delay(uint16_t time);
#endif
