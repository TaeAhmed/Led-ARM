#include "Common/Platform_Types.h"
#include "Common/Mcu_Hw.h"
#include "Common/Bit_Math.h"
#include "GPIO.h"

#ifndef Port_Macro
#define Port_Macro
#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2
#define GPIO_PORT_D 3
#define GPIO_PORT_E 4
#define GPIO_PORT_F 5
#endif
/*Local vars*/
static boolean state =0;
/*--*/
/*Local function prototype*/
volatile static uint32_t* GPIO_GetPort_Data(uint8_t port);
static  void GPIO_Channel_Dir(volatile uint32_t *Dport, uint8_t pin, boolean direction);
static void GPIO_ClkEnable(uint8_t port);
static void GPIO_Channel_Den(volatile uint32_t *Dport, uint8_t pin);
static void GPIO_Unlock(volatile uint32_t *Dport);
/*--*/
/*API functions*/
void GPIO_WriteChannel(uint8_t port, uint8_t pin, boolean state){
if(state) SET_BIT_PER_BB(*GPIO_GetPort_Data(port),pin);
	else CLEAR_BIT_PER_BB(*GPIO_GetPort_Data(port),pin);
}
void GPIO_ToggleChannel(uint8_t port, uint8_t pin){
  if(!state) {
	SET_BIT_PER_BB(*GPIO_GetPort_Data(port),pin);
	state =!state;}
	else {
	CLEAR_BIT_PER_BB(*GPIO_GetPort_Data(port),pin);
	state=!state;}
}
boolean GPIO_ReadChannel(uint8_t port, uint8_t pin){
return BIT_IS_SET(*GPIO_GetPort_Data(port),pin);	
}


void GPIO_InitChannel(uint8_t port, uint8_t pin){
	GPIO_ClkEnable(port);
switch(port){
	case GPIO_PORT_A:
		GPIO_Channel_Den(&PORTA_DEN,pin);
		GPIO_Channel_Dir(&PORTA_DIR,pin,1);
		GPIO_Unlock(&PORTA_LOCK);
		break;
	case GPIO_PORT_B: 
		GPIO_Channel_Den(&PORTB_DEN,pin);
		GPIO_Channel_Dir(&PORTB_DIR,pin,1);
		GPIO_Unlock(&PORTB_LOCK);
		break;
	case GPIO_PORT_C:
		GPIO_Channel_Den(&PORTC_DEN,pin);
		GPIO_Channel_Dir(&PORTC_DIR,pin,1);
		GPIO_Unlock(&PORTC_LOCK);
		break;
	case GPIO_PORT_D:
		GPIO_Channel_Den(&PORTD_DEN,pin);
		GPIO_Channel_Dir(&PORTD_DIR,pin,1);
		GPIO_Unlock(&PORTD_LOCK);
		break;
	case GPIO_PORT_E:
		GPIO_Channel_Den(&PORTE_DEN,pin);
		GPIO_Channel_Dir(&PORTE_DIR,pin,1);	
		GPIO_Unlock(&PORTE_LOCK);
		break;
	case GPIO_PORT_F:
		GPIO_Channel_Den(&PORTF_DEN,pin);
		GPIO_Channel_Dir(&PORTF_DIR,pin,1);
		GPIO_Unlock(&PORTF_LOCK);
		break;
}
}
/*--*/
/*Local Functions*/
volatile static uint32_t* GPIO_GetPort_Data(uint8_t port){
	volatile uint32_t* DATA;
switch(port){
	case GPIO_PORT_A:
		DATA = &PORTA_DATA;	
		break;
	case GPIO_PORT_B: 
		DATA = &PORTB_DATA;		
		break;
	case GPIO_PORT_C:
		DATA = &PORTC_DATA;	
		break;
	case GPIO_PORT_D:
		DATA = &PORTD_DATA;	
		break;
	case GPIO_PORT_E:
		DATA = &PORTE_DATA;	
		break;
	case GPIO_PORT_F:
		DATA = &PORTF_DATA;	
		break;
	default:
		DATA = NULL_PTR;
		break;
}
return DATA;
}
/*Local functions*/
static void GPIO_ClkEnable(uint8_t port){
SYSCTL_RCGCGPIO |= (1<<port);
}
static void GPIO_Channel_Den(volatile uint32_t *Dport, uint8_t pin){
  *Dport |= (1<<pin);
}	
static void GPIO_Channel_Dir(volatile uint32_t *Dport, uint8_t pin, boolean direction){
	*Dport |= (direction << pin);
}
static void GPIO_Unlock(volatile uint32_t *Dport){
	*Dport = 0x4C4F434B;
}
/*--*/
