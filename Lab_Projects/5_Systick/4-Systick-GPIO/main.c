#include "SysTick.h"
#include "DIO.h"

int main(void) {
    // Initialize DIO
    dio_init('F', Pin1, Output);
    dio_init('F', Pin2, Output);
    dio_init('F', Pin3, Output);

    // Initialize SysTick Timer
    SysTick_Init(15999999); // 1-second delay (16 MHz clock)

    while (1) {
        // Toggle LEDs using SysTick timeout
        dio_writepin('F', Pin1, 1);  // Turn on LED connected to PF1
        while (!SysTick_Is_Time_Out()); // Wait for 1 second
        dio_writepin('F', Pin1, 0);  // Turn off LED connected to PF1
        while (!SysTick_Is_Time_Out()); // Wait for 1 second

        dio_writepin('F', Pin2, 1);  // Turn on LED connected to PF2
        while (!SysTick_Is_Time_Out()); // Wait for 1 second
        dio_writepin('F', Pin2, 0);  // Turn off LED connected to PF2
        while (!SysTick_Is_Time_Out()); // Wait for 1 second

        dio_writepin('F', Pin3, 1);  // Turn on LED connected to PF3
        while (!SysTick_Is_Time_Out()); // Wait for 1 second
        dio_writepin('F', Pin3, 0);  // Turn off LED connected to PF3
        while (!SysTick_Is_Time_Out()); // Wait for 1 second
    }

    return 0;
}
