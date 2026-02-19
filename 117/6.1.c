#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
void ShowBack(struct studentNode *start);

struct studentNode *AddNode(struct studentNode **start, const char *name, int age, char sex, float gpa);
void InsNode(struct studentNode *now, const char *name, int age, char sex, float gpa);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode **start, struct studentNode **now);

int main(void) {
    struct studentNode *start, *now;

    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(&now);

    DelNode(&start, &now);
    ShowAll(start);

    DelNode(&start, &now);
    ShowAll(start);

    DelNode(&start, &now);
    ShowAll(start);

    /* optional: check back links */
    /* ShowBack(start); */

    while (start != NULL) {
        struct studentNode *tmp = start;
        start = start->next;
        free(tmp);
    }

    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

void ShowBack(struct studentNode *start) {
    struct studentNode *walk = start;

    if (walk == NULL) {
        printf("\n");
        return;
    }

    while (walk->next != NULL) {
        walk = walk->next;
    }

    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->back;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, const char *name, int age, char sex, float gpa) {
    struct studentNode *newNode;
    struct studentNode *walk;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        return NULL;
    }

    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
        return newNode;
    }

    walk = *start;
    while (walk->next != NULL) {
        walk = walk->next;
    }

    walk->next = newNode;
    newNode->back = walk;

    return newNode;
}

void InsNode(struct studentNode *now, const char *name, int age, char sex, float gpa) {
    struct studentNode *newNode;
    struct studentNode *prev;

    if (now == NULL) {
        return;
    }

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        return;
    }

    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    prev = now->back;

    newNode->next = now;
    newNode->back = prev;
    now->back = newNode;

    if (prev != NULL) {
        prev->next = newNode;
    }
}

void GoBack(struct studentNode **now) {
    if (now == NULL || *now == NULL) {
        return;
    }
    if ((*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode **start, struct studentNode **now) {
    struct studentNode *cur;
    struct studentNode *prev;
    struct studentNode *next;

    if (start == NULL || now == NULL || *now == NULL) {
        return;
    }

    cur = *now;
    prev = cur->back;
    next = cur->next;

    if (prev != NULL) {
        prev->next = next;
    } else {
        *start = next;
    }

    if (next != NULL) {
        next->back = prev;
    }

    if (next != NULL) {
        *now = next;
    } else {
        *now = prev;
    }

    free(cur);
}
