#include "tm4c123gh6pm.h"
void Timer0_Init(void);
void timer0A_delayMs(void);

int main() {
    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
/* Configure Timer0 */
    Timer0_Init();
    
    while (1) {
        GPIO_PORTF_DATA_R = 0x08U;
        timer0A_delayMs();     
        GPIO_PORTF_DATA_R = 0x00U;
        timer0A_delayMs();    
    }
}
void
Timer0_Init(void){
    SYSCTL_RCGCTIMER_R |= 0x01;
    TIMER0_CTL_R = 0x0;            
    TIMER0_CFG_R = 0x4;       
    TIMER0_TAMR_R = 0x12;        
    TIMER0_CTL_R |= 0x03;       
}
void
timer0A_delayMs(void)
{
    TIMER0_CTL_R = 0x0;            
    TIMER0_TAILR_R =0x07;
    TIMER0_TAPR_R = 0x1;    
    TIMER0_ICR_R = 0x1;          
    TIMER0_CTL_R |= 0x03;        
    while ((TIMER0_RIS_R & 0x1) == 0) ;
}