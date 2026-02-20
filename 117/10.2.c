#include <stdio.h>

void TowerHanoi(int m, int i, int j);

int main() {
    TowerHanoi(3, 1, 3);
    return 0;
}

void TowerHanoi(int m, int i, int j) {
    const int PEG_A = 1;
    const int PEG_B = 2;
    const int PEG_C = 3;
    const int PEG_SUM = PEG_A + PEG_B + PEG_C;

    int diskCount;
    int fromPeg;
    int toPeg;
    int helperPeg;

    diskCount = m;
    fromPeg = i;
    toPeg = j;

    if (diskCount == 1) {
        printf("Disc 1 from %d to %d\n", fromPeg, toPeg);
        return;
    }

    helperPeg = PEG_SUM - fromPeg - toPeg;

    TowerHanoi(diskCount - 1, fromPeg, helperPeg);

    printf("Disc %d from %d to %d\n", diskCount, fromPeg, toPeg);

    TowerHanoi(diskCount - 1, helperPeg, toPeg);
}
