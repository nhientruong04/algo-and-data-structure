#include <stdio.h>

void insertion_sort(int *arr_ptr, int arr_size) {
    int temp; //save current number
    int p = 0; //index to go through array

    while (p + 1 <= arr_size) {
        temp = arr_ptr[p]; 
        int temp_ind = p;
        int reverse_ind = 1; //index for reversing through array

        //loop when current temp still < the next number and index of that number positive
        while (temp < arr_ptr[p - reverse_ind] && (p - reverse_ind) >= 0) {
            arr_ptr[temp_ind] = arr_ptr[p - reverse_ind]; //assign current position with next number
            temp_ind = p - reverse_ind; //assign new index for temp
            arr_ptr[p - reverse_ind] = temp; //assign that number in array with value of temp
            
            reverse_ind++;
        }
        
        p++;
    }
}

void compare_recursive(int A_arr[], int pivot_ind) {
    int pivot_value = A_arr[pivot_ind];
    int compare_ind = pivot_ind - 1;

    if (compare_ind >=0 && pivot_value < A_arr[compare_ind]) {
        A_arr[pivot_ind] = A_arr[compare_ind];
        A_arr[compare_ind] = pivot_value;

        compare_recursive(A_arr, compare_ind);
    }
}

void insertion_sort_recursive(int A_arr[], int q, int r) {
    compare_recursive(A_arr, q);

    if (q <= r) {
        insertion_sort_recursive(A_arr, q+1, r);
    }
}

int main() {
    int arr[7] = {3, 1, 4, 2, 7, 6, 5};
    insertion_sort_recursive(arr, 0, 6);
    
    for (int i=0; i<7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
