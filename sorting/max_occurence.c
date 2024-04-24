#include <stdlib.h> 
  
int mostFrequent(int arr[], int n) 
{ 
    quicksort(arr, arr + n); 
  
    int max_count = 1;
    int res = arr[0];
    int curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else
            curr_count = 1; 
        
        if (curr_count > max_count) { 
            max_count = curr_count; 
            res = arr[i - 1]; 
        } 
    } 
  
    return res; 
} 
  
// Driver program 
int main() 
{ 
    int arr[6] = {1,2,5,2,3,2}; 
    
    int max_curr_value = mostFrequent(arr, 6);
    printf("%d\n", max_curr_value);

    return 0; 
} 
  