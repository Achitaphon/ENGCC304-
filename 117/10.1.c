#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {
    int smallN;
    int bigN;

    smallN = 10;
    bigN = 1000000;

    printf("SumLoop(n) = %ld\n", SumLoop(smallN));
    printf("SumRecur(n) = %ld\n", SumRecur(smallN));

    printf("Trying to trigger run-time error with n = %d\n", bigN);
    printf("SumRecur(n) = %ld\n", SumRecur(bigN));

    return 0;
}

long SumLoop(int n) {
    long sumValue;
    int currentValue;

    sumValue = 0;
    currentValue = 1;

    while (currentValue <= n) {
        sumValue = sumValue + currentValue;
        currentValue = currentValue + 1;
    }

    return sumValue;
}

long SumRecur(int n) {
    static int currentDepth = 0;
    const int maxDepth = 50000;

    currentDepth = currentDepth + 1;

    if (currentDepth > maxDepth) {
        int zeroValue;
        int crashValue;

        zeroValue = 0;
        crashValue = 1 / zeroValue;

        currentDepth = currentDepth - 1;
        return crashValue;
    }

    if (n <= 1) {
        currentDepth = currentDepth - 1;
        return 1;
    }

    {
        long resultValue;

        resultValue = n + SumRecur(n - 1);

        currentDepth = currentDepth - 1;
        return resultValue;
    }
}
