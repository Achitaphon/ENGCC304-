#include <stdio.h>

long SumLoop(int n);
long SumRecur(int n);

int main() {
    int testValueSmall;
    int testValueLarge;

    testValueSmall = 10;
    testValueLarge = 1000000;

    printf("SumLoop(%d) = %ld\n", testValueSmall, SumLoop(testValueSmall));
    printf("SumRecur(%d) = %ld\n", testValueSmall, SumRecur(testValueSmall));

    /* ทดลองค่าใหญ่: ตั้งใจทำให้เกิด run-time error แบบควบคุมได้ */
    printf("Trying SumRecur(%d) to trigger run-time error...\n", testValueLarge);
    printf("SumRecur(%d) = %ld\n", testValueLarge, SumRecur(testValueLarge));

    return 0;
}

long SumLoop(int n) {
    long sumResult;
    int current;

    sumResult = 0;
    current = 1;

    while (current <= n) {
        sumResult += current;
        current++;
    }

    return sumResult;
}

long SumRecur(int n) {
    /* ป้องกัน/ควบคุมไม่ให้ recursion ลึกจนเครื่องค้างแบบไม่แน่นอน */
    static int recursionDepth = 0;
    const int depthLimit = 50000;

    recursionDepth++;

    if (recursionDepth > depthLimit) {
        /* ทำให้เกิด run-time error แบบชัดเจน (หารด้วยศูนย์) */
        int zero = 0;
        int crash = 1 / zero;
        recursionDepth--;
        return crash;
    }

    if (n <= 1) {
        recursionDepth--;
        return 1;
    }

    {
        long result;
        result = n + SumRecur(n - 1);
        recursionDepth--;
        return result;
    }
}
