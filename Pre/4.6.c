#include <stdio.h>

#define STUDENTS 5

int main(void) {
    int scores[STUDENTS];
    int sum = 0;
    float average;
    int above_average_count = 0;
    int i;

    for (i = 0; i < STUDENTS; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
        }
        sum += scores[i];
    }

    average = (float)sum / STUDENTS;

    for (i = 0; i < STUDENTS; i++) {
        if (scores[i] > average) {
            above_average_count++;
        }
    }

    printf("--- STUDENT SCORE ANALYSIS REPORT ---\n");
    printf("Recorded Scores: ");
    for (i = 0; i < STUDENTS; i++) {
        printf("%d", scores[i]);
        if (i < STUDENTS - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("Total Sum: %d\n", sum);
    printf("Average Score: %.2f\n", average);
    printf("Number of Scores Above Average: %d\n", above_average_count);

    return 0;
}

