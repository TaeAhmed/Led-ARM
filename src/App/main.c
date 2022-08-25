#include "Mcal/GPIO.h"
#include "Mcal/Timer.h"
#include "Hall/Led.c"
int main(void) {
ledInit(led1);	

ledOn(led1); 	
ledOff(led1);

return 0; 
}
