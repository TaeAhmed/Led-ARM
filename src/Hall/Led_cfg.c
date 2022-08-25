#include "Common/Platform_Types.h"
/* GPIO 0  I2C 1 */
#define ledType 0

enum GPIO_Ports {A,B,C,D,E,F};
enum GPIO_Port_Segment {APB,AHB};

#if (ledType == 0) 
struct GPIO_Led{
uint8_t port;
boolean segment;
uint8_t pin;	
};
static struct GPIO_Led led1 = {F,APB,1};
#endif
