#include <stdio.h>

int calculate_area(int length, int width);

int main(void) {
    int input_length;
    int input_width;
    int result_area;

    if (scanf("%d", &input_length) != 1) {
        return 1;
    }
    if (scanf("%d", &input_width) != 1) {
        return 1;
    }

    result_area = calculate_area(input_length, input_width);

    printf("--- RECTANGLE AREA REPORT ---\n");
    printf("Length: %d\n", input_length);
    printf("Width: %d\n", input_width);
    printf("Calculated Area: %d\n", result_area);

    return 0;
}

int calculate_area(int length, int width) {
    return length * width;
}

