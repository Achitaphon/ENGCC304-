#include <stdio.h>

int main() {
    int N, i;
    int studentID, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (i = 0; i < N; i++) {
        if (scanf("%d %d %d %d", &studentID, &score, &totalClasses, &absentClasses) != 4) {
            return 1;
        }

        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0f;

        if (score >= 50 && attendancePercent >= 75.0f) {
            printf("Student %d: PASS\n", studentID);
            passCount++;
        } else {
            printf("Student %d: FAIL - ", studentID);
            if (score < 50 && attendancePercent < 75.0f) {
                printf("Both Score and Attendance\n");
            } else if (score < 50) {
                printf("Low Score\n");
            } else {
                printf("Low Attendance (%.2f%%)\n", attendancePercent);
            }
            failCount++;
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
