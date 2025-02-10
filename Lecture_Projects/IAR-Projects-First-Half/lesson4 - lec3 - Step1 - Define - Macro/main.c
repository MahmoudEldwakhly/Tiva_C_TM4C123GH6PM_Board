#define GPIO_DATA *((unsigned int *)0x400253FCU)
int main() {
  *((unsigned int *)0x400FE608U) = 0x20U;
  *((unsigned int *)0x40025400U) = 0x0EU;
  *((unsigned int *)0x4002551CU) = 0x0EU;
  
  while (1) {
    GPIO_DATA = 0x04U;
    
    int volatile counter = 0;
    while (counter < 1000000) {
      ++counter;
    }
    
    GPIO_DATA = 0x00U;
    counter = 0;
    while (counter < 1000000) {
      ++counter;
    }
    
  }
  //return 0;
}
