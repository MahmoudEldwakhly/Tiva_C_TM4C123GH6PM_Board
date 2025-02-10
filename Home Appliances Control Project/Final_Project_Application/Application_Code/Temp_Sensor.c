/******************************************************************************
 *
 * Module: TEMP_SENSOR
 *
 * File Name: Temp_Sensor.c
 *
 * Description: source file for the TivaC Temp_Sensor driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#include "Temp_Sensor.h"
#include "ADC.h"
#include "common_macros.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*Initializes the temp sensor analog features*/

void TempSensor_init(void)
{
  SysCtlPeripheralEnable(ADC_PORT);
  SET_BIT(GPIO_PORTE_AFSEL_R,ADC_PIN);
  CLEAR_BIT(GPIO_PORTE_DEN_R,ADC_PIN);
  SET_BIT(GPIO_PORTE_AMSEL_R,ADC_PIN);

  ADCClockConfigSet(TEMP_SENSOR_ADC_CHANNEL,ADC_CLOCK_SRC_PIOSC | ADC_CLOCK_RATE_FULL, 1);
  ADCSequenceConfigure(TEMP_SENSOR_ADC_CHANNEL,SAMPLE_SEQUENCE_NUMBER,ADC_TRIGGER_PROCESSOR,ADC_SAMPLE_SEQUENCE_PRIORITY);
  ADCSequenceStepConfigure(TEMP_SENSOR_ADC_CHANNEL,SAMPLE_SEQUENCE_NUMBER,0,ADC_CTL_END);
}
uint32_t TempSensor_get_value(void)
{
  uint32_t ADC_Value, TempValue;
  ADCProcessorTrigger(TEMP_SENSOR_ADC_CHANNEL, SAMPLE_SEQUENCE_NUMBER);

  ADCSequenceDataGet(TEMP_SENSOR_ADC_CHANNEL, SAMPLE_SEQUENCE_NUMBER, &ADC_Value);

  TempValue= ADC_Value * TEMP_SENSOR_MAX_VOLT_VALUE * TEMP_SENSOR_MAX_TEMPERATURE/ ADC_MAXIMUM_VALUE;
  
  return TempValue;
  // return GPIOPinRead(Limit_Switch_Port,Limit_Switch_PIN);
}