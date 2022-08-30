#include "Mcal/Timer.h"
#include "Hall/Led.h"
 
int main(void) {
	SysTick_Init();
	DIO_ledsInit();
	SysTick_SetCBK(&DIO_ledsToggle);
while(1);
return 0; 
}
