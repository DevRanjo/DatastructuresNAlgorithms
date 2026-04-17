//Quick sort Time Complexity O(n log n)
//Best case 
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    //choose pivot
}