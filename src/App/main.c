#include "Mcal/GPIO.h"
#include "Mcal/Timer.h"
#include "Hall/Led.h"



int main(void) {
	SysTick_Init();
	SysTick_SetCBK(&ledToggle);

return 0; 
}
