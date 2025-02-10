#include <stdint.h>
#include "tm4c123gh6pm.h"

#define red	(1 << 1)
#define blue	(1 << 2)
#define green	(1 << 3)

void UART0_Init(void);
void UART0_TransmitChar(char c);
char UART0_ReceiveChar(void);
void UART0_TransmitString(const char *str);

int main(void) {
  // Initialize UART0
  UART0_Init();
  
  // Transmit a welcome message
  UART0_TransmitString("Hello from TM4C123GH6PM!\r\n");
  
  SYSCTL_RCGCGPIO_R |= (1 << 5);
  while ((SYSCTL_PRGPIO_R & (1 << 5)) == 0);
  
  GPIO_PORTF_DIR_R |= red | blue | green;
  GPIO_PORTF_DEN_R |= red | blue | green;
  while (1) {
    // Echo received characters back to the terminal
    char c = UART0_ReceiveChar();
    UART0_TransmitChar(c);
    switch(c)
    {
    case 'r':
      GPIO_PORTF_DATA_R = red;
      break;
    case 'b':
      GPIO_PORTF_DATA_R = blue;
      break;
    case 'g':
      GPIO_PORTF_DATA_R = green;
      break;
    case 'x':
      GPIO_PORTF_DATA_R = 0x00;
      break;
    case 'w':
      GPIO_PORTF_DATA_R = red | blue | green;
      break;
    }
  }
}

void UART0_Init(void) {
  SYSCTL_RCGCUART_R |= (1 << 0);
  SYSCTL_RCGCGPIO_R |= (1 << 0);
  while ((SYSCTL_PRUART_R & (1 << 0)) == 0);
  while ((SYSCTL_PRGPIO_R & (1 << 0)) == 0);
  
  GPIO_PORTA_AFSEL_R |= (1 << 0) | (1 << 1);
  GPIO_PORTA_PCTL_R &= ~0xFF;
  GPIO_PORTA_PCTL_R |= (1 << 0) | (1 << 4);
  GPIO_PORTA_DEN_R |= (1 << 0) | (1 << 1);
  GPIO_PORTA_AMSEL_R &= ~((1 << 0) | (1 << 1));
  
  UART0_CTL_R &= ~(1 << 0);
  UART0_IBRD_R = 104;
  UART0_FBRD_R = 11;
  UART0_LCRH_R = (0x3 << 5); // 8-bit word length, no parity, 1 stop bit
  UART0_CC_R = 0x0;
  UART0_CTL_R |= (1 << 0) | (1 << 8) | (1 << 9);  // Enable UART0, Tx, Rx
}

void UART0_TransmitChar(char c) {
  while ((UART0_FR_R & (1 << 5)) != 0);  // Wait until the transmit FIFO is not full
  UART0_DR_R = c;  // Write the character to the data register
}

char UART0_ReceiveChar(void) {
  while ((UART0_FR_R & (1 << 4)) != 0);  // Wait until the receive FIFO is not empty
  return (char)(UART0_DR_R & 0xFF);  // Read and return the received character
}

void UART0_TransmitString(const char *str) {
  while (*str) {
    UART0_TransmitChar(*str++);
  }
}
