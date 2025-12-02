#include <stdio.h>

#define PLAN_BASIC 1
#define PLAN_PREMIUM 2

#define BASIC_BASE_PRICE 299.0
#define PREMIUM_BASE_PRICE 599.0

#define BASIC_FREE_DATA 10.0
#define PREMIUM_FREE_DATA 20.0

#define BASIC_EXTRA_RATE 10.0
#define PREMIUM_EXTRA_RATE 5.0
#define PREMIUM_PENALTY 50.0

int main() {
    int planCode;
    float dataUsage_GB;
    float totalBill = 0.0;
    float extraUsage = 0.0;

    if (scanf("%d %f", &planCode, &dataUsage_GB) != 2)
    {
        return 1;
    }

    if (planCode == PLAN_BASIC)
    {
        if (dataUsage_GB > BASIC_FREE_DATA)
        {
            extraUsage = dataUsage_GB - BASIC_FREE_DATA;
            totalBill = BASIC_BASE_PRICE + BASIC_EXTRA_RATE * extraUsage;
        }
        else
        {
            totalBill = BASIC_BASE_PRICE;
        }

        printf("%.2f\n", totalBill);
    }
    else if (planCode == PLAN_PREMIUM)
    {
        if (dataUsage_GB > PREMIUM_FREE_DATA)
        {
            extraUsage = dataUsage_GB - PREMIUM_FREE_DATA;
            totalBill = PREMIUM_BASE_PRICE + PREMIUM_PENALTY + PREMIUM_EXTRA_RATE * extraUsage;
        }
        else
        {
            totalBill = PREMIUM_BASE_PRICE;
        }

        printf("%.2f\n", totalBill);
    }
    else
    {
        printf("Invalid Plan Code\n");
    }
    return 0;
}
