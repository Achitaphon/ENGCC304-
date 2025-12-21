#include <stdio.h>

#define MONTHS 3

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr);
void get_monthly_data(int array[], int size, const char *type);
void print_monthly_data(int array[], int size, const char *type);

int main(void) {
    int monthly_revenue[MONTHS];
    int monthly_expense[MONTHS];
    int net_profit;
    int business_status;

    get_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    get_monthly_data(monthly_expense, MONTHS, "EXPENSE");

    net_profit = analyze_profitability(monthly_revenue, monthly_expense, MONTHS, &business_status);

    printf("\n--- 3 MONTH FINANCIAL ANALYSIS REPORT ---\n");
    print_monthly_data(monthly_revenue, MONTHS, "REVENUE");
    print_monthly_data(monthly_expense, MONTHS, "EXPENSE");

    printf("\nNET PROFIT: %d\n\n", net_profit);

    if (business_status == 1) {
        printf("BUSINESS STATUS: PROJECT IS PROFITABLE\n");
    } else {
        printf("BUSINESS STATUS: PROJECT IS UNPROFITABLE\n");
    }

    return 0;
}

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr) {
    int total_rev = 0;
    int total_exp = 0;
    int i;
    int net;

    for (i = 0; i < size; i++) {
        total_rev += *(rev_ptr + i);
        total_exp += *(exp_ptr + i);
    }

    net = total_rev - total_exp;

    if (net >= 0) {
        *status_ptr = 1;
    } else {
        *status_ptr = 0;
    }

    return net;
}

void get_monthly_data(int array[], int size, const char *type) {
    int i;

    printf("Enter %d months of %s values:\n", size, type);
    for (i = 0; i < size; i++) {
        printf("Month %d %s: ", i + 1, type);
        scanf("%d", &array[i]);
    }
}

void print_monthly_data(int array[], int size, const char *type) {
    long total = 0;
    int i;

    for (i = 0; i < size; i++) {
        total += array[i];
    }
    printf("TOTAL %s: %ld\n", type, total);
}

