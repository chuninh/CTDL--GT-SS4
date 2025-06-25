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
    int number;
    int found =0;
    printf("nhap so muon tim ");
    scanf("%d",&number);
    for (int i=0;i<*quantity;i++) {
        if ((*array)[i] == number) {
            found =1;
            printf("%d ",i);
        }
    }
    if (!found) {
        printf("ko tim thay phan tu trong mang");
    }


}
int main() {
    int *array;
    int quantity;

    imporArray(&array, &quantity);

    free(array);
    return 0;
}
