//Selection sort time complexity (On^2)
#include <stdio.h>

void SelectionSort(int arr[], int size){
    for(int i=0; i<size; i++){
        int min_indx = i;       //current element

        for(int j=i+1; j<size; j++){        //search through unsorted
            if(arr[j]<arr[min_indx]){       //if find smaller save indx
                min_indx = j; 
            }
        }
        int temp = arr[i];                  //Switch
        arr[i] = arr[min_indx];
        arr[min_indx] = temp; 

    }
}

void print_arr(int arr[], int size){
    for(int i=1; i<size; i++){
        printf("%d ", arr[i]);
    }
}

