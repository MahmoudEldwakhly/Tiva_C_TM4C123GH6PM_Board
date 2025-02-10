#include "tm4c123gh6pm.h"

//colors (8 colors)

#define DARK (0U)
#define RED (1U <<1)
#define BLUE (1U <<2)
#define GREEN (1U <<3)
#define YELLOW (1U<<1) | (1U <<3)
#define SKYBLUE (1U <<2) | (1U <<3)
#define PINK (1U <<1) | (1U <<2)
#define WHITE (1U <<1) | (1U <<2) |(1U <<3)

//array that holds all colors 
int color [8] = {DARK, RED, BLUE, GREEN, YELLOW, SKYBLUE, PINK, WHITE};

//counter 
int counter = 0;

// a function to apply delay in ms 
void delay(int ms)
{
  int i, j;
  for(i = 0; i<500; i++)
  {
    for(j=0; j<3180; j++);
  }
}

// a function to initialize port f
void init_PF1(void)
{
  //enable clock gating system for  port f 
  SYSCTL_RCGCGPIO_R = 0x20;
  
  //to be able to modify pfo comit register and lock (unlock first)
  GPIO_PORTF_LOCK_R |= 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0x1F;
  
  // set direction as output (3 leds) and input for (2 switches)
  GPIO_PORTF_DIR_R = 0x0E;
  
  // digital enable port f  
  GPIO_PORTF_DEN_R = 0x1F;   
  
  //pull up resitors for switches 
  GPIO_PORTF_PUR_R  |= (1U<<4) | (1U); 
}

int main()
{
  init_PF1();
  while(1)
  {
    //check on sw1 if pressed 
    if( (( GPIO_PORTF_DATA_R & (1<<4) ) == 0) && (( GPIO_PORTF_DATA_R & (1<<0) ) != 0))
    {
      delay(1000);
      if (counter ==7)
      {
        counter = 0;
      }
      counter++;
      
      GPIO_PORTF_DATA_R = color[counter];
    }
    
    //check on sw2 if pressed  
    else if(( ( GPIO_PORTF_DATA_R & (1<<0) ) == 0) && (( GPIO_PORTF_DATA_R & (1<<4) ) != 0))
    {
      delay(1000);
      if (counter ==0)
      {
        counter = 7;
      }
      counter--;
      
      GPIO_PORTF_DATA_R = color[counter];
    }
    
    else if ((( GPIO_PORTF_DATA_R & (1<<4) ) == 0) && (( GPIO_PORTF_DATA_R & (1<<0) ) == 0))
    {
      GPIO_PORTF_DATA_R = WHITE;
    }
    
  }
  return 0;
}

