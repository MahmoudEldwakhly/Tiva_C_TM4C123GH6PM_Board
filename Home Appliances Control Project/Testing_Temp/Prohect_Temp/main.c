#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


#define LED_LAMP_PIN  (1U << 1)  // Lamp connected to PF1
#define LED_PLUG_PIN  (1U << 3)  // Plug connected to PF2
#define DOOR_SENSOR_PIN (1U << 2)  // Door sensor input (PF3)
#define TEMP_SENSOR_ADC_CHANNEL 0  // ADC channel for temperature sensor
#define BUZZER_PIN (1U << 0)  // Buzzer connected to PF0
#define TEMP_THRESHOLD  40  // Temperature threshold in �C
#define DHT_PIN (1U << 4)  // DHT11 data connected to PE4

void UART0_Init(void);
void UART0_SendString(const char *str);
void GPIOF_Init(void);
void GPIOE_Init(void);
void ADC0_Init(void);
uint32_t ADC0_Read(void);
void delay_ms(int ms);
void triggerAlarm(float temperature);
void readDHT11(float *temperature, float *humidity);
unsigned short Read(void);

bool lamp_state = false;
bool plug_state = false;

int main(void) {
    UART0_Init();
    GPIOF_Init();
    GPIOE_Init();
    ADC0_Init();

    char buffer[50];
    float temperature = 0.0;
    float humidity = 0.0;

    while (1) {
        // Check if data is received via UART
        if ((UART0_FR_R & (1U << 4)) == 0) { // UART RXFE is 0 when data is available
            char command = UART0_DR_R & 0xFF;

            if (command == 'L') { // Toggle Lamp
                lamp_state = !lamp_state;
                if (lamp_state) {
                    GPIO_PORTF_DATA_R |= LED_LAMP_PIN;
                } else {
                    GPIO_PORTF_DATA_R &= ~LED_LAMP_PIN;
                }
            } else if (command == 'P') { // Toggle Plug
                plug_state = !plug_state;
                if (plug_state) {
                    GPIO_PORTF_DATA_R |= LED_PLUG_PIN;
                } else {
                    GPIO_PORTF_DATA_R &= ~LED_PLUG_PIN;
                }
            }
        }

        // Read door sensor and send status
        if (GPIO_PORTF_DATA_R & DOOR_SENSOR_PIN) {
            UART0_SendString("DOOR:OPEN\r\n");
        } else {
            UART0_SendString("DOOR:CLOSED\r\n");
        }

        // Read temperature and humidity from DHT11
        readDHT11(&temperature, &humidity);
        sprintf(buffer, "TEMP:%.1f\r\n", temperature);
        UART0_SendString(buffer);

        // Trigger alarm based on temperature
        triggerAlarm(temperature);

        delay_ms(1000); // Delay to avoid flooding the UART
    }
}

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

void GPIOF_Init(void) {
    SYSCTL_RCGCGPIO_R |= (1U << 5); // Enable clock for PORTF
    GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PORTF
    GPIO_PORTF_CR_R = 0x1F; // Allow changes to PF0-PF4
    GPIO_PORTF_DIR_R |= (LED_LAMP_PIN | LED_PLUG_PIN | BUZZER_PIN); // Set PF1, PF2, PF0 as output
    GPIO_PORTF_DIR_R &= ~DOOR_SENSOR_PIN; // Set PF3 as input
    GPIO_PORTF_DEN_R |= (LED_LAMP_PIN | LED_PLUG_PIN | BUZZER_PIN | DOOR_SENSOR_PIN); // Enable digital functionality
    GPIO_PORTF_PUR_R |= DOOR_SENSOR_PIN; // Enable pull-up resistor for PF3
}

void GPIOE_Init(void) {
    SYSCTL_RCGCGPIO_R |= (1U << 4); // Enable clock for PORTE
    GPIO_PORTE_DIR_R &= ~DHT_PIN; // Set PE4 as input
    GPIO_PORTE_DEN_R |= DHT_PIN; // Enable digital functionality for PE4
}

void ADC0_Init(void) {
    SYSCTL_RCGCADC_R |= 1; // Enable ADC0 clock
    SYSCTL_RCGCGPIO_R |= (1U << 4); // Enable clock for PORTE
    GPIO_PORTE_AFSEL_R |= (1U << 3); // Enable alternate function for PE3
    GPIO_PORTE_DEN_R &= ~(1U << 3); // Disable digital function for PE3
    GPIO_PORTE_AMSEL_R |= (1U << 3); // Enable analog mode for PE3

    ADC0_ACTSS_R &= ~8; // Disable SS3 during configuration
    ADC0_EMUX_R = (ADC0_EMUX_R & 0xFFFF0FFF) | 0x0000; // Software trigger
    ADC0_SSMUX3_R = TEMP_SENSOR_ADC_CHANNEL; // Set channel
    ADC0_SSCTL3_R = 0x06; // Single-ended, end of sequence
    ADC0_ACTSS_R |= 8; // Enable SS3
}

uint32_t ADC0_Read(void) {
    ADC0_PSSI_R = 8; // Start sampling on SS3
    while ((ADC0_RIS_R & 8) == 0); // Wait for conversion complete
    uint32_t result = ADC0_SSFIFO3_R & 0xFFF; // Read 12-bit result
    ADC0_ISC_R = 8; // Clear completion flag
    return result;
}

void readDHT11(float *temperature, float *humidity) {
    uint8_t hum_int = Read();
    uint8_t temp_int = Read();
    *humidity = hum_int;
    *temperature = temp_int;
}

unsigned short Read(void) {
    uint8_t bit_cnt;
    uint8_t hum_int = 0;
    for (bit_cnt = 0; bit_cnt < 8; bit_cnt++) {
        while (!(GPIO_PORTE_DATA_R & DHT_PIN)); // Wait for pin to go high
        delay_ms(1); // Wait for 29us
        if (GPIO_PORTE_DATA_R & DHT_PIN) {
            hum_int |= (0x01 << (7 - bit_cnt));
        }
        while (GPIO_PORTE_DATA_R & DHT_PIN); // Wait for pin to go low
    }
    return hum_int;
}

void triggerAlarm(float temperature) {
    if (temperature > TEMP_THRESHOLD) {
        GPIO_PORTF_DATA_R |= BUZZER_PIN; // Turn on buzzer
    } else {
        GPIO_PORTF_DATA_R &= ~BUZZER_PIN; // Turn off buzzer
    }
}

void delay_ms(int ms) {
    for (int i = 0; i < ms * 3180; i++) {
        __asm("NOP");
    }
}
