#include <stdio.h>

#define MAX_SIZE 10
#define UNVISITED 0
#define VISITED 1

int main(void) {
    int data[MAX_SIZE];
    int status[MAX_SIZE];
    int freq[MAX_SIZE];
    int N;
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        status[i] = UNVISITED;
        freq[i] = 0;
    }

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

    for (i = 0; i < N; i++) {
        if (status[i] == VISITED) {
            continue;
        }

        freq[i] = 1;
        status[i] = UNVISITED;

        for (j = i + 1; j < N; j++) {
            if (status[j] == VISITED) {
                continue;
            }
            if (data[j] == data[i]) {
                freq[i]++;
                status[j] = VISITED;
            }
        }
    }

    printf("--- FREQUENCY ANALYSIS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);
    printf("Recorded Numbers: ");
    for (i = 0; i < N; i++) {
        printf("%d", data[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");

    printf("--- FREQUENCY TABLE ---\n");
    printf("Number | Frequency\n");
    printf("------ | ---------\n");

    for (i = 0; i < N; i++) {
        if (status[i] == VISITED) {
            continue;
        }
        printf("%d | %d\n", data[i], freq[i]);
    }

    return 0;
}

