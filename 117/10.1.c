#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {

    printf("SumLoop(10) = %ld\n", SumLoop(10));
    printf("SumRecur(10) = %ld\n", SumRecur(10));

    /* ทดลองค่าใหญ่เพื่อให้เกิด run-time error (Stack Overflow) */
    printf("SumRecur(1000000) = %ld\n", SumRecur(1000000));

    return 0;
}

long SumLoop(int n) {
    long sum = 0;
    int i;

    for (i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

long SumRecur(int n) {

    if (n <= 1)     /* Base Case */
        return 1;

    return n + SumRecur(n - 1);
}
