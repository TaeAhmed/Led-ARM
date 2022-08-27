#include "Common/Platform_Types.h"

#define ledType_GPIO 0
#define ledType_I2C 1
/*Set ledType*/
#define ledType ledType_GPIO
/*end*/
enum GPIO_Ports {A,B,C,D,E,F};
enum GPIO_Port_Segment {APB,AHB};

#if (ledType == 0) 
struct GPIO_Led{
uint8_t port;
boolean segment;
uint8_t pin;	
};
/*create GPIO leds*/
struct GPIO_Led led1 = {F,APB,1};
/*end*/
#endif
