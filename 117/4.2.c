#include <stdio.h>

void go(int ***p, int **z);

int main(void) {
    int b = 10;
    int c = 20;
    int *pb = &b;
    int *pc = &c;
    int **a;

    go(&a, &pb);
    printf("%d %p %p %p\n", **a, *a, a, &a);

    go(&a, &pc);
    printf("%d %p %p %p\n", **a, *a, a, &a);

    return 0;
}

void go(int ***p, int **z) {
    *p = z;
}
