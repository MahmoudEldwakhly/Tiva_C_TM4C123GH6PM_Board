#ifndef TM4C123GH6PM_H
#define TM4C123GH6PM_H

#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))

// Define the bit for the red LED on Port F
#define RED_LED                 (1U << 1) // PF1

#endif
