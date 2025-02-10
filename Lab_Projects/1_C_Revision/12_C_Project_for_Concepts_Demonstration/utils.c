// utils.c
#include "utils.h"

// Const variable
const char* APP_NAME = "Simple Calculator";

// Static variable (internal linkage)
static int calculation_count = 0;

// Function definitions
int add(int a, int b) {
    calculation_count++;
    return a + b;
}

int subtract(int a, int b) {
    calculation_count++;
    return a - b;
}

int multiply(int a, int b) {
    calculation_count++;
    return a * b;
}

float divide(int a, int b) {
    calculation_count++;
    if (b != 0)
        return (float)a / b;
    else
        return 0.0f; // Handle division by zero
}

void print_app_name() {
    printf("Application: %s\n", APP_NAME);
}
