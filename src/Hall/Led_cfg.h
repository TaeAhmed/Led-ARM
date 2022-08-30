#include "Common/Platform_Types.h"
#ifndef Port_Macro
#define Port_Macro
#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2
#define GPIO_PORT_D 3
#define GPIO_PORT_E 4
#define GPIO_PORT_F 5
#endif
/*select led count here*/
#define GPIO_Led_Count 1
#define I2C_Led_Count 0
/*code will do nothing with I2C leds ATM*/
/*end select*/

/*Enter GPIO_Leds in array of struct format*/
/*example:
    #define GPIO_Leds {{GPIO_PORT_F, 1},{GPIO_PORT_D,5},{..port,..pin}} where GPIO_Led_Count is array size   */
#define GPIO_Leds {{GPIO_PORT_A,6}}
#define I2C_Leds {}
/*end select*/


