#include "SysTick.h"
#include "Relay.h"

// Callback function for SysTick interrupt
void SysTick_Callback(void) {
    // Toggle the relay on Port F, Pin 1
    Relay_Toggle('F', Pin1); // Pin 1 corresponds to bit 1
}

int main(void) {
    // Initialize the relay on Port F, Pin 1
    Relay_Init('F', Pin1);

    // Initialize SysTick with interrupt mode and 1-second interval
    // Using a 16 MHz clock, 1 second corresponds to 16,000,000 cycles
    SysTick_InitInterrupt(16000000, SysTick_Callback);

    // Main loop
    while (1) {
        // Main loop remains empty as the SysTick interrupt handles relay toggling
    }
}
