#include <stdio.h>

#define MAX_SALES 1000

struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

int main() {
    int N;
    int i;
    float grandTotalCommission;
    struct SalesRecord records[MAX_SALES];

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    if (N < 1 || N > MAX_SALES) {
        return 1;
    }

    grandTotalCommission = 0.0;

    for (i = 0; i < N; i++) {
        float baseCommission;

        if (scanf("%f %f %49s",
                  &records[i].target,
                  &records[i].actual,
                  records[i].name) != 3) {
            return 1;
        }

        baseCommission = records[i].actual * 0.10;

        if (records[i].actual >= records[i].target * 1.20) {
            baseCommission = baseCommission + 200.0;
        } else if (records[i].actual >= records[i].target) {
            baseCommission = baseCommission + 50.0;
        } else if (records[i].actual < records[i].target * 0.90) {
            baseCommission = baseCommission - 100.0;
        }

        grandTotalCommission = grandTotalCommission + baseCommission;
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}
