#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    int n, i;
    float sum = 0.0, average;

    // Input the number of elements
    printf("Enter the number of integers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. The number of integers must be a positive integer.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the integers
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(array); // Free allocated memory before exiting
            return 1;
        }
        sum += array[i]; // Calculate the sum
    }

    // Calculate the average
    average = sum / n;

    // Print the average
    printf("The average is: %.2f\n", average);

    // Free the allocated memory
    free(array);

    return 0;
}