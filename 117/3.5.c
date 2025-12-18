#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

struct student (*GetStudent(int *room))[10];

int main(void) {
    struct student (*children)[10];
    int group;

    children = GetStudent(&group);

    free(children);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    struct student (*children)[10];
    int i;
    int j;

    if (scanf("%d", room) != 1) {
        return NULL;
    }

    children = malloc(sizeof(struct student) * (*room) * 10);
    if (children == NULL) {
        return NULL;
    }

    for (i = 0; i < *room; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%19s %d %c %f",
                  children[i][j].name,
                  &children[i][j].age,
                  &children[i][j].sex,
                  &children[i][j].gpa);
        }
    }

    return children;
}
