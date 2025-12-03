#include <stdio.h>

int main() {
    float principal, monthlyPayment, interest;
    int monthCount = 0;
    const float INTEREST_RATE = 0.01f;
    const float PENALTY = 10.0f;

    if (scanf("%f %f", &principal, &monthlyPayment) != 2) {
        return 1;
    }

    while (principal > 0.0f && monthCount < 10) {
        monthCount++;

        interest = principal * INTEREST_RATE;
        principal = principal + interest;

        if (monthlyPayment < interest) {
            principal = principal + PENALTY;
        }

        principal = principal - monthlyPayment;

        printf("Month %d: Remaining %.2f\n", monthCount, principal);
    }

    if (principal <= 0.0f) {
        printf("Loan settled in %d months.\n", monthCount);
    } else {
        printf("Loan settled in 10+ months.\n");
    }

    return 0;
}
