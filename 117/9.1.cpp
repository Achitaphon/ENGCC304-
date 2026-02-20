#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =======================
   Pre-code (KEEP STYLE)
   ======================= */

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();

    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    void GoFirst();
    void GoLast();
    void ShowAll();
    int  FindNode(char n[]);
    struct studentNode *NowNode();
    void EditNode(char n[], int a, char s, float g);

private:
    void ClearAll();
};

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll);

/* =======================
   Helper Prototypes
   ======================= */

static void flush_line(void);
static int read_menu_choice(void);
static int read_student_record(char nameOut[20], int *ageOut, char *sexOut, float *gpaOut);
static void show_one(struct studentNode *node);
static void show_title(void);

/* =======================
   main (ไว้ก่อนเสมอ)
   ======================= */

int main() {
    LinkedList listA;
    int menuChoice;

    readfile(&listA);

    show_title();
    menuChoice = read_menu_choice();

    while (menuChoice != 0) {
        if (menuChoice == 1) {
            AddData(&listA);
        } else if (menuChoice == 2) {
            EditData(&listA);
        } else if (menuChoice == 3) {
            listA.DelNode();
        } else if (menuChoice == 4) {
            FindData(&listA);
        } else if (menuChoice == 5) {
            listA.ShowAll();
        } else {
            printf("Invalid menu. Please choose 0-5.\n");
        }

        menuChoice = read_menu_choice();
    }

    writefile(&listA);
    return 0;
}

/* =======================
   Helper Implementations
   ======================= */

static void show_title(void) {
    printf("Student Linked List (ASCII file)\n");
    printf("--------------------------------\n");
}

static void flush_line(void) {
    int ch;
    ch = getchar();
    while (ch != '\n' && ch != EOF) {
        ch = getchar();
    }
}

static int read_menu_choice(void) {
    int choice;
    int ok;

    printf("\nMenu:\n");
    printf("  (1) Add\n");
    printf("  (2) Edit\n");
    printf("  (3) Delete (current)\n");
    printf("  (4) Find (by name)\n");
    printf("  (5) Show all\n");
    printf("  (0) Exit\n");
    printf("Select : ");

    ok = scanf("%d", &choice);
    if (ok != 1) {
        flush_line();
        return -1;
    }

    return choice;
}

static int read_student_record(char nameOut[20], int *ageOut, char *sexOut, float *gpaOut) {
    int ok;

    ok = scanf("%19s %d %c %f", nameOut, ageOut, sexOut, gpaOut);
    if (ok != 4) {
        flush_line();
        return 0;
    }

    return 1;
}

static void show_one(struct studentNode *node) {
    if (node == NULL) {
        printf("(no current node)\n");
        return;
    }

    printf("%-19s | age=%3d | sex=%c | gpa=%.2f\n",
           node->name,
           node->age,
           node->sex,
           node->gpa);
}

/* =======================
   LinkedList Implement
   ======================= */

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    ClearAll();
}

void LinkedList::ClearAll() {
    struct studentNode *walk;

    walk = start;
    while (walk != NULL) {
        struct studentNode *temp;
        temp = walk;
        walk = walk->next;
        free(temp);
    }

    start = NULL;
    now = &start;
}

struct studentNode *LinkedList::NowNode() {
    if (now == NULL) {
        return NULL;
    }
    return *now;
}

void LinkedList::GoFirst() {
    now = &start;
}

void LinkedList::GoLast() {
    now = &start;

    if (start == NULL) {
        return;
    }

    while (*now != NULL && (*now)->next != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::GoNext() {
    if (now == NULL) {
        return;
    }
    if (*now == NULL) {
        return;
    }
    now = &((*now)->next);
}

void LinkedList::ShowAll() {
    struct studentNode *walk;

    walk = start;
    if (walk == NULL) {
        printf("(empty)\n");
        return;
    }

    while (walk != NULL) {
        show_one(walk);
        walk = walk->next;
    }
}

int LinkedList::FindNode(char n[]) {
    now = &start;

    while (*now != NULL) {
        if (strcmp((*now)->name, n) == 0) {
            return 1;
        }
        now = &((*now)->next);
    }

    return 0;
}

/* Insert AFTER current position (append: call GoLast() before InsNode) */
void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode *newNode;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        printf("Out of memory.\n");
        return;
    }

    strncpy(newNode->name, n, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
        now = &start;
        return;
    }

    if (*now == NULL) {
        *now = newNode;
        return;
    }

    newNode->next = (*now)->next;
    (*now)->next = newNode;
    now = &((*now)->next);
}

