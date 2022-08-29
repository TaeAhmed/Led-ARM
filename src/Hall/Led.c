#include "Led_cfg.h"
#include "Led.h"
#include "Mcal/GPIO.h"

typedef struct GPIO_Led{
uint8_t port;
uint8_t pin;	
}GPIO_Led;
typedef struct I2C_Led{
uint32_t addr;
	/*etc*/
}I2C_Led;

static GPIO_Led leds[GPIO_Led_Count] = GPIO_Leds;

void DIO_ledsOn(){	
	int i=GPIO_Led_Count;
	for(i;i>0;i--){
		GPIO_WriteChannel(leds[i-1].port,leds[i-1].pin,1);
	}
}

void DIO_ledsOff(){
	int i=GPIO_Led_Count;
	for(i;i>0;i--){
		GPIO_WriteChannel(leds[i-1].port,leds[i-1].pin,0);
	}
}

void DIO_ledsToggle(){
	int i=GPIO_Led_Count;
	for(i;i>0;i--){
		GPIO_ToggleChannel(leds[i-1].port,leds[i-1].pin);
	}
}

void DIO_ledsInit(){
	int i=GPIO_Led_Count;
	for(i;i>0;i--){
		GPIO_DirChannel(leds[i-1].port,leds[i-1].pin,1);
	}
}
