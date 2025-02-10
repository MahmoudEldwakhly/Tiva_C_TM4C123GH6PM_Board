#include "tm4c123gh6pm.h"
void Timer0_Init(void);
int Timer0A_countCapture(void);

int main() {
int edgeCount;
/* Configure Timer0 */
    Timer0_Init();
    while(1){    
        edgeCount=Timer0A_countCapture();
    }
}
void
Timer0_Init(void){
    SYSCTL_RCGCGPIO_R = 0x20U;
    SYSCTL_RCGCTIMER_R |= 0x01;
    GPIO_PORTF_LOCK_R = 0x4C4F434B ; //Unlock the PORTF lock register 
    GPIO_PORTF_CR_R = 0x01F ; //Allow changes for my pins in GPIO_PORTF_CR_R
    GPIO_PORTF_DIR_R &= ~0x01;        /* make PF0 an input pin */
    GPIO_PORTF_DEN_R |= 0x01;         /* make PF0 as digital pin */
    GPIO_PORTF_AFSEL_R |= 0x01;       /* use PF0 alternate function */
    GPIO_PORTF_PCTL_R |= 0x00000007;  /* configure PF0 for T0CCP0 */  
    GPIO_PORTF_PUR_R |= 0x01;
    
    TIMER0_CTL_R &= ~1;            /* disable Timer0A before initialization */
    TIMER0_CFG_R = 0x4;            /* 16-bit timer mode */
    TIMER0_TAMR_R = 0x03;        /* Down-count, edge-count, capture mode */
    TIMER0_TAILR_R = 0x11;
//    TIMER0_TAPR_R = 0xAA;
    TIMER0_TAMATCHR_R = 0x05;     /* set the count limit */
    TIMER0_CTL_R &= ~0x0C;        /* capture the rising edge */
    TIMER0_CTL_R |= 0x01;         /* enable Timer A after initialization*/  
        
}
int Timer0A_countCapture(void)
{
    return TIMER0_TAR_R;
}

