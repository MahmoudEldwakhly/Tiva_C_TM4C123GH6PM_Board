/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the TivaC BUZZER driver
 *
 * Author: MCTA Team 5 
 *
 *******************************************************************************/

#include "Buzzer.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Initializes the buzzer pin direction & turns off the buzzer */

void Buzzer_init(void)
{
    //Enable Port F
    SysCtlPeripheralEnable(BUZZER_ENABLE_PORT);
    
    //Setting Direction of Buzzer Pin
    GPIOPinTypeGPIOOutput(BUZZER_PORT, BUZZER_PIN);
    
    //Make Sure Buzzer is turned off
    GPIOPinWrite(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);
}

/*Activates the buzzer*/
void Buzzer_on(void)
{
	/*Uses GPIO to turn on Buzzer*/
	GPIOPinWrite(BUZZER_PORT,BUZZER_PIN,LOGIC_HIGH);
}

void Buzzer_off(void)
{
  	GPIOPinWrite(BUZZER_PORT,BUZZER_PIN,LOGIC_LOW);

}






