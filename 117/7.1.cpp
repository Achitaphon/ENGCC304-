#include <iostream>
#include <cstring>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {
protected:
    studentNode *start;
    studentNode *now;

public:
    LinkedList() {
        start = NULL;
        now = NULL;
    }

    ~LinkedList() {
        studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }
    }

    void InsNode(char n[], int a, char s, float g) {
        studentNode *newNode = new studentNode;
        strcpy(newNode->name, n);
        newNode->age = a;
        newNode->sex = s;
        newNode->gpa = g;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            now = newNode;
        } else {
            studentNode *walk = start;
            while (walk->next != NULL)
                walk = walk->next;
            walk->next = newNode;
        }
    }

    void DelNode() {
        if (start == NULL || now == NULL) return;

        if (now == start) {
            start = start->next;
            delete now;
            now = start;
            return;
        }

        studentNode *prev = start;
        while (prev->next != now)
            prev = prev->next;

        prev->next = now->next;
        delete now;
        now = prev->next;
    }

    void GoNext() {
        if (now != NULL && now->next != NULL)
            now = now->next;
    }

    virtual void ShowNode() {
        if (now != NULL)
            cout << "[LinkedList] "
                 << now->name << " "
                 << now->age << " "
                 << now->sex << " "
                 << now->gpa << endl;
    }
};

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = start;
    }

    virtual void ShowNode() {
        if (now != NULL)
            cout << "[NewList] "
                 << now->name << " ("
                 << now->age << ") "
                 << now->gpa << endl;
    }
};

int main() {

    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    // ----- listA -----
    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);

    listA.GoNext();
    listA.ShowNode();

    // ----- listB -----
    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);

    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    // ----- Polymorphism -----
    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}
