#include <stdio.h>
#include <stdlib.h>

void mergesort(int t[], int k);
void merge(int *u, int m, int *v, int n, int *t);

int main() {
    int data[7] = { 4, 6, 1, 2, 5, 1, 8 };
    int n = 7;

    mergesort(data, n);

    for (int i = 0; i < n; i++)
        printf("%d ", data[i]);

    return 0;
}

void mergesort(int t[], int k) {
    int mid;

    if (k <= 1)
        return;

    mid = k / 2;

    mergesort(t, mid);
    mergesort(t + mid, k - mid);

    int *temp = (int*)malloc(k * sizeof(int));

    merge(t, mid, t + mid, k - mid, temp);

    for (int i = 0; i < k; i++)
        t[i] = temp[i];

    free(temp);
}

void merge(int *u, int m, int *v, int n, int *t) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (u[i] <= v[j])
            t[k++] = u[i++];
        else
            t[k++] = v[j++];
    }

    while (i < m)
        t[k++] = u[i++];

    while (j < n)
        t[k++] = v[j++];
}
