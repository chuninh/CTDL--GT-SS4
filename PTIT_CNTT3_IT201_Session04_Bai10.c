#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
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

    char searchName[30];
    int found = 0;
    printf("Nhap ten can tim: ");
    scanf(" %[^\n]", searchName);

    for (int i = 0; i < *n; i++) {
        if (strstr((*array)[i].name, searchName)) {
            printf("ID: %d | Ten: %s | Tuoi: %d\n",
                   (*array)[i].id, (*array)[i].name, (*array)[i].age);
            found = 1;
        }
    }

    if (!found)
        printf("Khong tim thay sinh vien nao co ten chua chuoi \"%s\".\n", searchName);
}

int main() {
    Student *students;
    int count;
    importStudents(&students, &count);
    free(students);
    return 0;
}
