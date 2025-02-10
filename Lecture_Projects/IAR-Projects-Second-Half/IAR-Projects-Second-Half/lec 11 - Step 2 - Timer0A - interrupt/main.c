#include "tm4c123gh6pm.h"
void Timer0A_Init(void);


int main() {
    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
    // Enable interrupts to the processor.
    //
    __asm("CPSIE  I");
    //
    
/* Configure Timer0 */
    Timer0A_Init();
    
    while (1) {
    //
    // Processor enters Sleep Mode to save Power instead of Looping
    // Once Interrupt happens, Processor goes directly into Run mode
    //      
      __asm("      wfi\n");
    }
}

void Timer0A_Init(void){ 
  SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate TIMER0
  TIMER0_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
  TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = 0x000000FF;    // 4) reload value
 // TIMER0_TAPR_R = 0;            // 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
  TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
//  TIMER0_TAMATCHR_R = 0x07;
//  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<19;           // 9) enable IRQ 19 in NVIC
  TIMER0_CTL_R = 0x00000003;    // 10) enable TIMER0A
}

void
Timer0AIntHandler(void)
{
  {
    TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
  }
  // Toggling by XOR with ONE
       GPIO_PORTF_DATA_R ^=0x04;

}
