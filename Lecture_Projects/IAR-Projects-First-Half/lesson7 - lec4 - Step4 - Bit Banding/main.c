#include "tm4c123gh6pm.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

int main() {
  SYSCTL_RCGCGPIO_R |= (1U << 5);  /* enable clock for GPIOF */
  //    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
  GPIO_PORTF_DIR_R= 0x7E;
  GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
  
  //   GPIO_PORTF_DATA_R |= LED_RED;
  //        *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;   
  while (1) {
    GPIO_PORTF_DATA_R |= 0x2;
    //     *((unsigned long volatile *)(0x40025008))=0x0;
    //       *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;
    
    int volatile counter;
    counter = 0;
    while (counter < 1000000) {  // delay loop
      ++counter;
    }
    //       *((unsigned long volatile *)(0x40025000 + (LED_RED << 2))) = ~LED_RED;
    //        GPIO_PORTF_DATA_R &= ~LED_BLUE;
    GPIO_PORTF_DATA_R &= 0xFD;
    counter = 0;
    while (counter < 1000000) {  // delay loop
      ++counter;
    }
    
  }
  //return 0;
}
