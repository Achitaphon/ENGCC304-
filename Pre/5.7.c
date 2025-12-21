#include <stdio.h>

#define SIZE 5

void sort_array_ascending(int array[], int size);
void print_array(int array[], int size);

int main(void) {
    int numbers[SIZE];
    int original_copy[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1) return 1;
        original_copy[i] = numbers[i];
    }

    sort_array_ascending(numbers, SIZE);

    printf("--- ARRAY SORTING REPORT ---\n");
    printf("Original Array: ");
    print_array(original_copy, SIZE);
    printf("Sorted Array (Ascending): ");
    print_array(numbers, SIZE);

    return 0;
}

void sort_array_ascending(int array[], int size) {
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print_array(int array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
