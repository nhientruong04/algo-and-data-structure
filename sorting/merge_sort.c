#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int A_arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L_arr = (int *) malloc((n1 + 1) * sizeof(int));
    int *R_arr = (int *) malloc((n2 + 1) * sizeof(int));

    for (int i=0; i<n1; i++) {
        L_arr[i] = A_arr[i + p];
    }
    for (int i=0; i<n2; i++) {
        R_arr[i] = A_arr[i + q + 1];
    }
    L_arr[n1] = __INT_MAX__;
    R_arr[n2] = __INT_MAX__;
    
    int i = 0;
    int j = 0;
    
    for (int h=p; h<r+1; h++) {
        if (L_arr[i] <= R_arr[j]) {
            A_arr[h] = L_arr[i];
            i++;
        } else {
            A_arr[h] = R_arr[j];
            j++;
        }
    }

    free(L_arr);
    free(R_arr);
}

void merge_sort(int A_arr[], int p, int r) {
    if (p<r){
        int q = p + ((r - p)/2);

        merge_sort(A_arr, p, q);
        merge_sort(A_arr, q+1, r);
        merge(A_arr, p, q, r);
    }
}

int main() {
    int arr[15] = {1,4,3,2,8,5,10,3,2,109,3,2,1,7,3};
    merge_sort(arr, 0, 14);

    for (int i=0; i<15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}