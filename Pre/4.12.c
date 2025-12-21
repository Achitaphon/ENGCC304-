#include <stdio.h>

#define A_ROWS 2
#define A_COLS 3

#define B_ROWS 2
#define B_COLS 3

#define BT_ROWS 3
#define BT_COLS 2

#define C_ROWS 2
#define C_COLS 2

void print_matrix(int rows, int cols, int matrix[rows][cols]);

int main(void) {
    int A[A_ROWS][A_COLS];
    int B[B_ROWS][B_COLS];
    int BT[BT_ROWS][BT_COLS];
    int C[C_ROWS][C_COLS];
    int i, j, k;

    printf("Enter elements for Matrix A (2x3):\n");
    for (i = 0; i < A_ROWS; i++) {
        for (j = 0; j < A_COLS; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements for Matrix B (2x3):\n");
    for (i = 0; i < B_ROWS; i++) {
        for (j = 0; j < B_COLS; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    /* Transpose B (2x3) -> BT (3x2) */
    for (i = 0; i < B_ROWS; i++) {
        for (j = 0; j < B_COLS; j++) {
            BT[j][i] = B[i][j];
        }
    }

    /* Multiply A (2x3) x BT (3x2) -> C (2x2) */
    for (i = 0; i < C_ROWS; i++) {
        for (j = 0; j < C_COLS; j++) {
            int sum = 0;
            for (k = 0; k < A_COLS; k++) {
                sum += A[i][k] * BT[k][j];
            }
            C[i][j] = sum;
        }
    }

    printf("\n--- MATRIX MULTIPLICATION REPORT ---\n");

    printf("\nMatrix A (2x3):\n");
    print_matrix(A_ROWS, A_COLS, A);

    printf("\nMatrix B (2x3):\n");
    print_matrix(B_ROWS, B_COLS, B);

    printf("\nMatrix B Transposed (BT, 3x2):\n");
    print_matrix(BT_ROWS, BT_COLS, BT);

    printf("\nResult Matrix C (A x BT, 2x2):\n");
    print_matrix(C_ROWS, C_COLS, C);

    return 0;
}

void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (j == 0) {
                printf("%d", matrix[i][j]);
            } else {
                printf(" %d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

