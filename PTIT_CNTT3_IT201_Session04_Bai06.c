#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Student;

void importStudents(Student **array, int *n) {
    *n = 5;
    *array = malloc(*n * sizeof(Student));
    if (!*array) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhap sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &((*array)[i].id));
        printf("Ten: ");
        scanf(" %[^\n]", (*array)[i].name);
        printf("Tuoi: ");
        scanf("%d", &((*array)[i].age));
    }

    int searchId;
    int found = 0;
    printf("Nhap ID can tim: ");
    scanf("%d", &searchId);
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i].id == searchId) {
            printf("Tim thay:\nID: %d\nTen: %s\nTuoi: %d\n",(*array)[i].id, (*array)[i].name, (*array)[i].age);
            found = 1;

        }
    }
    if (!found) printf("Khong tim thay sinh vien co ID do.\n");
}

int main() {
    Student *students;
    int count;
    importStudents(&students, &count);
    free(students);
    return 0;
}
