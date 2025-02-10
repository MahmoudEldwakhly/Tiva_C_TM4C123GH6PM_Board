#include "tm4c123gh6pm.h"
#include "SysTick.h"

int main(void) {
    // Enable clock for PORTF
    SYSCTL_RCGCGPIO_R |= 0x20; 
    GPIO_PORTF_DIR_R |= 0x02;          // Set PF1 as output
    GPIO_PORTF_DEN_R |= 0x02;          // Enable digital function for PF1

    // Initialize SysTick Timer for 1-second delay (16 MHz clock)
    SysTick_Init(16000000);

    while (1) {
        if (SysTick_Is_Time_Out()) {
            GPIO_PORTF_DATA_R ^= 0x02; // Toggle LED
            NVIC_ST_CURRENT_R = 0;    // Clear COUNT flag
        }
    }
}
