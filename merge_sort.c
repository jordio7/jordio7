#include<stdio.h>

void merge_sort(int arr[], int low, int high){
    if (low < high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr ,mid+1, high);
        merge(arr, low, mid, high);
    }  
}
void merge(int arr[], int low, int mid, int high){
    int x = mid-low+1;
    int y = high-mid;

    int left[x], right[y];
    for(int i = 0; i < x; i++) left[i] = arr[low + i];
    for(int i = 0; i < y; i++) right[i] = arr[mid + 1 + i];

    int k = low, i = 0, j = 0;
    while (i < x && j < y){
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < x){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < y)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
      
}   

int main(int argc, char const *argv[])
{
    int arr[] = {1,5,3,7,6};

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    merge_sort(arr, 0, 5);
    
    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
 
// // Merges two subarrays of arr[].
// // First subarray is arr[l..m]
// // Second subarray is arr[m+1..r]
// void merge(int arr[], int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1;
//     int n2 = r - m;
 
//     // Create temp arrays
//     int L[n1], R[n2];
 
//     // Copy data to temp arrays L[] and R[]
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
 
//     // Merge the temp arrays back into arr[l..r
//     i = 0;
//     j = 0;
//     k = l;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         }
//         else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     // Copy the remaining elements of L[],
//     // if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     // Copy the remaining elements of R[],
//     // if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
 
// // l is for left index and r is right index of the
// // sub-array of arr to be sorted
// void mergeSort(int arr[], int l, int r)
// {
//     if (l < r) {
//         int m = l + (r - l) / 2;
 
//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
 
//         merge(arr, l, m, r);
//     }
// }
 
// // Function to print an array
// void printArray(int A[], int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         printf("%d ", A[i]);
//     printf("\n");
// }
 
// // Driver code
// int main()
// {
//     int arr[] = { 12, 11, 13, 5, 6, 7 };
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
 
//     printf("Given array is \n");
//     printArray(arr, arr_size);
 
//     mergeSort(arr, 0, arr_size - 1);
 
//     printf("\nSorted array is \n");
//     printArray(arr, arr_size);
//     return 0;
// }