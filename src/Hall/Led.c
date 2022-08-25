#include "Led_cfg.c"
#include "Mcal/GPIO.c"

#if (ledType == 0)
void ledOn(struct GPIO_Led led){	
GPIO_Write(led.port,led.segment,led.pin,1);
}
void ledOff(struct GPIO_Led led){
GPIO_Write(led.port,led.segment,led.pin,0);
}
void ledToggle(struct GPIO_Led led){
boolean state = GPIO_Read(led.port,led.segment,led.pin);
state = !state;
GPIO_Write(led.port,led.segment,led.pin,state);	
}

void ledInit(struct GPIO_Led led){

}
#endif