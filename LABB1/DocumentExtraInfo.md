
MAKEFILE
The file Makefile, which contains rules for the program make to build the 
programs test_list and copy_test. 

Check if have:
    make --version
    mingw32-make --version

Compiling with mingw32 -> mingw32-make   
Gave:        
    gcc -Wall -Wextra -std=c11 -g   -c -o test_list.o test_list.c
    gcc -Wall -Wextra -std=c11 -g   -c -o list.o list.c
    gcc -g test_list.o list.o -o test_list
    gcc -Wall -Wextra -std=c11 -g   -c -o alternative_list.o alternative_list.c
    gcc -g test_list.o alternative_list.o -o test_alternative
    gcc -Wall -Wextra -std=c11 -g   -c -o copy_test.o copy_test.c
    gcc -g copy_test.o list.o -o copy_test
    gcc -g copy_test.o alternative_list.o -o alternative_copy_test

Now can use the commands in the commad window:
    ./test_list
	./copy_test
	./test_alternative
	./alternative_copy_test

GIT: Files saved with LF endings (commonly in Linux) converting to CRLF (Windows)
Command to ignore:
    git config --global core.autocrlf true
