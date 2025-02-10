#include "tm4c123gh6pm.h"
void Timer0_Init(void);
void timer0A_delayMs(int ttime);

int main() {
    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
/* Configure Timer0 */
    Timer0_Init();
    
    while (1) {
        GPIO_PORTF_DATA_R = 0x08U;
        timer0A_delayMs(100);     /* Timer A msec delay */
        GPIO_PORTF_DATA_R = 0x00U;
        timer0A_delayMs(100);     /* Timer A msec delay */
    }
}
void
Timer0_Init(void){
    SYSCTL_RCGCTIMER_R |= 0x01;
    TIMER0_CTL_R = 0x0;            /* disable Timer before initialization */
    TIMER0_CFG_R = 0x0;         /* 32-bit individual Timer only works with prescaler*/
    TIMER0_TAMR_R = 0x02;        /* Periodic down-counter only works in simulation */
    TIMER0_CTL_R |= 0x03;        /* enable Timer A after initialization*/  
}
void
timer0A_delayMs(int ttime)
{
    TIMER0_CTL_R = 0x0;            /* disable Timer before initialization */
    TIMER0_TAILR_R = 16000 * ttime - 1;  /* Timer A interval load value register*/
//    TIMER0_TAILR_R =0xfF;
    TIMER0_TAPR_R = 0x0;     /* TimerA Prescaler 16MHz/250=64000Hz */
    TIMER0_ICR_R = 0x01;          /* clear the TimerA timeout flag*/
    TIMER0_CTL_R |= 0x03;        /* enable Timer A after initialization*/
    while ((TIMER0_RIS_R & 0x1) == 0) ;  /* wait for TimerA timeout flag to set*/
}