#include <stdio.h>

#define NUM_STUDENTS 3

struct Student {
    int id;
    int score;
};

int find_max_score_id(struct Student students[], int size);

int main(void) {
    struct Student class_data[NUM_STUDENTS];
    int top_student_id;
    int i;

    for (i = 0; i < NUM_STUDENTS; i++) {
        if (scanf("%d", &class_data[i].id) != 1) return 1;
        if (scanf("%d", &class_data[i].score) != 1) return 1;
    }

    top_student_id = find_max_score_id(class_data, NUM_STUDENTS);

    printf("--- STUDENT SCORE REPORT ---\n");
    printf("ID | Score\n");
    printf("---------\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%d | %d\n", class_data[i].id, class_data[i].score);
    }
    printf("\nTOP PERFORMER ID: %d\n", top_student_id);

    return 0;
}

int find_max_score_id(struct Student students[], int size) {
    int i;
    int max_index = 0;

    for (i = 1; i < size; i++) {
        if (students[i].score > students[max_index].score) {
            max_index = i;
        }
    }
    return students[max_index].id;
}

