#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void GetStudent(struct student child[][10], int *room);

int main(void) {
    struct student children[20][10];
    int group;

    GetStudent(children, &group);

    return 0;
}

void GetStudent(struct student child[][10], int *room) {
    int i;
    int j;

    if (scanf("%d", room) != 1) {
        return;
    }

    for (i = 0; i < *room; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%19s %d %c %f",
                  child[i][j].name,
                  &child[i][j].age,
                  &child[i][j].sex,
                  &child[i][j].gpa);
        }
    }
}

