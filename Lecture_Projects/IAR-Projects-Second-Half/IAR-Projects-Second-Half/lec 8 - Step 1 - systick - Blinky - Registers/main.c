#include "tm4c123gh6pm.h"


int main() {
    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
/* Configure SysTick */
    NVIC_ST_RELOAD_R = 0xFF;   /* reload reg. with max value */
    NVIC_ST_CTRL_R = 5;         /* enable it, no interrupt, use system clock */
    
    while (1) {
        GPIO_PORTF_DATA_R = 0x08U;
	while ((NVIC_ST_CTRL_R & 0x10000) == 0);         /* if COUNT (D16 of CTRL reg.) flag is set : Reading COUNT FLAG will reset it back*/

        GPIO_PORTF_DATA_R = 0x00U;
	while ((NVIC_ST_CTRL_R & 0x10000) == 0);         /* if COUNT (D16 of CTRL reg.) flag is set : Reading COUNT FLAG will reset it back*/
    }
    //return 0;
}
