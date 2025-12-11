#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main(void) {
    char out[20][10];
    int num;
    int i;

    explode("I/Love/You", '/', out, &num);

    for (i = 0; i < num; i++) {
        printf("%s\n", out[i]);
    }
    printf("%d\n", num);

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i;
    int row;
    int col;

    i = 0;
    row = 0;
    col = 0;

    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            str2[row][col] = '\0';
            if (row < 19) {
                row = row + 1;
                col = 0;
            }
        } else if (col < 9) {
            str2[row][col] = str1[i];
            col = col + 1;
        }
        i = i + 1;
    }

    str2[row][col] = '\0';
    *count = row + 1;
}
