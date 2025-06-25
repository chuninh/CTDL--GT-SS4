#include <stdio.h>
#include <stdlib.h>

void imporArray(int **array, int *quantity) {
    printf("nhap so luong phan tu : ");
    scanf("%d", quantity);

    if (*quantity <= 0) {
        printf("So luong ko hop le\n");
        return;
    }

    *array = (int *)malloc(*quantity * sizeof(int));
    if (*array == NULL) {
        printf("bo nho ko du de thuc hien thao tac nay\n");
        exit(1);
    }

    for (int i = 0; i < *quantity; i++) {
        printf("Nhap phan tu mang[%d]: ", i);
        scanf("%d", &(*array)[i]);
    }
    int number;
    int index = 0;
    printf("nhap so muon tim");
    scanf("%d", &number);
    for (int i = 1; i < *quantity; i++) {
        if (number == (*array)[i]) {
            index = i;
        }
    }

    printf(" vi tri cuoi cung cua so can tim la: %d",index);


}

int main() {
    int *array;
    int quantity;
    imporArray(&array, &quantity);

    free(array);
    return 0;
}
