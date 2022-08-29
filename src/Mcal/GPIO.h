#include "Common/Platform_Types.h"

extern void GPIO_WriteChannel(uint8_t port, uint8_t pin, boolean state);
extern boolean GPIO_ReadChannel(uint8_t port, uint8_t pin);
extern void GPIO_InitChannel(uint8_t port, uint8_t pin);
extern void GPIO_ToggleChannel(uint8_t port, uint8_t pin);
extern void GPIO_DirChannel(uint8_t port, uint8_t pin,boolean);
