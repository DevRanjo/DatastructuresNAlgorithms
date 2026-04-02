#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "list.h"

static clock_t before;
static clock_t after;

static void start_timer(void) {
    before = clock();
}

static void stop_and_show_timer(void) {
    after = clock();

    double elapsed_ticks = after - before;
    double seconds = elapsed_ticks / CLOCKS_PER_SEC;
    printf("Elapsed time: %.2f s\n", seconds);
}

// For testing: Sorts the array "a" of length "length" in random order
static void shuffle_array(int a[], int length) {
    for (int randomized = 0; randomized < length; ++randomized) {
        // Select a random position in the rest of the array
        int selected = randomized + rand() % (length - randomized);
        // Swap the current position with the random position
        int oldvalue = a[randomized];
        a[randomized] = a[selected];
        a[selected] = oldvalue;
    }
}

#define NR_STRESS_TESTS_TO_RUN 10
#define NR_NUMBERS_TO_TEST 1000
// Large data, such as this array, might not fit in a local variable
int numbers[NR_NUMBERS_TO_TEST];

void stress_test(void) {
    printf("Stress test. This could take a while...\n");
    for (int i = 0; i < NR_NUMBERS_TO_TEST; ++i) {
        numbers[i] = i - NR_NUMBERS_TO_TEST / 2;
    }
    shuffle_array(numbers, NR_NUMBERS_TO_TEST);
    for (int testnumber = 0; testnumber < NR_STRESS_TESTS_TO_RUN; ++testnumber) {//10 ggr skapar listor
        List *list = create_list();
        int nr_numbers_this_time = rand() % NR_NUMBERS_TO_TEST; //random number amount of elements to test

        for (int i = 0; i < nr_numbers_this_time; ++i) {
            if (rand() % 2 == 0)                        //random med jämn/ojämn rest
                prepend_to_list(list, numbers[i]);      //lägg till i början
            else
                append_to_list(list, numbers[i]);       //lägg till i slutet

            assert(list_length(list) == i + 1);         //kollar list storlek

            for (int j = 0; j < NR_NUMBERS_TO_TEST; ++j) {
                if (j <= i)
                    assert(find_position_in_list(list, numbers[j]) != -1);
                else
                    assert(find_position_in_list(list, numbers[j]) == -1);
            }
        }
        destroy_list(list);
    }
    printf("Stress test done.\n");
}

int main(void) {
    start_timer();
    printf("Testing List...\n");

    // The simplest tests, with a single empty list and a copy of it
    List *list1 = create_list();
    assert(list_length(list1) == 0);
    assert(find_position_in_list(list1, -1) == -1);
    assert(find_position_in_list(list1, 0) == -1);
    assert(find_position_in_list(list1, 17) == -1);
    List *list1copy = copy_list(list1);
    assert(list_length(list1copy) == 0);
    assert(find_position_in_list(list1copy, -1) == -1);
    assert(find_position_in_list(list1copy, 0) == -1);
    assert(find_position_in_list(list1copy, 17) == -1);
    destroy_list(list1);
    destroy_list(list1copy);

    // Testing appending and prepending
    List *list2 = create_list();
    assert(list_length(list2) == 0);
    prepend_to_list(list2, 17);
    assert(list_length(list2) == 1);
    assert(find_position_in_list(list2, 17) == 0);
    assert(find_position_in_list(list2, 4711) == -1);
    append_to_list(list2, 4711);
    assert(list_length(list2) == 2);
    assert(find_position_in_list(list2, 17) == 0);
    assert(find_position_in_list(list2, 4711) == 1);
    append_to_list(list2, -1);
    assert(list_length(list2) == 3);
    assert(find_position_in_list(list2, 17) == 0);
    assert(find_position_in_list(list2, 4711) == 1);
    assert(find_position_in_list(list2, -1) == 2);
    destroy_list(list2);

    // Testing if there really are separate List objects
    List *list3 = create_list();
    List *list4 = create_list();
    append_to_list(list3, 1);
    append_to_list(list3, 2);
    append_to_list(list3, 3);
    prepend_to_list(list4, 5);
    prepend_to_list(list4, 4);
    List *list3copy = copy_list(list3);
    assert(list_length(list3) == 3);
    assert(list_length(list3copy) == 3);
    assert(list_length(list4) == 2);
    destroy_list(list3);
    destroy_list(list3copy);
    destroy_list(list4);

    stress_test();

    printf("Testing List done. No errors found.\n");

    printf("And finally, check that print_list works.\n");
    printf("This should be the list [ 13 13 -27 13 0 26 ]:\n");
    List *list5 = create_list();
    append_to_list(list5, 13);
    append_to_list(list5, 13);
    append_to_list(list5, -27);
    append_to_list(list5, 13);
    append_to_list(list5, 0);
    append_to_list(list5, 26);
    print_list(list5);
    destroy_list(list5);

    stop_and_show_timer();
}
