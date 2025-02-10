/******************************************************************************
 *
 * Module: LIMIT_SWITCH
 *
 * File Name: Limit_Switch.h
 *
 * Description: header file for the TivaC Limit_Switch driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef LIMIT_SWITCH_H_
#define LIMIT_SWITCH_H_

#include "std_types.h"
#include "inc/hw_memmap.h" //Regiters Memory Map in Tivaware
#include "driverlib/gpio.h" //GPIO APIs Defines & Macros in Tivaware
#include "driverlib/sysctl.h" //Sysctl Registers in TIvaware

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Limit Switch HW Ports and Pins ID */

#define Limit_Switch_Port              GPIO_PORTF_BASE
#define Limit_Switch_PIN               GPIO_PIN_2
#define LIMIT_SWITCH_ENABLE_PORT       SYSCTL_PERIPH_GPIOF 
   
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the limit switch pin directions*/

void LimitSwitch_init(void);

/*Gets status of limit switch if pressed or not*/

uint32 LimitSwitch_get_status(void);


#endif /* LIMIT_SWITCH_H_*/