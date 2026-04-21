//Quick sort Time Complexity O(n log n)
//Best case 
#include <stdio.h>
#include <stdlib.h>
#include "../sorting_algorithms.h"

void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    //choose pivot
    int pivot = arr[high];

    //Index of smaller element and indicates 
    //the right position 
    //of pivot found so far
    int i = low - 1; 

    //Traverse arr[low to high] and move all smaller
    //elements to the left side
    for(int j=low; j<= high -1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    //move pivot after smaller elements and return its position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

//the quick sort implementation
void quicksort(int arr[], int low, int high){
    if(low < high){
        //pi is the partiiton return index of pivot
        int pi = partition(arr, low, high);

        //recursion calls for smaller elements and 
        //greater or equals elements
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);

    }
}

/*int main(){
    int arr[] = {3, 8, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}*/
