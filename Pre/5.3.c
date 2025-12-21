#include <stdio.h>

#define SIZE 5

int calculate_sum(int array[], int size);

int main(void) {
    int numbers[SIZE];
    int total_sum;
    float average;
    int i;

    for (i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    total_sum = calculate_sum(numbers, SIZE);
    average = (float)total_sum / SIZE;

    printf("--- ARRAY AVERAGE REPORT ---\n");
    printf("Recorded Numbers: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", numbers[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Total Sum: %d\n", total_sum);
    printf("Average: %.2f\n", average);

    return 0;
}

int calculate_sum(int array[], int size) {
    int sum = 0;
    int i;

    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

