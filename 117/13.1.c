#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x;

    x = KnapsackDP(w, v, n, wx);

    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    free(x);
    return 0;
}

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int rows = n + 1;
    int cols = wx + 1;

    int *u = (int *)malloc(rows * cols * sizeof(int));
    int *x = (int *)malloc(n * sizeof(int));

    if (u == NULL || x == NULL) {
        free(u);
        free(x);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            u[i * cols + j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (w[i - 1] <= j) {
                int a = u[(i - 1) * cols + j];
                int b = u[(i - 1) * cols + (j - w[i - 1])] + v[i - 1];

                if (b > a) {
                    u[i * cols + j] = b;
                } else {
                    u[i * cols + j] = a;
                }
            } else {
                u[i * cols + j] = u[(i - 1) * cols + j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    {
        int j = wx;

        for (int i = n; i >= 1; i--) {
            if (u[i * cols + j] != u[(i - 1) * cols + j]) {
                x[i - 1] = 1;
                j -= w[i - 1];
            } else {
                x[i - 1] = 0;
            }
        }
    }

    free(u);
    return x;
}
