#include <stdio.h>

#define MAX_SIZE 1000

int *GetSet(int *n);

int main(void)
{
    int *data;
    int num;

    data = GetSet(&num);

    return 0;
}

int *GetSet(int *n)
{
    static int data[MAX_SIZE];
    int i;

    if (scanf("%d", n) != 1) {
        *n = 0;
        return data;
    }

    if (*n < 0) {
        *n = 0;
        return data;
    }

    if (*n > MAX_SIZE) {
        *n = MAX_SIZE;
    }

    for (i = 0; i < *n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            *n = i;
            break;
        }
    }

    return data;
}
