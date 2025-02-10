/******************************************************************************
 *
 * Module: LIMIT_SWITCH
 *
 * File Name: Limit_Switch.c
 *
 * Description: source file for the TivaC Limit_Switch driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#include "Limit_Switch.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*Initializes the limit switch pin directions*/

void LimitSwitch_init(void)
{
    //Enable Limit Switch Port
    SysCtlPeripheralEnable(LIMIT_SWITCH_ENABLE_PORT);
    
    //Setting Direction of Limit Switch Pin
    GPIOPinTypeGPIOInput(Limit_Switch_Port, Limit_Switch_PIN);
}

/*Gets status of limit switch if pressed or not*/

uint32 LimitSwitch_get_status(void)
{
  return GPIOPinRead(Limit_Switch_Port,Limit_Switch_PIN);
}



