#include "tm4c123gh6pm.h"
#include <stdint.h>

void SysTick_Init(uint32_t reloadValue) {
    NVIC_ST_CTRL_R = 0;               // Disable SysTick during setup
    NVIC_ST_RELOAD_R = reloadValue;   // Set the reload value
    NVIC_ST_CURRENT_R = 0;            // Clear the current value
    NVIC_ST_CTRL_R = 0x05;            // Enable SysTick with system clock, no interrupt
}

void SysTick_Wait(void) {
    while ((NVIC_ST_CTRL_R & 0x10000) == 0); // Wait for COUNT flag
    NVIC_ST_CURRENT_R = 0;                  // Clear the flag by writing to CURRENT
}

int main(void) {
    SYSCTL_RCGCGPIO_R |= 0x20;        // Enable clock for PORTF
    GPIO_PORTF_DIR_R |= 0x02;         // Set PF1 as output
    GPIO_PORTF_DEN_R |= 0x02;         // Enable digital function for PF1
    
    SysTick_Init(15999999);           // Configure SysTick for 1-second delay (16 MHz clock)

    while (1) {
        GPIO_PORTF_DATA_R ^= 0x02;   // Toggle LED
        SysTick_Wait();              // Wait for 1 second
    }
}
