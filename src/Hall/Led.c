#include "Led_cfg.h"
#include "Mcal/GPIO.h"

#if (ledType == 0)
void ledOn(struct GPIO_Led led){	
GPIO_Write(led.port,led.segment,led.pin,1);
}
void ledOff(struct GPIO_Led led){
GPIO_Write(led.port,led.segment,led.pin,0);
}
void ledToggle(struct GPIO_Led led){
boolean state = GPIO_Read(led.port, led.pin);
state = !state;
GPIO_Write(led.port,led.segment,led.pin,state);	
}
void ledState(struct GPIO_Led led){

}

void ledInit(struct GPIO_Led led){

}
#endif