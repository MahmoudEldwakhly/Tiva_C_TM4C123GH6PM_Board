/******************************************************************************
 *
 * Module: RELAY
 *
 * File Name: Relay.h
 *
 * Description: header file for the TivaC Relay driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef RELAY_H_
#define RELAY_H_

#include "std_types.h"
#include "inc/hw_memmap.h" //Regiters Memory Map in Tivaware
#include "driverlib/gpio.h" //GPIO APIs Defines & Macros in Tivaware
#include "driverlib/sysctl.h" //Sysctl Registers in TIvaware

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* RELAY HW Ports and Pins ID */

#define RELAY_1_PORT                   GPIO_PORTF_BASE
#define RELAY_2_PORT                   GPIO_PORTF_BASE
#define RELAY_1_PIN                    GPIO_PIN_1
#define RELAY_2_PIN                    GPIO_PIN_3

#define RELAY_ENABLE_PORT             SYSCTL_PERIPH_GPIOF           
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the relay pin directions and turn off both relays*/

void Relay_init(void);

/*Activates desired relay*/

void Relay_on(char Relay_ID);

/*Deactivates desired relay*/

void Relay_off(char Relay_ID);


#endif /* RELAY_H_*/