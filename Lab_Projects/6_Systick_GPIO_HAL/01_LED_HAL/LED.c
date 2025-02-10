#include "LED.h"

// Initialize LEDs
void LED_Init(char port, uint8_t pins) {
    dio_init(port, pins, Output); // Configure pins as output
}

// Turn on LEDs
void LED_On(char port, uint8_t pins) {
    dio_writeport(port, dio_readport(port) | pins); // Set bits corresponding to LEDs
}

// Turn off LEDs
void LED_Off(char port, uint8_t pins) {
    dio_writeport(port, dio_readport(port) & ~pins); // Clear bits corresponding to LEDs
}

// Toggle LEDs
void LED_Toggle(char port, uint8_t pins) {
    dio_writeport(port, dio_readport(port) ^ pins); // XOR to toggle bits
}

// Blink LED with a delay (blocking function)
void LED_Blink(char port, uint8_t pin, uint32_t delayMs) {
    LED_On(port, pin);
    SysTick_Init((delayMs * 16000) - 1); // Delay in milliseconds
    while (!SysTick_Is_Time_Out());
    LED_Off(port, pin);
    SysTick_Init((delayMs * 16000) - 1);
    while (!SysTick_Is_Time_Out());
}
