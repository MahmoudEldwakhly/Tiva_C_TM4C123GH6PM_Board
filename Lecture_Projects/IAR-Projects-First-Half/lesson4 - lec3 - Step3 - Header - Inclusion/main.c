#include "tm4c123gh6pm.h"

int main() {
  
  SYSCTL_RCGCGPIO_R = 0x20U;
  GPIO_PORTF_DIR_R = 0x0EU;
  GPIO_PORTF_DEN_R = 0x0EU;
  GPIO_PORTF_PUR_R = 0x11;
  
  while (1) {
    int volatile x=0;
    x = GPIO_PORTF_DATA_R;
    GPIO_PORTF_DATA_R = 0x08U;
    
    int volatile counter = 0;
    while (counter < 1000000) {
      ++counter;
    }
    
    GPIO_PORTF_DATA_R = 0x00U;
    counter = 0;
    while (counter < 1000000) {
      ++counter;
    }
  }
  //return 0;
}
