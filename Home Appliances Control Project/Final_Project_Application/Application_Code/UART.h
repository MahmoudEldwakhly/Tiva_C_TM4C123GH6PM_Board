/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Description: header file for the TivaC UART driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the temp sensor analog features*/

void UART0_Init(void);

/*Gets value of temperature sensor*/

void UART0_SendString(const char *str);

#endif /* TEMP_SENSOR_H_*/