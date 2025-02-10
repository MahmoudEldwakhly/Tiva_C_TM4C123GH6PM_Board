#include "tm4c123gh6pm.h"

void delay(int count) {
    volatile int i;
    for (i = 0; i < count; i++);
}

int main(void) {
    // Step 1: Enable the clock for GPIO Port F
    SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock for Port F (bit 5)
    
    // Step 2: Set PF1 (red LED) as output
    GPIO_PORTF_DIR_R |= RED_LED; // Set PF1 as output
    GPIO_PORTF_DEN_R |= RED_LED; // Enable digital functionality for PF1

    while(1) {
        // Step 3: Toggle the red LED
        GPIO_PORTF_DATA_R ^= RED_LED; // Toggle the red LED
        
        // Step 4: Delay for a bit
        delay(1000000); // Adjust delay for blink rate
    }
    return 0;
}
