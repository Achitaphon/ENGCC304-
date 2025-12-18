#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student child);

int main(void) {
    struct student aboy;

    aboy.sex = 'M';
    aboy.gpa = 3.00f;

    upgrade(aboy);

    printf("%.2f\n", aboy.gpa);

    return 0;
}

void upgrade(struct student child) {
    if (child.sex == 'M' || child.sex == 'm') {
        child.gpa = child.gpa * 1.10f;
    } else if (child.sex == 'F' || child.sex == 'f') {
        child.gpa = child.gpa * 1.20f;
    }
}

