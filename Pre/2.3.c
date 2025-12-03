#include <stdio.h>

int main() {
    int termCode;
    float investmentAmount;
    float aprRate = 0.0f;
    float totalInterest = 0.0f;

    if (scanf("%d %f", &termCode, &investmentAmount) != 2) {
        return 1;
    }

    switch (termCode) {
        case 1: 
            if (investmentAmount < 5000.0f) {
                aprRate = 0.03f;
            } else {
                aprRate = 0.04f;
            }
            break;

        case 2: 
            if (investmentAmount < 10000.0f) {
                aprRate = 0.05f;
            } else {
                aprRate = 0.065f;
            }
            break;

        case 3: 
            aprRate = 0.08f;
            break;

        default:
           
            break;
    }

    if (termCode >= 1 && termCode <= 3) {
        totalInterest = investmentAmount * aprRate;
        printf("%.2f\n", totalInterest);
    } else {
        printf("Invalid Term Code\n");
    }

    return 0;
}
