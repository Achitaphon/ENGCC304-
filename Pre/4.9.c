#include <stdio.h>

int main(void) {
    int gross_salary;
    float tax_rate = 0.0f;
    float tax_amount = 0.0f;
    float net_salary = 0.0f;

    if (scanf("%d", &gross_salary) != 1) {
        return 1;
    }

    if (gross_salary < 20000) {
        tax_rate = 0.0f;
    } else if (gross_salary < 50000) {
        tax_rate = 0.05f;
    } else {
        tax_rate = 0.10f;
    }

    tax_amount = (float)gross_salary * tax_rate;
    net_salary = (float)gross_salary - tax_amount;

    printf("--- SALARY CALCULATION REPORT ---\n");
    printf("Gross Salary: %d THB\n", gross_salary);
    printf("Tax Rate Applied: %.0f%%\n", tax_rate * 100.0f);
    printf("Tax Amount Deducted: %.2f THB\n", tax_amount);
    printf("Net Salary: %.2f THB\n", net_salary);

    return 0;
}

