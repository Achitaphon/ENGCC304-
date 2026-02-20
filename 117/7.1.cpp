#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
} studentNode;

typedef struct {
    studentNode *start;
    studentNode *now;
} LinkedList;

int main() {
    LinkedList listA, listB;
    LinkedList *listC;

    listA.start = NULL; listA.now = NULL;
    listB.start = NULL; listB.now = NULL;

    {
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "one"); newNode->age = 1; newNode->sex = 'A'; newNode->gpa = 1.1f; newNode->next = NULL;
        listA.start = newNode; listA.now = newNode;
    }
    {
        studentNode *walk = listA.start;
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "two"); newNode->age = 2; newNode->sex = 'B'; newNode->gpa = 2.2f; newNode->next = NULL;
        while (walk->next != NULL) walk = walk->next;
        walk->next = newNode;
    }
    {
        studentNode *walk = listA.start;
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "three"); newNode->age = 3; newNode->sex = 'C'; newNode->gpa = 3.3f; newNode->next = NULL;
        while (walk->next != NULL) walk = walk->next;
        walk->next = newNode;
    }

    if (listA.now != NULL && listA.now->next != NULL) listA.now = listA.now->next;
    if (listA.now != NULL) {
        printf("[LinkedList] %s %d %c %.1f\n",
               listA.now->name, listA.now->age, listA.now->sex, listA.now->gpa);
    }

    {
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "four"); newNode->age = 4; newNode->sex = 'D'; newNode->gpa = 4.4f; newNode->next = NULL;
        listB.start = newNode; listB.now = newNode;
    }
    {
        studentNode *walk = listB.start;
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "five"); newNode->age = 5; newNode->sex = 'E'; newNode->gpa = 5.5f; newNode->next = NULL;
        while (walk->next != NULL) walk = walk->next;
        walk->next = newNode;
    }
    {
        studentNode *walk = listB.start;
        studentNode *newNode = (studentNode *)malloc(sizeof(studentNode));
        strcpy(newNode->name, "six"); newNode->age = 6; newNode->sex = 'F'; newNode->gpa = 6.6f; newNode->next = NULL;
        while (walk->next != NULL) walk = walk->next;
        walk->next = newNode;
    }

    if (listB.now != NULL && listB.now->next != NULL) listB.now = listB.now->next;

    if (!(listB.start == NULL || listB.now == NULL)) {
        if (listB.now == listB.start) {
            listB.start = listB.start->next;
            free(listB.now);
            listB.now = listB.start;
        } else {
            studentNode *prev = listB.start;
            while (prev->next != listB.now) prev = prev->next;
            prev->next = listB.now->next;
            free(listB.now);
            listB.now = prev->next;
        }
    }

    if (listB.now != NULL) {
        printf("[NewList] %s (%d) %.1f\n",
               listB.now->name, listB.now->age, listB.now->gpa);
    }

    listC = &listA;
    if (listC->now != NULL && listC->now->next != NULL) listC->now = listC->now->next;
    if (listC->now != NULL) {
        printf("[LinkedList] %s %d %c %.1f\n",
               listC->now->name, listC->now->age, listC->now->sex, listC->now->gpa);
    }

    listC = &listB;
    if (listC->now != NULL) {
        printf("[LinkedList] %s %d %c %.1f\n",
               listC->now->name, listC->now->age, listC->now->sex, listC->now->gpa);
    }

    {
        studentNode *temp;
        while (listA.start != NULL) {
            temp = listA.start;
            listA.start = listA.start->next;
            free(temp);
        }
        listA.now = NULL;
    }
    {
        studentNode *temp;
        while (listB.start != NULL) {
            temp = listB.start;
            listB.start = listB.start->next;
            free(temp);
        }
        listB.now = NULL;
    }

    return 0;
}
