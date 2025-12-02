#include <stdio.h>

int main() {

    int limitN;
    int totalSum = 0;

    if (scanf("%d", &limitN) != 1) {
        return 1;
    }

    for (int step = 1; step <= limitN; step++) {
        totalSum += step;
    }

    printf("%d\n", totalSum);
    return 0;
}
