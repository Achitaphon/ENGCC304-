#include <stdio.h>

#define VAT_RATE 0.07

struct Item {
    char name[50];
    float unitPrice;
    int quantity;
};

int main() {
    int N;
    int i;
    float subTotal;
    float totalVAT;
    float grandTotal;

    scanf("%d", &N);

    struct Item items[N];

    subTotal = 0.0;
    totalVAT = 0.0;
    grandTotal = 0.0;

    printf("--- RECEIPT ---\n");

    for (i = 0; i < N; i++) {
        float itemCost;

        scanf("%s", items[i].name);
        scanf("%f", &items[i].unitPrice);
        scanf("%d", &items[i].quantity);

        itemCost = items[i].unitPrice * items[i].quantity;

        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, itemCost);

        subTotal = subTotal + itemCost;
    }

    totalVAT = subTotal * VAT_RATE;
    grandTotal = subTotal + totalVAT;

    printf("-------------\n");
    printf("Subtotal: %.2f\n", subTotal);
    printf("VAT (7%%): %.2f\n", totalVAT);
    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}

