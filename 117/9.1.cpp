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
   main (ตาม pre-code)
   ======================= */

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA);
    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
    scanf("%d", &menu);

    while (menu != 0) {
        switch (menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: listA.DelNode(); break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
            default: printf("Invalid menu.\n"); break;
        }
        printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);
    }

    writefile(&listA);
    return 0;
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
    struct studentNode *walk = start;
    while (walk != NULL) {
        struct studentNode *tmp = walk;
        walk = walk->next;
        free(tmp);
    }
    start = NULL;
    now = &start;
}

struct studentNode *LinkedList::NowNode() {
    if (now == NULL) return NULL;
    return *now;
}

void LinkedList::GoFirst() {
    now = &start;
}

void LinkedList::GoLast() {
    now = &start;
    if (start == NULL) return;

    while (*now != NULL && (*now)->next != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::GoNext() {
    if (now == NULL) return;
    if (*now == NULL) return;
    now = &((*now)->next);
}

void LinkedList::ShowAll() {
    struct studentNode *walk = start;

    if (walk == NULL) {
        printf("(empty)\n");
        return;
    }

    while (walk != NULL) {
        printf("%s %d %c %.2f\n", walk->name, walk->age, walk->sex, walk->gpa);
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

/* เพิ่มโหนด "ต่อท้าย" ได้ง่ายสุดด้วยการเรียก GoLast() ก่อน แล้วค่อย InsNode() */
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

    /* list empty */
    if (start == NULL) {
        start = newNode;
        now = &start;
        return;
    }

    /* if current slot is NULL (rare), put directly */
    if (*now == NULL) {
        *now = newNode;
        return;
    }

    /* insert AFTER current */
    newNode->next = (*now)->next;
    (*now)->next = newNode;

    /* move now to the new node */
    now = &((*now)->next);
}

void LinkedList::DelNode() {
    struct studentNode *del;
    struct studentNode *nextNode;

    if (now == NULL || *now == NULL) {
        printf("No current node to delete.\n");
        return;
    }

    del = *now;
    nextNode = del->next;

    *now = nextNode;    /* link around */
    free(del);

    /* ถ้าลบแล้ว now กลายเป็น NULL แต่ลิสต์ยังมีข้อมูล -> เลื่อนไปโหนดสุดท้าย */
    if (*now == NULL && start != NULL) {
        GoLast();
    }

    if (start == NULL) {
        now = &start;
    }

    printf("Deleted.\n");
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    /* แก้ "โหนดปัจจุบัน" */
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
   Menu Helper Functions
   ======================= */

void AddData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Input: name age sex gpa : ");
    /* ใส่ space หน้า %c เพื่อกิน newline ที่ค้าง */
    if (scanf("%19s %d %c %f", name, &age, &sex, &gpa) != 4) {
        printf("Invalid input.\n");
        return;
    }

    ll->GoLast();
    ll->InsNode(name, age, sex, gpa);
    printf("Added.\n");
}

void EditData(LinkedList *ll) {
    char findName[20];
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Find name to edit : ");
    if (scanf("%19s", findName) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(findName) == 0) {
        printf("Not found.\n");
        return;
    }

    printf("New data: name age sex gpa : ");
    if (scanf("%19s %d %c %f", name, &age, &sex, &gpa) != 4) {
        printf("Invalid input.\n");
        return;
    }

    ll->EditNode(name, age, sex, gpa);
}

void FindData(LinkedList *ll) {
    char name[20];
    struct studentNode *p;

    printf("Find name : ");
    if (scanf("%19s", name) != 1) {
        printf("Invalid input.\n");
        return;
    }

    if (ll->FindNode(name) == 0) {
        printf("Not found.\n");
        return;
    }

    p = ll->NowNode();
    printf("FOUND: %s %d %c %.2f\n", p->name, p->age, p->sex, p->gpa);
}

/* =======================
   File I/O (ASCII)
   file: student.txt
   format: name age sex gpa
   ======================= */

void readfile(LinkedList *ll) {
    FILE *fp;
    char name[20];
    int age;
    char sex;
    float gpa;

    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        return; /* ยังไม่มีไฟล์ ไม่เป็นไร */
    }

    while (fscanf(fp, "%19s %d %c %f", name, &age, &sex, &gpa) == 4) {
        ll->GoLast();
        ll->InsNode(name, age, sex, gpa);
    }

    fclose(fp);
}

void writefile(LinkedList *ll) {
    FILE *fp;
    struct studentNode *walk;

    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Can't open file for write.\n");
        return;
    }

    /* เขียนจาก start */
    walk = ll->NowNode();
    ll->GoFirst();
    walk = ll->NowNode();

    while (walk != NULL) {
        fprintf(fp, "%s %d %c %.2f\n", walk->name, walk->age, walk->sex, walk->gpa);
        walk = walk->next;
    }

    fclose(fp);
}
