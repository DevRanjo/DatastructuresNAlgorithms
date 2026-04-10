#include <stdlib.h>
#include <stdio.h>
#include "load_file.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: test_load_file FILE_NAME\n");
        exit(EXIT_FAILURE);
    }

    const char* file_name = argv[1];
    int *a = load_file(file_name);
    int size = a[0];

    printf("%d element(s):\n", size);
    // This loops from 1 <= i <= size!
    printf("[");
    for (int i = 1; i <= size; i++) {
        printf(" %d", a[i]);
        if (i % 10 == 0 && i != size)
            printf("\n");
    }
    printf(" ]\n");

    free(a); // Not really needed, since the program terminates
}
