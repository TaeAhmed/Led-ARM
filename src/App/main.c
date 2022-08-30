#include "Mcal/Timer.h"
#include "Hall/Led.h"
 
int main(void) {
	DIO_ledsInit();
	SysTick_SetCBK(&DIO_ledsToggle);	
	SysTick_Init();
	
while(1);
return 0; 
}
