#include "Mcal/GPIO.h"
#include "Mcal/Timer.h"
#include "Hall/Led.c"



int main(void) {
ledInit(led1);	
void (*CBK)(struct GPIO_Led) = &ledToggle;
Timer_setCBK(CBK,led1);
return 0; 
}
