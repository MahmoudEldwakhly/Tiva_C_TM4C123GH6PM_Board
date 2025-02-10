#include <stdio.h>
#include <string.h>

#define TASK5

#ifdef TASK1
void add_two_numbers(int *a, int *b, int *result) {
    *result = *a + *b;
}
#endif

#ifdef TASK2
void multiply_array(int *arr, int size, int multiplier) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= multiplier;
    }
}
#endif

#ifdef TASK3
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
#endif

#ifdef TASK4
int string_length(char *str) {
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    return length;
}
#endif

#ifdef TASK5
void concatenate_strings(char *dest, char *src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}
#endif

#ifdef TASK6
void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
#endif

#ifdef TASK7
int search_element(int *arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == element) {
            return i;
        }
    }
    return -1;
}
#endif

int main() {
#ifdef TASK1
    int a = 5, b = 10, result;
    add_two_numbers(&a, &b, &result);
    printf("Sum of %d and %d is: %d\n", a, b, result);
#endif

#ifdef TASK2
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int multiplier = 3;
    multiply_array(arr, size, multiplier);
    printf("Array after multiplication: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
#endif

#ifdef TASK3
    int x = 7, y = 14;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
#endif

#ifdef TASK4
    char str[] = "Hello";
    int length = string_length(str);
    printf("Length of the string \"%s\" is: %d\n", str, length);
#endif

#ifdef TASK5
    char dest[100] = "Hello, ";
    char src[] = "World!";
    concatenate_strings(dest, src);
    printf("Concatenated string: %s\n", dest);
#endif

#ifdef TASK6
    int arr_sort[] = {34, 7, 23, 32, 5, 62};
    int size_sort = sizeof(arr_sort) / sizeof(arr_sort[0]);
    sort_array(arr_sort, size_sort);
    printf("Sorted array: ");
    for (int i = 0; i < size_sort; i++) {
        printf("%d ", arr_sort[i]);
    }
    printf("\n");
#endif

#ifdef TASK7
    int arr_search[] = {10, 20, 30, 40, 50};
    int size_search = sizeof(arr_search) / sizeof(arr_search[0]);
    int element = 30;
    int index = search_element(arr_search, size_search, element);
    if (index != -1) {
        printf("Element %d found at index: %d\n", element, index);
    } else {
        printf("Element %d not found.\n", element);
    }
#endif

    return 0;
}



seif eldin samer;
Youssef Hany;
Adham Ossama;
Rana Mohamed;