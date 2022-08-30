#include "Common/Mcu_Hw.h"
#include "Common/Bit_Math.h"
#include "Timer.h"
#include "Timer_cfg.h"

/*Local function prototype*/
static void Time2Tick(uint16_t sec,uint16_t ms,uint16_t us,    uint8_t* reloads,uint32_t* remTicks);
static void start_Timer(uint32_t ticks);
static void stop_Timer(void);
/*--*/
/*Local vars*/
static uint8_t reloadsOn;
static uint32_t remTicksOn;
static uint8_t reloadsOff;
static uint32_t remTicksOff;
static uint8_t reloads =0;
static	uint32_t remTicks =0;

static boolean State = 0;
static uint8_t condition;

static void(*CBK)(void);
/*--*/
/*API functions*/
void SysTick_SetCBK(void(*cbk)(void)){
CBK=cbk;
}

void SysTick_Init(){
	Time2Tick(onTime_sec, onTime_ms, onTime_us,    &reloadsOn, &remTicksOn);
	Time2Tick(offTime_sec, offTime_ms, offTime_us,    &reloadsOff, &remTicksOff);
	start_Timer(12);
}
/*--*/
void SysTick_Handler(){
	stop_Timer();
	condition = (uint8_t)(State*4 + (reloads>0)*2 + (remTicks>0));
	switch(condition){
		case 0: 
			reloads = reloadsOn;
			remTicks = remTicksOn;
			(*CBK)();
			State = 1;
			if(reloads>0){
					start_Timer(0xFFFFFF);
					reloads--;
			}else{
					start_Timer(remTicks);
					remTicks=0;	
			}
			break;
		case 4:
			reloads = reloadsOff;
			remTicks = remTicksOff;
			(*CBK)();
			State = 0;
			if(reloads>0){
					start_Timer(0xFFFFFF);
					reloads--;
			}else{
					start_Timer(remTicks);
					remTicks=0;	
			}
			break;	
		case 1:
		case 5:	
			start_Timer(remTicks);
			remTicks=0;
			break;
		case 2:
		case 3:
		case 6:
		case 7:		
			start_Timer(0xFFFFFF);
			reloads--;
			break;
		default:
			start_Timer(16);
			break;
	}
}
/*local functions*/
static void Time2Tick(uint16_t sec,uint16_t ms,uint16_t us,    uint8_t* Reloads,uint32_t* RemTicks){
uint8_t ticks_per_us = (uint8_t)(Clock/1000000);	
uint32_t ticks = (sec*1000000 + ms*1000 + us)*ticks_per_us ;
*Reloads	= (uint8_t)(ticks / 0xFFFFFF);
*RemTicks = ticks % 0xFFFFFF; 	
}

static void start_Timer(uint32_t ticks){
	STRELOAD.R = ticks;
	STCURRENT.R =0;
	SET_BIT(STCTRL.R,2);
	SET_BIT(STCTRL.R,1);
	SET_BIT(STCTRL.R,0);
}
static void stop_Timer(){
	CLEAR_BIT(STCTRL.R,0);
}
/*--*/
