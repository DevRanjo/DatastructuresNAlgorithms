CC = gcc
# CFLAGS += -Wall -Wextra -std=c11 -O3
CFLAGS += -Wall -Wextra -std=c11 -g
CXXFLAGS += -Wall -Wextra -std=c++17 -g

all: test_list test_alternative copy_test alternative_copy_test

test_list: test_list.o list.o
	$(CC) -g test_list.o list.o -o test_list

test_alternative: test_list.o alternative_list.o
	$(CC) -g test_list.o alternative_list.o -o test_alternative

copy_test: copy_test.o list.o
	$(CC) -g copy_test.o list.o -o copy_test

alternative_copy_test: copy_test.o alternative_list.o
	$(CC) -g copy_test.o alternative_list.o -o alternative_copy_test

clean:
	$(RM) test_list test_list.o list.o test_alternative alternative_list.o copy_test copy_test.o alternative_copy_test

test: test_list copy_test test_alternative alternative_copy_test
	./test_list
	./copy_test
	./test_alternative
	./alternative_copy_test

zip: clean
	$(RM) *~
	$(RM) ../intro-list-exercise.zip
	cd .. ; zip -r intro-list-exercise.zip intro-list-exercise
