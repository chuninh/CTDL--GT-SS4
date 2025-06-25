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

    int found =0;
    for (int i =0;i < *quantity/2;i++) {
        for (int j =*quantity-i-1;j>=*quantity/2;j--) {
            if (i+j ==*quantity-1) {
                printf("cap doi xung :(%d,%d)\n",(*array)[i],(*array)[j]);
                found =1;
            }
        }
    }
    if (!found) {
        printf("ko co cap doi xung");
    }


}

int main() {
    int *array;
    int quantity;
    imporArray(&array, &quantity);

    free(array);
    return 0;
}
