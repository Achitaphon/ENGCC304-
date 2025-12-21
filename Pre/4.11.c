#include <stdio.h>

#define ROWS 2
#define COLS 4

int main() {
    int matrix[ROWS][COLS];
    int total_sum = 0;
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            total_sum += matrix[i][j];
        }
    }

    printf("--- 2D ARRAY SUMMATION REPORT ---\n");
    printf("Recorded Matrix (2x4):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (j > 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Sum of all elements: %d\n", total_sum);

    return 0;
}

