#include <stdio.h>

#define SIZE 5

int calculate_net_balance(int *trans_array, int size, int *status_ptr);

int main(void) {
    int transactions[SIZE];
    int net_balance;
    int finance_status; /* 1 = PROFIT, 0 = LOSS */
    int i;

    /* Input 5 transactions */
    for (i = 0; i < SIZE; i++) {
        if (scanf("%d", &transactions[i]) != 1) {
            return 1;
        }
    }

    /* Calculate net balance + get status via pointer (call by reference) */
    net_balance = calculate_net_balance(transactions, SIZE, &finance_status);

    /* Report */
    printf("--- PERSONAL FINANCE REPORT ---\n");
    printf("Transactions Recorded: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", transactions[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Net Balance: %d\n", net_balance);
    printf("Status: %s\n", (finance_status == 1) ? "PROFIT" : "LOSS");

    return 0;
}

int calculate_net_balance(int *trans_array, int size, int *status_ptr) {
    int sum = 0;
    int i;

    /* Array traversal via pointer arithmetic */
    for (i = 0; i < size; i++) {
        sum += *(trans_array + i);
    }

    /* Set status via pointer (call by reference) */
    if (sum >= 0) {
        *status_ptr = 1; /* PROFIT */
    } else {
        *status_ptr = 0; /* LOSS */
    }

    return sum;
}

