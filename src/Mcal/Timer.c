#include "Common/Mcu_Hw.h"
#include "Timer.h"
#include "Timer_cfg.h"

extern SystemCoreClock;

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

static void(*CBK)(int);
/*--*/

void SysTick_SetCBK(void(*cbk)(int)){
CBK=cbk;
}

void SysTick_Init(){
	Time2Tick(onTime_sec, onTime_ms, onTime_us,    &reloadsOn, &remTicksOn);
	Time2Tick(offTime_sec, offTime_ms, offTime_us,    &reloadsOff, &remTicksOff);
	start_Timer(12);
}

void SysTick_Handler(){
	stop_Timer();
	if(State == 0){
		if(reloads <= 0){
			if(remTicks <= 0){
				/*Case 1 of 6 --after reset--*/
				reloads = reloadsOn;
				remTicks = remTicksOn;
				//TODO: toggle led
				State = 1;
				if(reloads>0){
					start_Timer(0xFFFFFF);
					reloads--;
				}
				if(reloads <= 0){
					start_Timer(remTicks);
					remTicks=0;	
				}
			}
			if(remTicks > 0){
				//timer rel = remticks
				//remticks =0
				//start timer
 			}
		}
		if(reloads > 0){
			//reloads--
			//timer rel = 0xffffff
			//start timer
		}
	} 
	
	if(State == 1){
		if(reloads <= 0){
			if(remTicks <= 0){
				//ready timer
				//toggle led
				//start timer
			}
			if(remTicks > 0){
				//timer rel = remticks
				//remticks =0
				//start timer
 			}
		}
		if(reloads > 0){
			//reloads--
			//timer rel = 0xffffff
			//start timer
		}
	}
	
}
/*local functions*/
static void Time2Tick(uint16_t sec,uint16_t ms,uint16_t us,    uint8_t* reloads,uint32_t* remTicks){
uint8_t ticks_per_us = (uint8_t)(SystemCoreClock/1000000);	
uint32_t ticks = (sec*1000000 + ms*1000 + us)*ticks_per_us ;
*reloads	= (uint8_t)(ticks / 0xFFFFFF);
*remTicks = ticks % 0xFFFFFF; 	
}

static void start_Timer(uint32_t ticks){
	STRELOAD.R = ticks;
	STCURRENT.R =0;
	STCTRL.R |= 0x1;
}
static void stop_Timer(){
	STCTRL.R &= ~(uint32_t)(1);
}
/*--*/
