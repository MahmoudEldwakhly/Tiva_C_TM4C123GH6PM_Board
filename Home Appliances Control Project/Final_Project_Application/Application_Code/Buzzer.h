/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: buzzer.h
 *
 * Description: header file for the TivaC BUZZER driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#include "inc/hw_memmap.h" //Regiters Memory Map in Tivaware
#include "driverlib/gpio.h" //GPIO APIs Defines & Macros in Tivaware
#include "driverlib/sysctl.h" //Sysctl Registers in TIvaware

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* BUZZER HW Port and Pin ID */

#define BUZZER_PORT                    GPIO_PORTF_BASE
#define BUZZER_PIN                     0
#define BUZZER_ENABLE_PORT             SYSCTL_PERIPH_GPIOF     

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the buzzer pin direction and turn off the buzzer*/

void Buzzer_init(void);

/*Activates the buzzer*/

void Buzzer_on(void);

/*Deactivates the buzzer*/

void Buzzer_off(void);


#endif /* BUZZER_H_ */
