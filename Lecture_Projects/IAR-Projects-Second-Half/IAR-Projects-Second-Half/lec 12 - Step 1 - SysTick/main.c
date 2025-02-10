// Systick & Timer0 Interrupts by Sherif Hammad December 2018
// Merging Systick & Timer0 last projects as basline. Step by step debugging
// Timer0 Period Always : 32 Ticks. Start by Comment out Delay call
// Systick 16 Ticks : Very hard to see Timer0 serviced; Yet Running
// Rule: Both having same priority 0. If Happens togetehr >> IRQ lower number wins
// Rule: Both having same priority 0. No preemption between same priority interrupts
// Systick 160 Ticks : To see both Systick & Timer0 serviced; No preemtion
// Systick 160 Ticks with Delay call: To see both Systick & Timer0 serviced; No preemtion

#include "tm4c123gh6pm.h"
#include <stdint.h>

void Portf_Init(void);

int
main(void) {
    Portf_Init();
    NVIC_ST_RELOAD_R = 160;   /* reload with number of clocks per second 16 then 160 then 160 with Delay call*/
    NVIC_ST_CTRL_R = 7;      /* enable SysTick interrupt, use system clock */ 

    // Enable interrupts to the processor.
    //
    __asm("CPSIE  I");
    //
 //    __asm("CPSID  I");   
    while (1)
    {
    //
    // Processor enters Sleep Mode to save Power instead of Looping
    // Once Interrupt happens, Processor goes directly into Run mode
    //      
      __asm("      wfi\n");
    }
}
void
SysTick_Handler(void){
    int32_t i;
//    i = NVIC_ST_CTRL_R;
    GPIO_PORTF_DATA_R ^= 2;    /* toggle the red LED */
}

void Portf_Init(void){
	   /* enable clock to GPIOF at clock gating c
ontrol register */
    SYSCTL_RCGCGPIO_R |= 0x20;
    /* enable the GPIO pins for the LED (PF3, 2, 1) as output */
    GPIO_PORTF_DIR_R = 0x0e;
	  GPIO_PORTF_AFSEL_R &= ~0x0E;     // disable alt funct on PF3-1
    /* enable the GPIO pins for digital function */
    GPIO_PORTF_DEN_R = 0x0e;    
}


