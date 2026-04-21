#include <stdio.h>
#include <stdlib.h>
#include "./load_file/load_file.h"
#include "sorting_algorithms.h"

int main(){


    const char* filename = "./sorting_problems/test-10-1-problem";
    int* array = load_file(filename);
    if(array == NULL){
        printf("error loading array\n");
        return 0;
    }
    int n = array[0];

    //first element specified the array size
    printf("Array before quick sorting: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quicksort(&array[1], 0, n-1);
    printf("Array after quick sorting: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;
}



