/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.c
 *
 * Description: Source file for the TivaC GPIO driver
 *
 * Author: MCTA Team 5 
 *
 *******************************************************************************/

#include "GPIO.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Initializes the buzzer pin direction & turns off the buzzer */

void GPIOF_Init(void) {
    SYSCTL_RCGCGPIO_R |= (1U << 5); // Enable clock for PORTF
    GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PORTF
    GPIO_PORTF_CR_R = 0x1F; // Allow changes to PF0-PF4
    GPIO_PORTF_DIR_R |= (LED_LAMP_PIN | LED_PLUG_PIN | BUZZER_PIN); // Set PF1, PF2, PF0 as output
    GPIO_PORTF_DIR_R &= ~DOOR_SENSOR_PIN; // Set PF3 as input
    GPIO_PORTF_DEN_R |= (LED_LAMP_PIN | LED_PLUG_PIN | BUZZER_PIN | DOOR_SENSOR_PIN); // Enable digital functionality
    GPIO_PORTF_PUR_R |= DOOR_SENSOR_PIN; // Enable pull-up resistor for PF3
}







