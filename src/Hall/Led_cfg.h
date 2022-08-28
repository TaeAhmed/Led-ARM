#include "Common/Platform_Types.h"

#define ledType_GPIO 0
#define ledType_I2C 1

#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2
#define GPIO_PORT_D 3
#define GPIO_PORT_E 4
#define GPIO_PORT_F 5

/*Set ledType*/
#define ledType ledType_GPIO
/*end*/

#if (ledType == 0) 
struct GPIO_Led{
uint8_t port;
uint8_t pin;	
};
/*create GPIO leds*/
struct GPIO_Led led1 = {GPIO_PORT_F,1};
/*end*/
#endif
