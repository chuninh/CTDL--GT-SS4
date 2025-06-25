#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return 0;
    int mid = (left + right) / 2;
    if (arr[mid] == target)
        return 1;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

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

    if (binarySearchRecursive(*array, 0, *quantity - 1, number)) {
        printf("phan tu co trong mang\n");
    } else {
        printf("phan tu khong co trong mang\n");
    }
}

int main() {
    int *array;
    int quantity;

    imporArray(&array, &quantity);

    free(array);
    return 0;
}
