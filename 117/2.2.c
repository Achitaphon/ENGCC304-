#include <stdio.h>

char* reverse(char str1[]) {
    static char str2[50];
    int len = 0;
    int i;

    while (str1[len] != '\0' && str1[len] != '\n') {
        len++;
    }

    for (i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';

    return str2;
}

int main(void) {
    char text[50];
    char *out;

    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    out = reverse(text);
    printf("%s\n", out);

    return 0;
}
