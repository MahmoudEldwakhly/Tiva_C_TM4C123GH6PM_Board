/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.h
 *
 * Description: header file for the TivaC GPIO driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the temp sensor analog features*/

void UART0_Init(void);

/*Gets value of temperature sensor*/

void UART0_SendString(const char *str);

#endif /* TEMP_SENSOR_H_*/