/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the TivaC ADC driver
 *
 * Author: MCTA Team 5 
 *
 *******************************************************************************/

#include "ADC.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC0_Init(void) {
    SYSCTL_RCGCADC_R |= 1; // Enable ADC0 clock
    SYSCTL_RCGCGPIO_R |= (1U << 4); // Enable clock for PORTE
    GPIO_PORTE_AFSEL_R |= (1U << ADC_PIN); // Enable alternate function for PE3
    GPIO_PORTE_DEN_R &= ~(1U << ADC_PIN); // Disable digital function for PE3
    GPIO_PORTE_AMSEL_R |= (1U << ADC_PIN); // Enable analog mode for PE3

    ADC0_ACTSS_R &= ~8; // Disable SS3 during configuration
    ADC0_EMUX_R = (ADC0_EMUX_R & 0xFFFF0FFF) | 0x0000; // Software trigger
    ADC0_SSMUX3_R = TEMP_SENSOR_ADC_CHANNEL; // Set channel
    ADC0_SSCTL3_R = 0x06; // Single-ended, end of sequence
    ADC0_ACTSS_R |= 8; // Enable SS3
}

uint32 ADC0_Read(void) {
    ADC0_PSSI_R = 8; // Start sampling on SS3
    while ((ADC0_RIS_R & 8) == 0); // Wait for conversion complete
    uint32_t result = ADC0_SSFIFO3_R & 0xFFF; // Read 12-bit result
    ADC0_ISC_R = 8; // Clear completion flag
    return result;
}





