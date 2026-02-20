#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = { 1, 2, 3, 4, 5, 7 };
    int n = 6, find = 5;
    int pos = BinSearch(data, n, find);
    return 0;
}

int BinSearch(int data[], int n, int find) {
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (data[mid] == find) {
            printf("Found %d at %d\n", find, mid);
            return mid;
        }
        else if (data[mid] < find) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("Not Found\n");
    return -1;
}
