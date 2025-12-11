
#include <stdio.h>

int main() {
    int N_DAYS;
    int day;
    float initialBudget;
    float remainingBudget;
    float dailySpend;

    if (scanf("%f %d", &initialBudget, &N_DAYS) != 2) {
        return 1;
    }

    remainingBudget = initialBudget;

    printf("Day | Spend | Remaining\n");
    printf("-----------------------\n");

    for (day = 1; day <= N_DAYS; day++) {
        dailySpend = 0.0;

        if (remainingBudget >= 500.00) {
            dailySpend = 100.00;
        } else if (remainingBudget >= 100.00) {
            dailySpend = 50.00;
        } else if (remainingBudget > 0.0) {
            dailySpend = 20.00;
        } else {
            dailySpend = 0.0;
        }

        if (dailySpend > remainingBudget) {
            dailySpend = remainingBudget;
        }

        remainingBudget = remainingBudget - dailySpend;

        printf("%d | %.2f | %.2f\n", day, dailySpend, remainingBudget);
    }

    printf("-----------------------\n");
    printf("Final Budget: %.2f\n", remainingBudget);

    return 0;
}
