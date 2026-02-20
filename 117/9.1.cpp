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
    struct studentNode *start, *now;

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

int main() {
    LinkedList listA;
    int menu;

    readfile(&listA);
    printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
    scanf("%d", &menu);

    while (menu != 0) {
        switch (menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: listA.DelNode(); break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
        printf(" Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
        scanf("%d", &menu);
    }

    writefile(&listA);
    return 0;
}

/* =======================
   LinkedList Implementation
   ======================= */

LinkedList::LinkedList() {
    start = NULL;
    now = NULL;
}

LinkedList::~LinkedList() {
    ClearAll();
}

void LinkedList::ClearAll() {
    struct studentNode *walk;
    struct studentNode *temp;

    walk = start;
    while (walk != NULL) {
        temp = walk;
        walk = walk->next;
        free(temp);
    }

    start = NULL;
    now = NULL;
}

struct studentNode *LinkedList::NowNode() {
    return now;
}

void LinkedList::GoFirst() {
    now = start;
}

void LinkedList::GoLast() {
    struct studentNode *walk;

    if (start == NULL) {
        now = NULL;
        return;
    }

    walk = start;
    while (walk->next != NULL) {
        walk = walk->next;
    }

    now = walk;
}

void LinkedList::GoNext() {
    if (now == NULL) {
        return;
    }

    if (now->next == NULL) {
        return;
    }

    now = now->next;
}

void LinkedList::ShowAll() {
    struct studentNode *walk;
    int count;

    walk = start;
    count = 0;

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

        count = count + 1;
        walk = walk->next;
    }

    printf("Total records: %d\n", count);
}

int LinkedList::FindNode(char n[]) {
    /* NOTE: 'n' is fixed by pre-code. Use meaningful local variable instead. */
    struct studentNode *walk;
    char *targetName;

    targetName = n;
    walk = start;

    while (walk != NULL) {
        if (strcmp(walk->name, targetName) == 0) {
            now = walk;
            return 1;
        }
        walk = walk->next;
    }

    now = NULL;
    return 0;
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    /* NOTE: parameter names are fixed by pre-code -> map to meaningful locals */
    char *inputName;
    int inputAge;
    char inputSex;
    float inputGpa;

    struct studentNode *newNode;
    struct studentNode *walk;

    inputName = n;
    inputAge = a;
    inputSex = s;
    inputGpa = g;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL) {
        printf("Out of memory.\n");
        return;
    }

    strncpy(newNode->name, inputName, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';
    newNode->age = inputAge;
    newNode->sex = inputSex;
    newNode->gpa = inputGpa;
    newNode->next = NULL;

    /* Append to the end to keep order stable and easy to trace */
    if (start == NULL) {
        start = newNode;
        now = newNode;
        return;
    }

    walk = start;
    while (walk->next != NULL) {
        walk = walk->next;
    }

    walk->next = newNode;
    now = newNode;
}

void LinkedList::DelNode() {
    struct studentNode *walk;
    struct studentNode *prev;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (now == NULL) {
        printf("No current node.\n");
        return;
    }

    /* Delete head */
    if (now == start) {
        start = start->next;
        free(now);
        now = start;
        printf("Deleted.\n");
        return;
    }

    /* Find previous node */
    prev = NULL;
    walk = start;

    while (walk != NULL && walk != now) {
        prev = walk;
        walk = walk->next;
    }

    if (walk == NULL) {
        /* Current pointer is not in list (safety case) */
        now = start;
        printf("Delete failed (invalid current).\n");
        return;
    }

    prev->next = now->next;
    free(now);

    /* Move now to next, or back to head if at end */
    now = prev->next;
    if (now == NULL) {
        now = start;
    }

    printf("Deleted.\n");
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    /* NOTE: parameter names are fixed by pre-code -> map to meaningful locals */
    char *newName;
    int newAge;
    char newSex;
    float newGpa;

    if (now == NULL) {
        printf("No current node to edit.\n");
        return;
    }

    newName = n;
    newAge = a;
    newSex = s;
    newGpa = g;

    strncpy(now->name, newName, sizeof(now->name) - 1);
    now->name[sizeof(now->name) - 1] = '\0';
    now->age = newAge;
    now->sex = newSex;
    now->gpa = newGpa;

    printf("Edited.\n");
}

/* =======================
   Menu Functions
   ======================= */

void AddData(LinkedList *ll) {
    char inputName[20];
    int inputAge;
    char inputSex;
    float inputGpa;
    int ok;

    printf("Input: name age sex gpa : ");
    ok = scanf("%19s %d %c %f", inputName, &inputAge, &inputSex, &inputGpa);
    if (ok != 4) {
        printf("Invalid input.\n");
        return;
    }

    /* Basic validation to improve stability */
    if (inputAge < 0 || inputAge > 150) {
        printf("Invalid age.\n");
        return;
    }

    if (!(inputSex == 'M' || inputSex == 'm' || inputSex == 'F' || inputSex == 'f')) {
        printf("Invalid sex (use M/F).\n");
        return;
    }

    if (inputGpa < 0.0f || inputGpa > 4.0f) {
        printf("Invalid GPA (0.00 - 4.00).\n");
        return;
    }

    ll->InsNode(inputName, inputAge, inputSex, inputGpa);
    printf("Added.\n");
}

void EditData(LinkedList *ll) {
    char findName[20];
    char newName[20];
    int newAge;
    char newSex;
    float newGpa;
    int found;
    int ok;

    printf("Find name to edit : ");
    ok = scanf("%19s", findName);
    if (ok != 1) {
        printf("Invalid input.\n");
        return;
    }

    found = ll->FindNode(findName);
    if (found == 0) {
        printf("Not found.\n");
        return;
    }

    printf("Current: ");
    if (ll->NowNode() != NULL) {
        printf("%s %d %c %.2f\n",
               ll->NowNode()->name,
               ll->NowNode()->age,
               ll->NowNode()->sex,
               ll->NowNode()->gpa);
    }

    printf("New data: name age sex gpa : ");
    ok = scanf("%19s %d %c %f", newName, &newAge, &newSex, &newGpa);
    if (ok != 4) {
        printf("Invalid input.\n");
        return;
    }

    if (newAge < 0 || newAge > 150) {
        printf("Invalid age.\n");
        return;
    }

    if (!(newSex == 'M' || newSex == 'm' || newSex == 'F' || newSex == 'f')) {
        printf("Invalid sex (use M/F).\n");
        return;
    }

    if (newGpa < 0.0f || newGpa > 4.0f) {
        printf("Invalid GPA (0.00 - 4.00).\n");
        return;
    }

    ll->EditNode(newName, newAge, newSex, newGpa);
}

void FindData(LinkedList *ll) {
    char findName[20];
    int ok;
    int found;
    struct studentNode *p;

    printf("Find name : ");
    ok = scanf("%19s", findName);
    if (ok != 1) {
        printf("Invalid input.\n");
        return;
    }

    found = ll->FindNode(findName);
    if (found == 0) {
        printf("Not found.\n");
        return;
    }

    p = ll->NowNode();
    printf("FOUND: %s %d %c %.2f\n",
           p->name,
           p->age,
           p->sex,
           p->gpa);
}

/* =======================
   File I/O (ASCII)
   file: student.txt
   format: name age sex gpa
   ======================= */

void readfile(LinkedList *ll) {
    FILE *fp;
    char fileName[20];
    int fileAge;
    char fileSex;
    float fileGpa;
    int ok;

    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (1) {
        ok = fscanf(fp, "%19s %d %c %f", fileName, &fileAge, &fileSex, &fileGpa);
        if (ok != 4) {
            break;
        }

        /* Skip bad records to improve stability */
        if (fileAge < 0 || fileAge > 150) {
            continue;
        }
        if (!(fileSex == 'M' || fileSex == 'm' || fileSex == 'F' || fileSex == 'f')) {
            continue;
        }
        if (fileGpa < 0.0f || fileGpa > 4.0f) {
            continue;
        }

        ll->InsNode(fileName, fileAge, fileSex, fileGpa);
    }

    fclose(fp);
}

void writefile(LinkedList *ll) {
    FILE *fp;
    struct studentNode *walk;

    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Can't open student.txt for writing.\n");
        return;
    }

    walk = ll->NowNode();
    ll->GoFirst();
    walk = ll->NowNode();

    while (walk != NULL) {
        fprintf(fp, "%s %d %c %.2f\n",
                walk->name,
                walk->age,
                walk->sex,
                walk->gpa);

        walk = walk->next;
    }

    fclose(fp);
}
