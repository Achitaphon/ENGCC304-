#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input_data.csv"
#define NUM_COUNT 5

int main() {
    FILE *fptr;
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int total_sum;

    fptr = fopen(FILENAME, "r");

    if (fptr == NULL)
    {
        printf("ERROR: Could not open file %s for reading. Make sure the file exists.\n", FILENAME);
        exit(1);
    }

    if (fscanf(fptr, "%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5) != NUM_COUNT)
    {
        printf("ERROR: Failed to read data from %s.\n", FILENAME);
        fclose(fptr);
        exit(1);
    }

    total_sum = num1 + num2 + num3 + num4 + num5;

    fclose(fptr);

    printf("--- FILE READING PROCESS ---\n");
    printf("Reading data from %s...\n", FILENAME);
    printf("File reading complete.\n");

    printf("\n--- DATA ANALYSIS REPORT ---\n");
    printf("Data read: %d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);
    printf("Total Sum: %d\n", total_sum);

    return 0;
}
