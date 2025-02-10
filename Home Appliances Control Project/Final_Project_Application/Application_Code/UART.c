/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.c
 *
 * Description: source file for the TivaC UART driver
 *
 * Author: MCTA Team 5
 *
 *******************************************************************************/

#include "UART.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void UART0_Init(void) {
    SYSCTL_RCGCUART_R |= (1U << 0); // Enable UART0
    SYSCTL_RCGCGPIO_R |= (1U << 0); // Enable PORTA

    UART0_CTL_R &= ~(1U << 0); // Disable UART0 during configuration
    UART0_IBRD_R = 104; // Integer portion for 9600 baud rate (assuming 16 MHz clock)
    UART0_FBRD_R = 11;  // Fractional portion for 9600 baud rate
    UART0_LCRH_R = (0x3 << 5); // 8-bit, no parity, 1-stop bit
    UART0_CTL_R |= (1U << 0) | (1U << 8) | (1U << 9); // Enable UART, RX, TX

    GPIO_PORTA_AFSEL_R |= (1U << 0) | (1U << 1); // Enable alt function for PA0, PA1
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x00000011; // UART0
    GPIO_PORTA_DEN_R |= (1U << 0) | (1U << 1); // Digital enable
}

void UART0_SendString(const char *str) {
    while (*str) {
        while (UART0_FR_R & (1U << 5)); // Wait until TXFF is 0
        UART0_DR_R = *str++;
    }
}