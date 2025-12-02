#include <stdio.h>

#define LEVEL_ADMIN 3
#define LEVEL_MANAGER 2
#define STATUS_ACTIVE 1
#define MIN_AGE_FOR_LEVEL2 25

#define ACCESS_TRUE 1
#define ACCESS_FALSE 0

int checkAccess(int clearanceLevel, int age, int isActive);

int main() {
    int clearanceLevel;
    int age;
    int isActive;
    int hasAccess;

    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3)
    {
        return 1;
    }

    hasAccess = checkAccess(clearanceLevel, age, isActive);

    if (hasAccess == ACCESS_TRUE)
    {
        printf("Access Granted\n");
    }
    else
    {
        printf("Access Denied\n");
    }

    return 0;
}

int checkAccess(int clearanceLevel, int age, int isActive) {
    int result;

    result = ACCESS_FALSE;

    if (isActive == STATUS_ACTIVE)
    {
        if (clearanceLevel == LEVEL_ADMIN)
        {
            result = ACCESS_TRUE;
        }
        else
        {
            if (clearanceLevel == LEVEL_MANAGER && age >= MIN_AGE_FOR_LEVEL2)
            {
                result = ACCESS_TRUE;
            }
        }
    }

    return result;
}
