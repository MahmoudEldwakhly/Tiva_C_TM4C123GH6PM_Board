#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "DIO.h"
#include "SysTick.h"

// LED state definitions
#define LED_ON  1
#define LED_OFF 0

// Function prototypes
void LED_Init(char port, uint8_t pins);
void LED_On(char port, uint8_t pins);
void LED_Off(char port, uint8_t pins);
void LED_Toggle(char port, uint8_t pins);
void LED_Blink(char port, uint8_t pin, uint32_t delayMs);

#endif // LED_H
