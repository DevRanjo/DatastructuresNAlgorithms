MAKEFILE

check if have:
    make --version
    mingw32-make --version

Compiling with mingw32 -> mingw32-make   

Gave: 
    gcc -Wall -Wextra -std=c11 -O3   -c -o test_load_file.o test_load_file.c
    gcc -Wall -Wextra -std=c11 -O3   -c -o load_file.o load_file.c
    gcc  test_load_file.o load_file.o -o test_load_file

Usage:
    ./test_load_file ../sorting_problems/[name of specific file]
    ex: 
    ./test_load_file ../sorting_problems/test-10-1-problem

Note:
    In exercise 5:
        The array indexes are 1..n from the load file.
        array[0] will contain the number "n" of elements in the array.
        The physical length of the array is therefore n+1.

Compile:
    In Ex5:
       gcc Ex5.c sorting_algorithms/quicksort.c sorting_algorithms/selectionssort.c load_file/load_file.c -o program
Run:
    In Ex5:
        ./program