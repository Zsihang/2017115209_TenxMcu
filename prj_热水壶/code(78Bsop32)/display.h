#ifndef __display_h
#define __display_h
// Hal: exp: #define P_ledcom P10 -----------------
//定义LED灯IO口
#define P_ledcom P1_0 
#define P_led1 P1_4
#define P_led2 P1_2

//定义数码管控制IO口
#define SMG_COM1 P1_1		//控制左数码管
#define SMG_COM2 P1_6		//控制右数码管

//定义数码管八个led的IO口
#define SMG_A P1_4
#define SMG_B P3_4
#define SMG_C P3_5
#define SMG_D P1_7
#define SMG_E P3_6
#define SMG_F P1_2
#define SMG_G P3_2
#define SMG_DG P1_3

// Const: exp: #define D_data 1 ----------------
#define D_ledcom_Off 1  //高电平灭
#define D_ledcom_On 0 	//低电平亮

//选择左、右数码管
#define SMG_L 1
#define SMG_R 2
// Globle Var -----------------------------------------
#ifdef __display_c
bit bflag0;
bit bflag;
#else
extern bit bflag0;
extern bit bflag;
#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledcom_On() P_ledcom = D_ledcom_On         
#define F_ledcom_Off() P_ledcom = D_ledcom_Off     
#define F_ledcom_Neg() P_ledcom = ~P_ledcom
// Function ------------------------------------
//LED灯
void LED1_and_LED2();
void LED1_ON();
void LED2_ON();
void LED2_OFF();

//数码管
void smg_init();
void smg_choice(uint8_t smgx);
void smg_display_num(uint8_t smgx,int num);
void smg_display_on_of(uint8_t On_or_Of);

#endif
