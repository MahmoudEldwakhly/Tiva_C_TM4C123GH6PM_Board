#include "LED.h"

int main(void) {
    LED_Init('F', Pin1); // Initialize LED on PF1

    while (1) {
        LED_Blink('F', Pin1, 1000); // blink LED on PF1 for 1000ms
    }
}
