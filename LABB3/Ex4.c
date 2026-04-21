#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//SELECTION SORT ALGORITM WITH O(n^2) COMPLEXITY
bool selection_sort(int array[], int n){
    for(int i=0; i<n-1; i++){ 
        int min_value_at = i;                   //move to the current index 

        for(int j=i+1; j<n; j++){                         //look through the unsorted elements
            if(array[j] < array[min_value_at]){
                min_value_at = j;                       //update if smaller element was found
            }
        }
            
        //swap elements to right place
        int previous = array[i];
        array[i] = array[min_value_at];
        array[min_value_at] = previous;
        
    }
    return true;
}

//QUICK SORT 

int part(int array[], int low, int high){
    
    //choose pivot: here we take random element
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = array[pivot_index];

    // Swap pivot to the end
    int tmp = array[pivot_index];
    array[pivot_index] = array[high];
    array[high] = tmp;

    int i = low - 1;        //before first element index

    for(int j = low; j<= high-1; j++){
        if(array[j] < pivot){
            i++;            //move to next index
            
            //swap elements
            int temp = array[i];
            array[i]= array[j];
            array[j] = temp;
        }
    }
     //swap elements
     int temp = array[i+1];
     array[i+1]= array[high];
     array[high] = temp;
     return i+1;
}

bool quick_sort(int array[], int low, int high){
    if (low < high){
        int pivot_place = part(array, low, high);   //returns the index of pivot

        quick_sort(array, low, pivot_place-1);      //sort elements before pivot
        quick_sort(array, pivot_place+1, high);     //sort elemenst after pivot

    }
    return true;
}

void display_array(int array[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

float clock_time_end(clock_t start){
    clock_t end = clock();
    float seconds = (float)(end-start)/CLOCKS_PER_SEC;
    return seconds;
}

void Testing(){
    
    int arr[] = {1};
    //Testing array with only one element
    assert(selection_sort(arr, 1) == true);
    assert(quick_sort(arr,0, 0) == 1);
    
    //Testing large arrays
    int ARRAY_SIZE = 100000;
    int* largeArray = malloc(ARRAY_SIZE * sizeof(int));
    assert(largeArray != NULL);

    // Initialize the array with some values, decending/falling order
    for (int i = 0; i < ARRAY_SIZE; i++) {
        largeArray[i] = ARRAY_SIZE - i - 1;
    }
    //Test time with sorting selection sort and quick sort
    clock_t start1 = clock();
    assert(selection_sort(largeArray, ARRAY_SIZE)==true);
    printf("Time for large array selection sort, decending order: %f\n", clock_time_end(start1));
    clock_t start11 = clock();
    assert(quick_sort(largeArray, 0, ARRAY_SIZE-1)==true);
    printf("Time for large array quick sort, decending order: %f\n\n", clock_time_end(start11));


    //increasing order
    for (int i = 0; i < ARRAY_SIZE; i++) {
        largeArray[i] = i;
    }

    clock_t start2 = clock();
    assert(selection_sort(largeArray, ARRAY_SIZE)==true);
    printf("Time for large array selection sort, increasing order: %f\n", clock_time_end(start2));
    clock_t start22 = clock();
    assert(quick_sort(largeArray,0, ARRAY_SIZE-1)==true);
    printf("Time for large array quick sort, increasing order: %f\n\n", clock_time_end(start22));



    //for random order
    for (int i = 0; i < ARRAY_SIZE; i++) {
        largeArray[i] = rand();
    }
    clock_t start3 = clock();
    assert(selection_sort(largeArray, ARRAY_SIZE)==true);
    printf("Time for large array selection sort, random order: %f\n", clock_time_end(start3));
    clock_t start33 = clock();
    assert(quick_sort(largeArray,0, ARRAY_SIZE-1)==true);
    printf("Time for large array quick sort, random order: %f\n\n", clock_time_end(start33));


    //for same value in whole array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        largeArray[i] = 1;
    }
    clock_t start4 = clock();
    assert(selection_sort(largeArray, ARRAY_SIZE)==true);
    printf("Time for large array selection sort, same value: %f\n", clock_time_end);
    assert(quick_sort(largeArray,0, ARRAY_SIZE-1));   
    clock_t start44 = clock();      //so it won't partition to subarrays which leads to infinite recursion
    printf("Time for large array quick sort, same value: %f\n", clock_time_end(start44));



    free(largeArray);
}

int main(){

    int b[]={1,9,6,3,1,2,1,1,1,6,5,8};
    int m = sizeof(b)/sizeof(b[0]);
    printf("Personal number before sorting: ");
    display_array(b, m);
    selection_sort(b, m);

    printf("Personal number after sorting: ");
    display_array(b, m);

    printf("Please wait for result for testing...\n");
    Testing();
    printf("End of main\n");
    return 1;
}