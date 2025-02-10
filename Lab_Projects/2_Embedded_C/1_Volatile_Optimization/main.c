#include <stdint.h>

int main(void)
{
  volatile uint8_t data1;
  volatile uint8_t data2;
  
  data1 = 50;
  
  data2 = data1;
  
  data2 = data1;
  
  for(;;);
}
