#include <stdint.h>
#include <stdbool.h>

#define SYSCTL_RCGCGPIO  (*(volatile uint32_t *)0x400FE608)
#define SYSCTL_PRGPIO    (*(volatile uint32_t *)0x400FEA08)
#define GPIO_PORTF_DATA  (*(volatile uint32_t *)0x400253FC)
#define GPIO_PORTF_DIR   (*(volatile uint32_t *)0x40025400)
#define GPIO_PORTF_DEN   (*(volatile uint32_t *)0x4002551C)
#define GPIO_PORTF_PUR   (*(volatile uint32_t *)0x40025510)
#define GPIO_PORTF_LOCK  (*(volatile uint32_t *)0x40025520)
#define GPIO_PORTF_CR    (*(volatile uint32_t *)0x40025524)

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define SWITCH1   (1U << 4)
#define SWITCH2   (1U << 0)

void Delay(uint32_t time) {
    while (time--) {
        for (volatile int i = 0; i < 1000; i++) { }
    }
}

typedef enum {
    RED,
    BLUE,
    GREEN
} LEDColor;

void setLED(LEDColor color) {
    GPIO_PORTF_DATA &= ~(LED_RED | LED_BLUE | LED_GREEN);
    switch (color) {
        case RED:
            GPIO_PORTF_DATA |= LED_RED;
            break;
        case BLUE:
            GPIO_PORTF_DATA |= LED_BLUE;
            break;
        case GREEN:
            GPIO_PORTF_DATA |= LED_GREEN;
            break;
    }
}

int main(void) {
    SYSCTL_RCGCGPIO |= (1U << 5); 
    while ((SYSCTL_PRGPIO & (1U << 5)) == 0) {}

    GPIO_PORTF_LOCK = 0x4C4F434B;
    GPIO_PORTF_CR |= SWITCH2;

    GPIO_PORTF_DIR |= (LED_RED | LED_BLUE | LED_GREEN);    
    GPIO_PORTF_DIR &= ~(SWITCH1 | SWITCH2);   
    GPIO_PORTF_DEN |= (LED_RED | LED_BLUE | LED_GREEN | SWITCH1 | SWITCH2); 
    GPIO_PORTF_PUR |= (SWITCH1 | SWITCH2);    

    LEDColor currentColor = RED;

    while (1) {
        bool currentSW1State = (GPIO_PORTF_DATA & SWITCH1) == 0;
        bool currentSW2State = (GPIO_PORTF_DATA & SWITCH2) == 0;

        if (currentSW1State) { 
            currentColor = (currentColor == RED) ? BLUE : (currentColor == BLUE) ? GREEN : RED;
            setLED(currentColor);
            Delay(500); 
        }

        if (currentSW2State) {
            currentColor = (currentColor == GREEN) ? BLUE : (currentColor == BLUE) ? RED : GREEN;
            setLED(currentColor);
            Delay(500); 
        }

        Delay(50); 
    }
}
