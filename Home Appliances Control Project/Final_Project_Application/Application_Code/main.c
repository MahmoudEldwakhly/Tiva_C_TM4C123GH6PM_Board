#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "Buzzer.h"
#include "Relay.h"
#include "Limit_Switch.h"
#include "Temp_Sensor.h"
#include "UART.h"
#include "common_macros.h"

bool lamp_state = false;
bool plug_state = false;

uint32_t current_temp;

char buffer[50];
    
int main()
{
TempSensor_init();
LimitSwitch_init();
Buzzer_init();
Relay_init();
UART0_Init();

   while (1) {
        // Check if data is received via UART
        if ((UART0_FR_R & (1U << 4)) == 0) { // UART RXFE is 0 when data is available
            char command = UART0_DR_R & 0xFF;
            if (command == 'L') { // Toggle Lamp
                lamp_state = !lamp_state;
                if (lamp_state) {
                  Relay_on(RELAY_1_PIN);
                } else {
                   Relay_off(RELAY_1_PIN);                }
            } else if (command == 'P') { // Toggle Plug
                plug_state = !plug_state;
                if (plug_state) {
                  Relay_on(RELAY_2_PIN);
                } else {
                  Relay_off(RELAY_2_PIN);
                }
            }
        }

        // Read door sensor and send status
        if (LimitSwitch_get_status()) {
            UART0_SendString("DOOR:OPEN\r\n");
        } else {
            UART0_SendString("DOOR:CLOSED\r\n");
        }

        // Read temperature sensor and send data
        sprintf(buffer, "TEMP:%.1f\r\n", current_temp);
        UART0_SendString(buffer);

        // Trigger alarm based on temperature
  current_temp = TempSensor_get_value();
  if (current_temp > TEMP_THRESHOLD) {
        Buzzer_on(); // Turn on buzzer
    } else {
        Buzzer_off(); // Turn off buzzer
    }
}
        // Delay to avoid flooding the UART
    SysTickPeriodSet(16000000-1);
    SysTickEnable();
    }