#include <stdio.h>

void reverse(char str1[], char str2[]) {
    int len = 0;
    int i;

    while (str1[len] != '\0') {
        len++;
    }

    if (len > 0 && str1[len - 1] == '\n') {
        len--;
    }

    for (i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';
}

int main(void) {
    char text[50];
    char out[50];

    if (fgets(text, 50, stdin) == NULL) {
        return 1;
    }

    reverse(text, out);
    printf("%s\n", out);

    return 0;
}
