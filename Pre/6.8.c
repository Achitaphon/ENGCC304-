#include <stdio.h>

#define SIZE 5

int find_and_update(int *arr_ptr, int size, int search_value, int new_value);
void print_array(int array[], int size);

int main(void) {
    int numbers[SIZE];
    int search_val;
    int new_val;
    int status;
    int i;

    for (i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%d", &search_val) != 1) {
        return 1;
    }
    if (scanf("%d", &new_val) != 1) {
        return 1;
    }

    printf("--- ARRAY UPDATE REPORT ---\n");
    printf("Array BEFORE Update: ");
    print_array(numbers, SIZE);

    status = find_and_update(numbers, SIZE, search_val, new_val);

    printf("Array AFTER Update: ");
    print_array(numbers, SIZE);

    if (status == 1) {
        printf("Status: Update SUCCESSFUL.\n");
    } else {
        printf("Status: Update FAILED (Value not found).\n");
    }

    return 0;
}

int find_and_update(int *arr_ptr, int size, int search_value, int new_value) {
    int i;

    for (i = 0; i < size; i++) {
        if (*(arr_ptr + i) == search_value) {
            *(arr_ptr + i) = new_value;
            return 1;
        }
    }
    return 0;
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

