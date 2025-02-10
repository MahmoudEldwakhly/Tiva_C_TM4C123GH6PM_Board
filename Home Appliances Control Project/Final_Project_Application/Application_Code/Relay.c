/******************************************************************************
 *
 * Module: RELAY
 *
 * File Name: Relay.c
 *
 * Description: source file for the TivaC Relay driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#include "Relay.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 ***********#include "inc/hw_memmap.h"
#include "driverlib/debug.h"********************************************************************/

/* Initializes the buzzer pin direction & turns off the buzzer */

void Relay_init(void)
{
    //Enable Relay Port
    SysCtlPeripheralEnable(RELAY_ENABLE_PORT);
    
    //Setting Direction of Relay 1 Pin
    GPIOPinTypeGPIOOutput(RELAY_1_PORT, RELAY_1_PIN);
    
    //Setting Direction of Relay 2 Pin
    GPIOPinTypeGPIOOutput(RELAY_2_PORT, RELAY_2_PIN);
    
    //Turning off Both Relays
    GPIOPinWrite(RELAY_1_PORT,RELAY_1_PIN,LOGIC_LOW);
    GPIOPinWrite(RELAY_2_PORT,RELAY_2_PIN,LOGIC_LOW);
}


/*Activates desired relay*/

void Relay_on(char Relay_ID)
{
  if (Relay_ID==RELAY_1_PIN)
  {
    /*Uses GPIO to turn on Relay*/
    GPIOPinWrite(RELAY_1_PORT,RELAY_1_PIN,LOGIC_HIGH);
  }
  else if  (Relay_ID==RELAY_2_PIN)
  {
   GPIOPinWrite(RELAY_2_PORT,RELAY_2_PIN,LOGIC_HIGH);
  }
}
void Relay_off(char Relay_ID)
{
  if (Relay_ID==RELAY_1_PIN)
  {
    /*Uses GPIO to turn off Relay*/
    GPIOPinWrite(RELAY_1_PORT,RELAY_1_PIN,LOGIC_LOW);
  }
  else if  (Relay_ID==RELAY_2_PIN)
  {
   GPIOPinWrite(RELAY_2_PORT,RELAY_2_PIN,LOGIC_LOW);
  }
}


