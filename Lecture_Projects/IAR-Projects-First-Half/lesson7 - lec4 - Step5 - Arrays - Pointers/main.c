#include "tm4c123gh6pm.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main() {
    SYSCTL_RCGCGPIO_R |= (1U << 5);  /* enable clock for GPIOF */
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);

    GPIO_PORTF_DATA_R |= LED_BLUE;
    while (1) {
        *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;

        int volatile counter[2] = {0,0};
        while (counter[0] < 1000000) {  // delay loop
            ++counter[0];
        }

        GPIO_PORTF_DATA_R &= ~LED_RED;
        while (*(counter + 1) < 1000000) {  // delay loop
            ++(*(counter + 1));
        }
    }
    //return 0;
}
