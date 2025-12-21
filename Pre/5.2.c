#include <stdio.h>

struct Employee {
    int id;
    int gross_salary;
    int bonus;
    int total_income;
};

int calculate_net_salary(int total_income);

int main(void) {
    struct Employee emp;
    int net_salary;

    if (scanf("%d", &emp.id) != 1) return 1;
    if (scanf("%d", &emp.gross_salary) != 1) return 1;
    if (scanf("%d", &emp.bonus) != 1) return 1;

    emp.total_income = emp.gross_salary + emp.bonus;
    net_salary = calculate_net_salary(emp.total_income);

    printf("--- EMPLOYEE SALARY REPORT ---\n");
    printf("ID: %d\n", emp.id);
    printf("Gross Salary: %d\n", emp.gross_salary);
    printf("Bonus: %d\n", emp.bonus);
    printf("Total Income: %d\n", emp.total_income);
    printf("Net Salary: %d\n", net_salary);

    return 0;
}

int calculate_net_salary(int total_income) {
    float tax_rate;
    int tax_amount;

    if (total_income > 30000) {
        tax_rate = 0.10f;
    } else {
        tax_rate = 0.05f;
    }

    tax_amount = (int)(total_income * tax_rate);
    return total_income - tax_amount;
}

