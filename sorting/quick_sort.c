#include <stdio.h>
#include <stdlib.h>

int partition(int A_arr[], int p, int r) {
    int i = p - 1;
    int x = A_arr[r];

    for (int j=p; j<r; j++) {
        if (A_arr[j] <= x) {
            i++;
            int temp = A_arr[i];
            A_arr[i] = A_arr[j];
            A_arr[j] = temp;
        }
    }

    A_arr[r] = A_arr[i + 1];
    A_arr[i + 1] = x;

    return i+1;
}

void quick_sort(int A_arr[], int p, int r) {
    if (p < r) {
        int q = partition(A_arr, p ,r);

        quick_sort(A_arr, p, q-1);
        quick_sort(A_arr, q+1,r);
    }
}

int main() {
    int arr[15] = {1,4,3,2,8,5,10,3,2,109,3,2,1,7,7};
    quick_sort(arr, 0, 14);

    for (int i=0; i<15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}