#include <stdio.h>
#include <stdlib.h>

int GetSet(int **data);

int main(void) {
    int *data;
    int num;

    num = GetSet(&data);

    free(data);
    return 0;
}

int GetSet(int **data) {
    int n;
    int i;

    scanf("%d", &n);

    *data = (int *)malloc(n * sizeof(int));
    if (*data == NULL) {
        exit(1);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &(*data)[i]);
    }

    return n;
}
