#include <stdint.h>
#include "tm4c123gh6pm.h"

#define RED_LED (1U << 1)  	// PF1 Red LED
#define BLUE_LED (1U << 2)  	// PF1 BLUE LED
#define SYS_CLOCK 16000000

void Timer0A_Handler(void) {
    TIMER0_ICR_R = TIMER_ICR_TATOCINT; // Clear timeout interrupt
    GPIO_PORTF_DATA_R |= RED_LED;     // Turn on Red LED
}

void setup(void) {
    // Enable GPIOF and Timer0
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)); // Wait for GPIOF
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R0)); // Wait for Timer0

    // Configure GPIOF for Red LED
    GPIO_PORTF_DIR_R |= RED_LED;
    GPIO_PORTF_DEN_R |= RED_LED;

    // Configure Timer0 for one-shot mode
    TIMER0_CTL_R &= ~TIMER_CTL_TAEN;       // Disable Timer0A during setup
    TIMER0_CFG_R = 0x0;                    // 32-bit timer mode
    TIMER0_TAMR_R = TIMER_TAMR_TAMR_1_SHOT;// One-shot mode
    TIMER0_TAILR_R = SYS_CLOCK - 1;        // Load value for 1-second delay
    TIMER0_IMR_R |= TIMER_IMR_TATOIM;      // Enable timeout interrupt
    NVIC_EN0_R = (1 << 19);                // Enable IRQ 19 in NVIC (Timer0A)
    TIMER0_CTL_R |= TIMER_CTL_TAEN;        // Enable Timer0A
}

int main(void) {
    setup();
    while (1) {

    }
}
