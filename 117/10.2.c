#include <stdio.h>

void TowerHanoi(int m, int i, int j);

int main() {

    TowerHanoi(3, 1, 3);

    return 0;
}

void TowerHanoi(int m, int i, int j) {

    int k;

    if (m == 1) {
        printf("Disc 1 from %d to %d\n", i, j);
        return;
    }

    /* เสาอีกต้น = 6 - i - j  (เพราะ 1 + 2 + 3 = 6) */
    k = 6 - i - j;

    /* ย้าย m-1 แผ่น ไปยังเสาช่วย */
    TowerHanoi(m - 1, i, k);

    /* ย้ายแผ่นที่ m */
    printf("Disc %d from %d to %d\n", m, i, j);

    /* ย้าย m-1 จากเสาช่วย ไปยังปลายทาง */
    TowerHanoi(m - 1, k, j);
}
