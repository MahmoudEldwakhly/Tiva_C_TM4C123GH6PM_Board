#include "tm4c123gh6pm.h"
void Timer0_Init(void);
int Timer0A_periodCapture(void);
int period=0;
int main() {

/* Configure Timer0 */
    Timer0_Init();
    
    period = Timer0A_periodCapture();
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
    
    TIMER0_CTL_R = 0x0;            /* disable Timer before initialization */
    TIMER0_CFG_R = 0x4;         /* 16-bit timer mode */
    TIMER0_TAMR_R = 0x07;        /* up-count, edge-time, capture mode */
    TIMER0_TAILR_R = 0xCDEF;
    TIMER0_TAPR_R = 0xAB;
    TIMER0_CTL_R &= ~0x0C;        /* capture the rising edge */
    TIMER0_CTL_R |= 0x01;        /* enable Timer A after initialization*/  
        
}
/* This function captures two consecutive rising edges of a periodic signal 
from Timer Block 0 Timer A and returns
the time difference (the period of the signal). */
int
Timer0A_periodCapture(void)
{
    int volatile diff, lastEdge, thisEdge;
    
    /* capture the first rising edge */
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
    lastEdge = TIMER0_TAR_R;     /* save the timestamp */

    /* capture the second rising edge */
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
    thisEdge = TIMER0_TAR_R;     /* save the timestamp */
    diff=thisEdge - lastEdge;
    return (diff); /* return the time difference */
}
