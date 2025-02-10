/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: header file for the TivaC ADC driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "tm4c123gh6pm.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE              4096
#define ADC_PIN                        3
#define TEMP_THRESHOLD                 27  // Temperature threshold in °C

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the temp sensor analog features*/

void ADC0_Init(void);

/*Gets value of temperature sensor*/

uint32 ADC0_Read(void);

#endif /* ADC_H_*/