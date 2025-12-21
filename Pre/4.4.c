#include <stdio.h>

#define SIZE 5

int main(void) {
    int numbers[SIZE];
    int even_count = 0;
    int odd_count = 0;
    int i;

    for (i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            return 1;
        }

        if (numbers[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    printf("--- NUMBER CLASSIFICATION REPORT ---\n");
    printf("Recorded Numbers: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d", numbers[i]);
        if (i < SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Total Even Numbers Found: %d\n", even_count);
    printf("Total Odd Numbers Found: %d\n", odd_count);

    return 0;
}

