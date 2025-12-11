#include <stdio.h>

struct SalesRecord {
    char name[50];   
    float target;   
    float actual;   
};

int main(void) {
    int N, i;
    float grandTotalCommission = 0.0f;

    scanf("%d", &N);

    struct SalesRecord records[N];

    for (i = 0; i < N; i++) {
        float baseCommission;

        scanf("%f %f %s",
              &records[i].target,
              &records[i].actual,
              records[i].name);

        baseCommission = records[i].actual * 0.10f;

        if (records[i].actual >= records[i].target * 1.20f) {
          
            baseCommission += 200.0f;     // โบนัส Tier 2
        } else if (records[i].actual >= records[i].target) {
           
            baseCommission += 50.0f;      // โบนัส Tier 1
        } else if (records[i].actual < records[i].target * 0.90f) {
            baseCommission -= 100.0f;     // ค่าปรับ
        }
   
        grandTotalCommission += baseCommission;
    }

    printf("Grand Total Commission: %.2f\n", grandTotalCommission);

    return 0;
}

