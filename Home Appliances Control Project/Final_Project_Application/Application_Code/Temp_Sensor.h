/******************************************************************************
 *
 * Module: TEMP_SENSOR
 *
 * File Name: Temp_Sensor.h
 *
 * Description: header file for the TivaC Temp_Sensor driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "std_types.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_memmap.h" //Regiters Memory Map in Tivaware
#include "inc/hw_gpio.h" //GPIO Hardware Defines & Macros in Tivaware
#include "driverlib/gpio.h" //GPIO APIs Defines & Macros in Tivaware
#include "driverlib/sysctl.h" //Sysctl Registers in TIvaware
#include "driverlib/adc.h" //Using ADC Headers for ADC APIs

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TEMP_SENSOR_ADC_CHANNEL        ADC0_BASE 
#define TEMP_SENSOR_MAX_VOLT_VALUE     3.3
#define TEMP_SENSOR_MAX_TEMPERATURE    10
#define ADC_MAXIMUM_VALUE              4096
#define SAMPLE_SEQUENCE_NUMBER         3
#define ADC_SAMPLE_SEQUENCE_PRIORITY   0
#define ADC_PORT                       GPIO_PORTE_BASE
#define ADC_PIN                        GPIO_PIN_3
#define TEMP_THRESHOLD                 43  // Temperature threshold in °C

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Initializes the temp sensor analog features*/

void TempSensor_init(void);

/*Gets value of temperature sensor*/

uint32_t TempSensor_get_value(void);

#endif /* TEMP_SENSOR_H_*/