#include <stdio.h>

void handleWorkday(int hour);

int main() {
    int dayCode, hour;
  
    if (scanf("%d %d", &dayCode, &hour) != 2){
        return 1;
    }

    switch (dayCode)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            handleWorkday(hour);
            break;
        case 6:
        case 7:
            printf("Weekend Relax Mode\n");
            break;
        default:
            printf("Invalid Day Code\n");
            break;
    }

    return 0;
}

void handleWorkday(int hour) {

    if (hour >= 8 && hour <= 17)
    {
        printf("System Running (Workday)\n");
    }
    else
    {
        printf("System Idle (Off-hours)\n");
    }
}
