#include "dio.h"

int main(void) {
  // Initialize Port F Pin0 as Input with pull-up resistor enabled
  dio_init('F', Pin4, Input);
  
  // Initialize Port F Pin1 as Output
  dio_init('F', Pin1, Output);
  
  // Read Pin0 on Port F
  uint8_t pin_value = dio_readpin('F', Pin4);
  
  // Write high to Pin1 on Port F
  dio_writepin('F', Pin1, 1);
  
  while (1) {
    // Toggle Pin1 on Port F
    dio_writepin('F', Pin1, !dio_readpin('F', Pin4));
    for(int i =0; i < 100000; i++){}
  }
  
  return 0;
}
