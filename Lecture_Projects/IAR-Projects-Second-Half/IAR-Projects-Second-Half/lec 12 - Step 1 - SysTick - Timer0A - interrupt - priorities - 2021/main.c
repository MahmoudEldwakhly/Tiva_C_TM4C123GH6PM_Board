// Systick & Timer0 Interrupts by Sherif Hammad September 2021

#include "tm4c123gh6pm.h"
#include <stdint.h>
void Timer0A_Init(void);
void Portf_Init(void);
void SysTick_Init(void);

int
main(void) {
    Portf_Init();
    SysTick_Init();
    Timer0A_Init();
    NVIC_ST_CTRL_R = 7;      /* enable SysTick interrupt, use system clock */ 
    TIMER0_CTL_R = 0x00000003;    // 10) enable TIMER0A


    // Enable interrupts to the processor.
    //
    __asm("CPSIE  I");
    //
    
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

void
Timer0AIntHandler(void){
    TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
    GPIO_PORTF_DATA_R ^= 0x04;    /* toggle the red LED */
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

void SysTick_Init(void){
    /* Configure SysTick */
    NVIC_ST_RELOAD_R = 16000;   /* reload with number of clocks per second 16 then 160 then 160 with Delay call*/
//    NVIC_ST_CTRL_R = 7;      /* enable SysTick interrupt, use system clock */   
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x80000000; // 8) priority 4
}

void Timer0A_Init(void){ 
  SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate TIMER0
  TIMER0_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
  TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = 160;    // 4) reload value 32
  TIMER0_TAPR_R = 0;            // 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
  TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<19;           // 9) enable IRQ 19 in NVIC
//  TIMER0_CTL_R = 0x00000003;    // 10) enable TIMER0A
}
