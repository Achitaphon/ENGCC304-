#include <stdio.h>

struct Student {
    int student_id;
    int score;
    char grade;
};

void calculate_grade(struct Student *s_ptr);
void display_menu(void);

int main(void) {
    struct Student record = {0, 0, 'U'};
    int choice;

    do {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &record.student_id);
                printf("Enter Score (0-100): ");
                scanf("%d", &record.score);
                calculate_grade(&record);
                printf("Data updated. Grade calculated.\n");
                break;

            case 2:
                if (record.student_id == 0) {
                    printf("No student data has been entered yet (ID is 0).\n");
                } else {
                    printf("\n--- STUDENT REPORT ---\n");
                    printf("ID: %d\n", record.student_id);
                    printf("Score: %d\n", record.score);
                    printf("Grade: %c\n", record.grade);
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

void calculate_grade(struct Student *s_ptr) {
    if (s_ptr->score >= 80) {
        s_ptr->grade = 'A';
    } else if (s_ptr->score >= 70) {
        s_ptr->grade = 'B';
    } else if (s_ptr->score >= 60) {
        s_ptr->grade = 'C';
    } else if (s_ptr->score >= 50) {
        s_ptr->grade = 'D';
    } else {
        s_ptr->grade = 'F';
    }
}

void display_menu(void) {
    printf("\n--- STUDENT RECORD MENU ---\n");
    printf("1. Input/Update Student Data\n");
    printf("2. View Student Report\n");
    printf("3. Exit Program\n");
    printf("Enter choice: ");
}