void LinkedList::DelNode() {
    struct studentNode *deleteNode;
    struct studentNode *nextNode;

    if (now == NULL || *now == NULL) {
        printf("No current node to delete.\n");
        return;
    }

    deleteNode = *now;
    nextNode = deleteNode->next;

    *now = nextNode;
    free(deleteNode);

    if (start == NULL) {
        now = &start;
    } else if (*now == NULL) {
        GoLast();
    }

    printf("Deleted.\n");
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    if (now == NULL || *now == NULL) {
        printf("No current node to edit.\n");
        return;
    }

    strncpy((*now)->name, n, sizeof((*now)->name) - 1);
    (*now)->name[sizeof((*now)->name) - 1] = '\0';
    (*now)->age = a;
    (*now)->sex = s;
    (*now)->gpa = g;

    printf("Edited.\n");
}

/* =======================
   Menu Actions
   ======================= */

void AddData(LinkedList *ll) {
    char inputName[20];
    int inputAge;
    char inputSex;
    float inputGpa;

    printf("Input: name age sex gpa : ");
    if (!read_student_record(inputName, &inputAge, &inputSex, &inputGpa)) {
        printf("Invalid input.\n");
        return;
    }

    ll->GoLast();
    ll->InsNode(inputName, inputAge, inputSex, inputGpa);
    printf("Added.\n");
}

void EditData(LinkedList *ll) {
    char searchName[20];
    char newName[20];
    int newAge;
    char newSex;
    float newGpa;

    printf("Find name to edit : ");
    if (scanf("%19s", searchName) != 1) {
        flush_line();
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(searchName) == 0) {
        printf("Not found.\n");
        return;
    }

    printf("Current: ");
    show_one(ll->NowNode());

    printf("New data: name age sex gpa : ");
    if (!read_student_record(newName, &newAge, &newSex, &newGpa)) {
        printf("Invalid input.\n");
        return;
    }

    ll->EditNode(newName, newAge, newSex, newGpa);
}

void FindData(LinkedList *ll) {
    char searchName[20];

    printf("Find name : ");
    if (scanf("%19s", searchName) != 1) {
        flush_line();
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(searchName) == 0) {
        printf("Not found.\n");
        return;
    }

    printf("FOUND: ");
    show_one(ll->NowNode());
}

/* =======================
   File I/O (ASCII)
   file: student.txt
   format: name age sex gpa
   ======================= */

void readfile(LinkedList *ll) {
    FILE *fileHandle;
    char fileName[20];
    int fileAge;
    char fileSex;
    float fileGpa;

    fileHandle = fopen("student.txt", "r");
    if (fileHandle == NULL) {
        return;
    }

    while (fscanf(fileHandle, "%19s %d %c %f", fileName, &fileAge, &fileSex, &fileGpa) == 4) {
        ll->GoLast();
        ll->InsNode(fileName, fileAge, fileSex, fileGpa);
    }

    fclose(fileHandle);
}

void writefile(LinkedList *ll) {
    FILE *fileHandle;
    struct studentNode *current;

    fileHandle = fopen("student.txt", "w");
    if (fileHandle == NULL) {
        printf("Can't open student.txt for writing.\n");
        return;
    }

    ll->GoFirst();
    current = ll->NowNode();

    while (current != NULL) {
        fprintf(fileHandle, "%s %d %c %.2f\n",
                current->name,
                current->age,
                current->sex,
                current->gpa);

        ll->GoNext();
        current = ll->NowNode();
    }

    fclose(fileHandle);
}
