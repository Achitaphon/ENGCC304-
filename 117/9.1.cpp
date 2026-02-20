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
   Extra helper prototypes
   ======================= */

static void clear_input_line(void);
static int read_menu(void);
static int read_student_fields(char nameOut[20], int *ageOut, char *sexOut, float *gpaOut);
static void print_current_node(struct studentNode *node);

/* =======================
   main (ไว้ก่อนเสมอ)
   ======================= */

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA);

    menu = read_menu();

    while (menu != 0) {

        if (menu == -1) {
            printf("Invalid input. Please enter 0-5.\n");
        } else {

            switch (menu) {

                case 1:
                    AddData(&listA);
                    break;

                case 2:
                    EditData(&listA);
                    break;

                case 3:
                    listA.DelNode();
                    break;

                case 4:
                    FindData(&listA);
                    break;

                case 5:
                    listA.ShowAll();
                    break;

                default:
                    printf("Invalid menu.\n");
                    break;
            }
        }

        menu = read_menu();
    }

    writefile(&listA);
    return 0;
}

/* =======================
   Helper Functions
   ======================= */

static void clear_input_line(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

static int read_menu(void) {
    int value;

    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");

    if (scanf("%d", &value) != 1) {
        clear_input_line();
        return -1;
    }

    return value;
}

static int read_student_fields(char nameOut[20], int *ageOut, char *sexOut, float *gpaOut) {

    if (scanf("%19s %d %c %f", nameOut, ageOut, sexOut, gpaOut) != 4) {
        clear_input_line();
        return 0;
    }

    return 1;
}

static void print_current_node(struct studentNode *node) {

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
   LinkedList Implementation
   ======================= */

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    ClearAll();
}

void LinkedList::ClearAll() {

    struct studentNode *walk = start;

    while (walk != NULL) {
        struct studentNode *temp = walk;
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

    struct studentNode *walk = start;

    if (walk == NULL) {
        printf("(empty)\n");
        return;
    }

    while (walk != NULL) {
        printf("%-19s | age=%3d | sex=%c | gpa=%.2f\n",
               walk->name,
               walk->age,
               walk->sex,
               walk->gpa);

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

void LinkedList::InsNode(char n[], int a, char s, float g) {

    struct studentNode *newNode;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
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
        printf("No current node.\n");
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
        printf("No current node.\n");
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
   Menu Functions
   ======================= */

void AddData(LinkedList *ll) {

    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Input: name age sex gpa : ");

    if (!read_student_fields(name, &age, &sex, &gpa)) {
        printf("Invalid input.\n");
        return;
    }

    ll->GoLast();
    ll->InsNode(name, age, sex, gpa);

    printf("Added.\n");
}

void EditData(LinkedList *ll) {

    char targetName[20];
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Find name to edit : ");

    if (scanf("%19s", targetName) != 1) {
        clear_input_line();
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(targetName) == 0) {
        printf("Not found.\n");
        return;
    }

    printf("Current: ");
    print_current_node(ll->NowNode());

    printf("New data: name age sex gpa : ");

    if (!read_student_fields(name, &age, &sex, &gpa)) {
        printf("Invalid input.\n");
        return;
    }

    ll->EditNode(name, age, sex, gpa);
}

void FindData(LinkedList *ll) {

    char name[20];

    printf("Find name : ");

    if (scanf("%19s", name) != 1) {
        clear_input_line();
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(name) == 0) {
        printf("Not found.\n");
        return;
    }

    printf("FOUND: ");
    print_current_node(ll->NowNode());
}

void readfile(LinkedList *ll) {

    FILE *fp;
    char name[20];
    int age;
    char sex;
    float gpa;

    fp = fopen("student.txt", "r");

    if (fp == NULL) {
        return;
    }

    while (fscanf(fp, "%19s %d %c %f", name, &age, &sex, &gpa) == 4) {
        ll->GoLast();
        ll->InsNode(name, age, sex, gpa);
    }

    fclose(fp);
}

void writefile(LinkedList *ll) {

    FILE *fp;
    struct studentNode *current;

    fp = fopen("student.txt", "w");

    if (fp == NULL) {
        printf("Cannot open file for writing.\n");
        return;
    }

    ll->GoFirst();
    current = ll->NowNode();

    while (current != NULL) {
        fprintf(fp, "%s %d %c %.2f\n",
                current->name,
                current->age,
                current->sex,
                current->gpa);

        ll->GoNext();
        current = ll->NowNode();
    }

    fclose(fp);
}
