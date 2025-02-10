1. Disable the Timer

NVIC_ST_CTRL_R = 0; // Disable SysTick

2. Calculate Reload Value

For 500 ms delay with a 16 MHz clock:
  Ticks = (0.5) / (1 / 16000000) = 8000000
    reload = 8000000 - 1;
  
3. Set Reload Value

NVIC_ST_RELOAD_R = 7999999; // 500 ms

4. Clear Current Value

NVIC_ST_CURRENT_R = 0;

5. Enable Timer

NVIC_ST_CTRL_R = 0x05; // Enable with system clock