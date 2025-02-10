#include "DIO.h"
#include "SysTick_Timer.h"
#include "tm4c123gh6pm.h"

int main(void) {
    // Initialize DIO
    DIO_init(PORTF_ID, PIN1_ID, PIN_OUTPUT,PORT_OUTPUT,PIN);
    DIO_init(PORTF_ID, PIN2_ID, PIN_OUTPUT,PORT_OUTPUT,PIN);
    DIO_init(PORTF_ID, PIN3_ID, PIN_OUTPUT,PORT_OUTPUT,PIN);

    DIO_writePin(PORTF_ID, PIN1_ID, LOGIC_LOW);  // Turn off LED connected to PF1
    DIO_writePin(PORTF_ID, PIN2_ID, LOGIC_LOW);  // Turn off LED connected to PF1
    DIO_writePin(PORTF_ID, PIN3_ID, LOGIC_LOW);  // Turn off LED connected to PF1

    // Initialize SysTick Timer
    SysTick_Init(15999999); // 1-second delay (16 MHz clock)

    while (1) {
        // Toggle LEDs using SysTick timeout
        DIO_writePin(PORTF_ID, PIN1_ID, LOGIC_HIGH);  // Turn on LED connected to PF1
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second
        DIO_writePin(PORTF_ID, PIN1_ID, LOGIC_LOW);  // Turn off LED connected to PF1
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second

        DIO_writePin(PORTF_ID, PIN2_ID, LOGIC_HIGH);  // Turn on LED connected to PF2
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second
        DIO_writePin(PORTF_ID, PIN2_ID, LOGIC_LOW);  // Turn off LED connected to PF2
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second

        DIO_writePin(PORTF_ID, PIN3_ID, LOGIC_HIGH);  // Turn on LED connected to PF3
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second
        DIO_writePin(PORTF_ID, PIN3_ID, LOGIC_LOW);  // Turn off LED connected to PF3
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second
        // for white led
        
        DIO_writePin(PORTF_ID, PIN1_ID, LOGIC_HIGH);  // Turn on LED connected to PF1
        DIO_writePin(PORTF_ID, PIN2_ID, LOGIC_HIGH);  // Turn on LED connected to PF2
        DIO_writePin(PORTF_ID, PIN3_ID, LOGIC_HIGH);  // Turn on LED connected to PF3
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second
        DIO_writePin(PORTF_ID, PIN1_ID, LOGIC_LOW);  // Turn off LED connected to PF1
        DIO_writePin(PORTF_ID, PIN2_ID, LOGIC_LOW);  // Turn off LED connected to PF2
        DIO_writePin(PORTF_ID, PIN3_ID, LOGIC_LOW);  // Turn off LED connected to PF3
        while (!SysTick_Is_Time_Out()){} // Wait for 1 second

        
    }

    return 0;
}

