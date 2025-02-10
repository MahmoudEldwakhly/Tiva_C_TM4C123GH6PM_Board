// utils.h
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// #define directive
#define MAX_INPUT 100

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

// External variable
extern const char* APP_NAME;

// Static variable (only visible in utils.c)
void print_app_name();

#endif // UTILS_H
