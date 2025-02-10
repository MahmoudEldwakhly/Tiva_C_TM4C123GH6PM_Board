int main() {
  *((unsigned int *)0x400FE608U) = 0x20U;
  *((unsigned int *)0x40025400U) = 0x0EU;
  *((unsigned int *)0x4002551CU) = 0x0EU;
  
  while (1) {
    int counter1 = 0;
    int volatile counter = 0;
    
    *((unsigned int *)0x400253FCU) = 0x02U;
    while (counter < 1000000) {
      ++counter;
    }
    
    *((unsigned int *)0x400253FCU) = 0x00U;
    while (counter1 < 1000000) {
      ++counter1;
    }
    
  }
  //return 0;
}
