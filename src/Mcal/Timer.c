#include "common/Mcu_Hw.h"
#include "Timer_cfg.h"

extern SystemCoreClock;

static void Time2Tick(uint16_t sec,uint16_t ms,uint16_t us,    uint8_t* reloads,uint32_t* remTicks);

static uint8_t reloads;
static uint32_t remTicks;

void StsTick_Init(){
	
	STRELOAD.R = remTicks;
	STCURRENT.R =0;
	
}

void SysTick_Handler(){

}

static void Time2Tick(uint16_t sec,uint16_t ms,uint16_t us,    uint8_t* reloads,uint32_t* remTicks){
uint8_t ticks_per_us = (uint8_t)(SystemCoreClock/1000000);	
uint32_t ticks = (sec*1000000 + ms*1000 + us)*ticks_per_us;
*reloads	= (uint8_t)(ticks / 0xFFFFFF);
*remTicks = ticks % 0xFFFFFF; 	
}
