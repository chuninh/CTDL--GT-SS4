#include <stdio.h>
#include <stdlib.h>

void imporArray(int **array, int *quantity) {
    printf("Nhap so luong phan tu: ");
    scanf("%d", quantity);

    if (*quantity <= 0) {
        printf("So luong khong hop le\n");
        return;
    }

    *array = (int *)malloc(*quantity * sizeof(int));
    if (*array == NULL) {
        printf("Bo nho khong du de thuc hien thao tac nay\n");
        exit(1);
    }

    for (int i = 0; i < *quantity; i++) {
        printf("Nhap phan tu mang[%d]: ", i);
        scanf("%d", &(*array)[i]);
    }

    for (int i = 0; i < *quantity - 1; i++) {
        for (int j = 0; j < *quantity - i - 1; j++) {
            if ((*array)[j] > (*array)[j + 1]) {
                int temp = (*array)[j];
                (*array)[j] = (*array)[j + 1];
                (*array)[j + 1] = temp;
            }
        }
    }

    int number;
    printf("Nhap phan tu muon tim: ");
    scanf("%d", &number);

    int left = 0;
    int right = *quantity - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if ((*array)[mid] == number) {
            printf("Vi tri cua so muon tim la %d\n", mid);
            found = 1;
            break;
        } else if ((*array)[mid] < number) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu trong mang\n");
    }
}

int main() {
    int *array;
    int quantity;

    imporArray(&array, &quantity);

    free(array);
    return 0;
}
