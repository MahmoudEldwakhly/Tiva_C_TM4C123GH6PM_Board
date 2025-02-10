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
#define SWITCH2   (1U << 0)

void Delay(uint32_t time) {
    while (time--) {
        for (volatile int i = 0; i < 1000; i++) { }
    }
}

int main(void) {
    SYSCTL_RCGCGPIO |= (1U << 5); 
    while (((SYSCTL_PRGPIO >> 5) & 1)  == 0) {}
    
    GPIO_PORTF_LOCK = 0x4C4F434B;
    GPIO_PORTF_CR |= SWITCH2;

    GPIO_PORTF_DIR |= LED_RED;    
    GPIO_PORTF_DIR &= ~SWITCH2;
    GPIO_PORTF_DEN |= (LED_RED | SWITCH2);
    GPIO_PORTF_PUR |= SWITCH2;

    while (1) {
        bool currentState = !(((GPIO_PORTF_DATA >> 0)) & 1); 

        if (currentState) { 
            GPIO_PORTF_DATA ^= LED_RED;
	    Delay(500);
        }
        Delay(50); 
    }
}

