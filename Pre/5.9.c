#include <stdio.h>
#include <ctype.h>

struct Product {
    int item_id;
    float cost_price;
    float sell_price;
    int stock_quantity;
};

float calculate_total_profit(float cost, float sell, int qty);
float calculate_profit_percentage(float cost, float sell);

int main(void) {
    struct Product item;
    float total_profit;
    float profit_percent;

    char id_input[32];
    int i;

    if (scanf("%31s", id_input) != 1) return 1;
    if (scanf("%f", &item.cost_price) != 1) return 1;
    if (scanf("%f", &item.sell_price) != 1) return 1;
    if (scanf("%d", &item.stock_quantity) != 1) return 1;

    item.item_id = 0;
    for (i = 0; id_input[i] != '\0'; i++) {
        if (isdigit((unsigned char)id_input[i])) {
            item.item_id = item.item_id * 10 + (id_input[i] - '0');
        }
    }

    total_profit = calculate_total_profit(item.cost_price, item.sell_price, item.stock_quantity);
    profit_percent = calculate_profit_percentage(item.cost_price, item.sell_price);

    printf("--- INVENTORY PROFIT REPORT ---\n");
    printf("Item ID: %d\n", item.item_id);
    printf("Cost Price: %.2f, Sell Price: %.2f, Stock: %d\n",
           item.cost_price, item.sell_price, item.stock_quantity);
    printf("Total Profit: %.2f\n", total_profit);
    printf("Profit Percentage: %.2f%%\n", profit_percent);

    if (total_profit > 0.0f) {
        printf("Status: Profit!\n");
    } else if (total_profit < 0.0f) {
        printf("Status: Loss!\n");
    } else {
        printf("Status: Break Even.\n");
    }

    return 0;
}

float calculate_total_profit(float cost, float sell, int qty) {
    return (sell - cost) * (float)qty;
}

float calculate_profit_percentage(float cost, float sell) {
    float unit_profit;

    if (cost == 0.0f) {
        return 0.0f;
    }

    unit_profit = sell - cost;
    return (unit_profit / cost) * 100.0f;
}

