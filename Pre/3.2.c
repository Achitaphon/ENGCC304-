#include <stdio.h>

struct Student {
    char name[50];
    int studentId;
    float score;
};

int main(void)
{
    int N, i;
    struct Student students[100];

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (scanf("%d %f %s", &students[i].studentId,
                           &students[i].score,
                            students[i].name) != 3) {
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n",
               students[i].studentId,
               students[i].name,
               students[i].score);
    }

    return 0;
}
