#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col);

int main(void) {
    int *data = NULL;
    int m = 0, n = 0;

    GetMatrix(&data, &m, &n);

    free(data);
    return 0;
}

void GetMatrix(int **value, int *row, int *col) {
    int i, j;

    if (scanf("%d %d", row, col) != 2) {
        return;
    }

    *value = (int *)malloc((*row) * (*col) * sizeof(int));
    if (*value == NULL) {
        exit(1);
    }

    for (i = 0; i < *row; i++) {
        for (j = 0; j < *col; j++) {
            if (scanf("%d", &(*value)[i * (*col) + j]) != 1) {
                return;
            }
        }
    }
}
