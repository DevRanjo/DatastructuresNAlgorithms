#include <stdio.h>
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

int main(void) {
    start_timer();
    printf("Creating a long list...\n");

    List *longlist = create_list();
    for (int i = 0; i < 100000; ++i)
        prepend_to_list(longlist, i);
    printf("Done!\n");
    printf("The long list is %d elements long.\n", list_length(longlist));
    printf("Copying the long list...\n");
    List *listcopy = copy_list(longlist);
    printf("Done!\n");
    printf("The copy is %d elements long.\n", list_length(listcopy));
    destroy_list(longlist);
    destroy_list(listcopy);

    stop_and_show_timer();
}
