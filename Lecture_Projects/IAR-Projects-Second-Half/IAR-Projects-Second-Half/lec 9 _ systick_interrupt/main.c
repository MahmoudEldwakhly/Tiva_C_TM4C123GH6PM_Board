// Systick & Timer0 Interrupts by Sherif Hammad December 2018
// Make Timer0 Interrupt priority 4 which is lower than Systick
// Timer0 Period Always : 32 Ticks and Delay call
// Systick 16000 Ticks = 1ms
// Rule: Higher priority interrupt preempts lower priority one


#include "tm4c123gh6pm.h"
#include <stdint.h>
void Portf_Init(void);
void SysTick_Init(void);

int
main(void) {
    Portf_Init();
    SysTick_Init();
    NVIC_ST_CTRL_R = 7;      /* enable SysTick interrupt, use system clock */ 
    // Enable interrupts to the processor.
    __asm("CPSIE  I");   
    while (1)
    {
    // Processor enters Sleep Mode to save Power instead of Looping
    // Once Interrupt happens, Processor goes directly into Run mode      
      __asm("      wfi\n");
    }
}
void
Mariam(void){
   int32_t i;
//    i = NVIC_ST_CTRL_R;
    GPIO_PORTF_DATA_R ^= 2;    /* toggle the red LED */
}
void SysTick_Init(void){
    /* Configure SysTick */
    NVIC_ST_RELOAD_R = 16000000;   /* reload with number of clocks per second 16000 ticks =1 ms*/
//    NVIC_ST_CTRL_R = 7;      /* enable SysTick interrupt, use system clock */   
}

void Portf_Init(void){
	   /* enable clock to GPIOF at clock gating control register */
    SYSCTL_RCGCGPIO_R |= 0x20;
    /* enable the GPIO pins for the LED (PF3, 2, 1) as output */
    GPIO_PORTF_DIR_R = 0x0e;
	  GPIO_PORTF_AFSEL_R &= ~0x0E;     // disable alt funct on PF3-1
    /* enable the GPIO pins for digital function */
    GPIO_PORTF_DEN_R = 0x0e;    
}



