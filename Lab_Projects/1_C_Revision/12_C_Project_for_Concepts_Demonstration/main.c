// main.c
#include <stdio.h>
#include "utils.h"

// Function prototype
void show_menu();

int main() {
    int choice;
    int a, b;
    float result;
    int running = 1; // Variable types demonstration: int

    print_app_name();

    while (running) { // Loop demonstration: while loop
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) { // Switch case demonstration
            case 1:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                result = add(a, b);
                printf("Result: %d + %d = %d\n", a, b, (int)result);
                break;
            case 2:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                result = subtract(a, b);
                printf("Result: %d - %d = %d\n", a, b, (int)result);
                break;
            case 3:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                result = multiply(a, b);
                printf("Result: %d * %d = %d\n", a, b, (int)result);
                break;
            case 4:
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                if (b != 0) { // If statement demonstration
                    result = divide(a, b);
                    printf("Result: %d / %d = %.2f\n", a, b, result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            case 5:
                printf("Total calculations performed.\n");
                // Normally, we'd expose a function to get calculation_count
                // But since it's static, it's not accessible here
                break;
            case 0:
                printf("Exiting the program.\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n"); // For better readability
    }

    return 0;
}

void show_menu() {
    printf("=== Simple Calculator ===\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Show Calculation Count (Not Available)\n"); // Placeholder
    printf("0. Exit\n");
}
