#include "Common/Platform_Types.h"
#include "Common/Mcu_Hw.h"
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

volatile static uint32_t* GPIO_GetPort_Data(uint8_t port);
void GPIO_Channel_Dir(volatile uint32_t *Dport, uint8_t pin, boolean direction);
void GPIO_ClkEnable(uint8_t port);
void GPIO_Channel_Den(volatile uint32_t *Dport, uint8_t pin);

/*API functions*/
void GPIO_WriteChannel(uint8_t port, uint8_t pin, boolean state){
*GPIO_GetPort_Data(port) |= (state<<pin);
}
void GPIO_ToggleChannel(uint8_t port, uint8_t pin){
*GPIO_GetPort_Data(port) ^= (1<<pin);
}
boolean GPIO_ReadChannel(uint8_t port, uint8_t pin){
boolean state = 0;
state = (uint8_t)*GPIO_GetPort_Data(port) & (1<<pin);	
return state;	
}


void GPIO_InitChannel(uint8_t port, uint8_t pin){
	GPIO_ClkEnable(port);
switch(port){
	case GPIO_PORT_A:
		GPIO_Channel_Den(&PORTA_DEN,pin);
		GPIO_Channel_Dir(&PORTA_DIR,pin,1);
		break;
	case GPIO_PORT_B: 
		GPIO_Channel_Den(&PORTB_DEN,pin);
		GPIO_Channel_Dir(&PORTB_DIR,pin,1);
		break;
	case GPIO_PORT_C:
		GPIO_Channel_Den(&PORTC_DEN,pin);
		GPIO_Channel_Dir(&PORTC_DIR,pin,1);
		break;
	case GPIO_PORT_D:
		GPIO_Channel_Den(&PORTD_DEN,pin);
		GPIO_Channel_Dir(&PORTD_DIR,pin,1);
		break;
	case GPIO_PORT_E:
		GPIO_Channel_Den(&PORTE_DEN,pin);
		GPIO_Channel_Dir(&PORTE_DIR,pin,1);	
		break;
	case GPIO_PORT_F:
		GPIO_Channel_Den(&PORTF_DEN,pin);
		GPIO_Channel_Dir(&PORTF_DIR,pin,1);
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

void GPIO_ClkEnable(uint8_t port){
SYSCTL_RCGCGPIO |= (1<<port);
}
void GPIO_Channel_Den(volatile uint32_t *Dport, uint8_t pin){
  *Dport |= (1<<pin);
}	
void GPIO_Channel_Dir(volatile uint32_t *Dport, uint8_t pin, boolean direction){
	*Dport |= (direction << pin);
}
/*--*/
