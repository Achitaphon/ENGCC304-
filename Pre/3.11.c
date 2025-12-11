#include <stdio.h>

int main() {
    int choice;
    float totalCost = 0.0;
    float paidAmount;
    float change;

    do {
        printf("\n--- Vending Machine ---\n");
        printf("1. Coke (15.00)\n");
        printf("2. Water (10.00)\n");
        printf("3. Snack (25.00)\n");
        printf("4. Exit and Pay\n");
        printf("Current Total: %.2f\n", totalCost);

        printf("Select item (1-4): ");
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                totalCost = totalCost + 15.00;
                printf("Item added. Current Total: %.2f\n", totalCost);
                break;
            case 2:
                totalCost = totalCost + 10.00;
                printf("Item added. Current Total: %.2f\n", totalCost);
                break;
            case 3:
                totalCost = totalCost + 25.00;
                printf("Item added. Current Total: %.2f\n", totalCost);
                break;
            case 4:
                printf("Total due: %.2f\n", totalCost);
                break;
            default:
                printf("Invalid choice. Current Total: %.2f\n", totalCost);
                break;
        }

    } while (choice != 4);

    if (totalCost > 0.0) {
        printf("Enter paid amount: ");
        if (scanf("%f", &paidAmount) != 1) {
            return 1;
        }

        if (paidAmount >= totalCost) {
            change = paidAmount - totalCost;
            printf("Purchase successful. Change: %.2f\n", change);
        } else {
            printf("Insufficient payment. Purchase cancelled.\n");
        }
    } else {
        printf("No items purchased. Goodbye!\n");
    }

    return 0;
}
