#include <stdio.h>
#include <stdlib.h>

void GetSet(int **data, int *num);

int main(void)
{
    int *data = NULL;
    int num = 0;

    GetSet(&data, &num);

    free(data);
    return 0;
}

void GetSet(int **data, int *num)
{
    int i;

    if (scanf("%d", num) != 1) {
        *num = 0;
        *data = NULL;
        return;
    }

    if (*num <= 0) {
        *data = NULL;
        return;
    }

    *data = (int *)malloc((*num) * sizeof(int));
    if (*data == NULL) {
        exit(1);
    }

    for (i = 0; i < *num; i++) {
        if (scanf("%d", &(*data)[i]) != 1) {
            (*data)[i] = 0;
        }
    }
}
