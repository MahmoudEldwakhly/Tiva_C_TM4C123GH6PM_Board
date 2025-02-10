#include <stdint.h>

#define SYSCTL_RCGCGPIO  (*(volatile uint32_t *)0x400FE608)
#define SYSCTL_PRGPIO    (*(volatile uint32_t *)0x400FEA08)
#define GPIO_PORTF_DATA  (*(volatile uint32_t *)0x400253FC)
#define GPIO_PORTF_DIR   (*(volatile uint32_t *)0x40025400)
#define GPIO_PORTF_DEN   (*(volatile uint32_t *)0x4002551C)
#define GPIO_PORTF_PUR   (*(volatile uint32_t *)0x40025510)
#define GPIO_PORTF_LOCK  (*(volatile uint32_t *)0x40025520)
#define GPIO_PORTF_CR    (*(volatile uint32_t *)0x40025524)

int main()
{
  SYSCTL_RCGCGPIO |= (1<<5);
  
  while((SYSCTL_PRGPIO >> (5)) & 1 == 0){}
  GPIO_PORTF_DIR = 0XFF;
  //GPIO_PORTF_DEN |= (1<<1);
  
  while(1)
  {
    
  }
}
  