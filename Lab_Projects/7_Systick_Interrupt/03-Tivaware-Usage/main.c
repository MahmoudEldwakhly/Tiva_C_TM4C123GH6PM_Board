#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/pin_map.h"

#define LED_PIN    GPIO_PIN_2

volatile uint32_t g_ui32SysTickCount = 0;

void SysTick_Handler(void)
{
    g_ui32SysTickCount++;
}

void main(void)
{
    // Enable the peripherals for GPIO Port F (where the LED is connected)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Wait for the GPIO module to be ready
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    // Configure PF2 (LED pin) as output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_PIN);

    // Initialize SysTick to interrupt every 1ms
    SysTickPeriodSet(SysCtlClockGet() / 1000);  // 1ms tick (1000Hz)
    SysTickIntEnable();                         // Enable SysTick interrupt
    SysTickEnable();                            // Enable SysTick Timer

    while (1)
    {
        // Toggle the LED every 500ms (500ms = 500 ticks of 1ms)
        if (g_ui32SysTickCount >= 500)
        {
            g_ui32SysTickCount = 0;  // Reset the SysTick counter

            // Toggle LED
            GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN, GPIOPinRead(GPIO_PORTF_BASE, LED_PIN) ^ LED_PIN);
        }
    }
}
