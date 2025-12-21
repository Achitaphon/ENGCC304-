#include <stdio.h>

#define MAX_SIZE 10

int main(void) {
    int data[MAX_SIZE];
    int N;
    int search_value;
    int count = 0;
    int i;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    if (N < 1) N = 1;
    if (N > MAX_SIZE) N = MAX_SIZE;

    for (i = 0; i < N; i++) {
        if (scanf("%d", &data[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%d", &search_value) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (data[i] == search_value) {
            count++;
        }
    }

    printf("--- FREQUENCY ANALYSIS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);
    printf("Recorded Numbers: ");
    for (i = 0; i < N; i++) {
        printf("%d", data[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Search Value: %d\n", search_value);
    printf("Frequency Count: %d\n", count);

    return 0;
}

