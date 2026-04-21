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