#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./load_file/load_file.h"
#include "sorting_algorithms.h"

int main(){

    const char* filename = "./sorting_problems/test-10-1-problem";
    int* array = load_file(filename);
    if(array == NULL){
        printf("error loading sorting problem array\n");
        return -1;
    }
    const char* filename2 = "./sorting_problems/test-10-1-solution"; //already sorted solution
    int* solution = load_file(filename2);
    if(solution == NULL){
        printf("error loading sorting problem solution array\n");
        return -1;
    }

    int n = array[0];
    int n2 = solution[0];

    //first element specified the array size
    printf("Array before quick sorting: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quicksort(&array[1], 0, n-1);   //int arr[] = int* arr, and arr + 1 -> move to next element
                                    //and arr[i] is equivalent to *(arr+i)
    /*Basically the input "array" gives the pointer to first element, therefore we put the pointer to point at the next element in the array*/
    printf("Array after quick sorting: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Compare with the solution array: ");
    for (int i= 1; i <= n; i++){
        printf("%d ", solution[i]);
        assert(solution[i] == array[i]);
    }
    printf("\n");

    free(array);
    free(solution);
    return 0;
}



