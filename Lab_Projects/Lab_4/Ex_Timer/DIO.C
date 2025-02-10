// DIO.C 


#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "common_macros.h" 

void DIO_init(uint32 port_num, uint32 pin_num, DIO_PinDirectionType direction, DIO_PortDirectionType direction2, DIO_PINORPORT num)
{
  if (num == PIN)
  {
    if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
    {
      /*Don't do anything*/
    }
    else
    {
      switch(port_num)
      {
        SYSCTL_SCGCGPIO_R |= (1U << port_num);
        while(((SYSCTL_PRGPIO_R >> (port_num))& 1)==0){}
      case PORTA_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTA_DEN_R,pin_num);
          SET_BIT(GPIO_PORTA_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTA_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num);
        }
        break;
      case PORTB_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTB_DEN_R,pin_num);
          SET_BIT(GPIO_PORTB_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTB_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
        }
        break;
      case PORTC_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTC_DEN_R,pin_num);
          SET_BIT(GPIO_PORTC_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTC_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
        }
        break;
      case PORTD_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTD_DEN_R,pin_num);
          SET_BIT(GPIO_PORTD_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTD_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
        }
        break;
      case PORTE_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTE_DEN_R,pin_num);
          SET_BIT(GPIO_PORTE_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTE_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
        }
        break;
      case PORTF_ID:
        if(direction == PIN_OUTPUT)
        {
          SET_BIT(GPIO_PORTF_DEN_R,pin_num);
          SET_BIT(GPIO_PORTF_DIR_R,pin_num);
        }
        else
        {
          CLEAR_BIT(GPIO_PORTF_DEN_R,pin_num);
          CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);
        }
        break;
      }
    }
  }
  else if(port_num >= NUM_OF_PORTS)
  {
    /*Don't do anything*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      GPIO_PORTA_DEN_R= 0xFF;
      GPIO_PORTA_DIR_R = direction2;
      break;
    case PORTB_ID:
      GPIO_PORTB_DEN_R= 0xFF;
      GPIO_PORTB_DIR_R = direction2;
      break;
    case PORTC_ID:
      GPIO_PORTC_DEN_R= 0xFF;
      GPIO_PORTC_DIR_R = direction2;
      break;
    case PORTD_ID:
      GPIO_PORTD_DEN_R= 0xFF;
      GPIO_PORTD_DIR_R = direction2;
      break;
    case PORTE_ID:
      GPIO_PORTE_DEN_R= 0xFF;
      GPIO_PORTE_DIR_R = direction2;
      break;
    case PORTF_ID:
      GPIO_PORTF_DEN_R= 0xFF;
      GPIO_PORTF_DIR_R = direction2;
      break;
    }
  }
}

void DIO_writePin(uint32 port_num, uint32 pin_num, uint32 value)
{
  
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
    /*Don't do anything*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTA_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTA_DATA_R,pin_num);
      }
      break;
    case PORTB_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTB_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTB_DATA_R,pin_num);
      }
      break;
    case PORTC_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTC_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTC_DATA_R,pin_num);
      }
      break;
    case PORTD_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTD_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTD_DATA_R,pin_num);
      }
      break;
    case PORTE_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTE_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTE_DATA_R,pin_num);
      }
      break;
    case PORTF_ID:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTF_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTF_DATA_R,pin_num);
      }
      break;
    }
  }
}

uint32 DIO_readPin(uint32 port_num, uint32 pin_num)
{
  uint32 pin_value = LOGIC_LOW;
  
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
    /*Don't do anything*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      if(BIT_IS_SET(GPIO_PORTA_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    case PORTB_ID:
      if(BIT_IS_SET(GPIO_PORTB_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    case PORTC_ID:
      if(BIT_IS_SET(GPIO_PORTC_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    case PORTD_ID:
      if(BIT_IS_SET(GPIO_PORTD_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    case PORTE_ID:
      if(BIT_IS_SET(GPIO_PORTE_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    case PORTF_ID:
      if(BIT_IS_SET(GPIO_PORTF_DATA_R,pin_num))
      {
        pin_value = LOGIC_HIGH;
      }
      else
      {
        pin_value = LOGIC_LOW;
      }
      break;
    }
    
  }
  
  return pin_value;
}

void DIO_writePort(uint32 port_num, uint32 value)
{
  
  if(port_num >= NUM_OF_PORTS)
  {
    /*Don't do anything*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      GPIO_PORTA_DATA_R = value;
      break;
    case PORTB_ID:
      GPIO_PORTB_DATA_R = value;
      break;
    case PORTC_ID:
      GPIO_PORTC_DATA_R = value;
      break;
    case PORTD_ID:
      GPIO_PORTD_DATA_R = value;
      break;
    case PORTE_ID:
      GPIO_PORTE_DATA_R = value;
      break;
    case PORTF_ID:
      GPIO_PORTF_DATA_R = value;
      break;
    }
  }
}

uint32 DIO_readPort(uint32 port_num)
{
  uint32 value = LOGIC_LOW;
  
  if(port_num >= NUM_OF_PORTS)
  {
    /*Don't do anything*/
  }
  else
  {
    switch(port_num)
    {
    case PORTA_ID:
      value = GPIO_PORTA_DATA_R;
      break;
    case PORTB_ID:
      value = GPIO_PORTB_DATA_R;
      break;
    case PORTC_ID:
      value = GPIO_PORTC_DATA_R;
      break;
    case PORTD_ID:
      value = GPIO_PORTD_DATA_R;
      break;
    case PORTE_ID:
      value = GPIO_PORTE_DATA_R;
      break;
    case PORTF_ID:
      value = GPIO_PORTF_DATA_R;
      break;
    }
  }
  
  return value;
}
