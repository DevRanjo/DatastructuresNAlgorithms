CC = gcc
CFLAGS += -Wall -Wextra -std=c11 -O3

OBJECTS = test_load_file.o load_file.o

test_load_file: $(OBJECTS)
	$(CC) $(CLAGS) $(OBJECTS) -o test_load_file

clean:
	$(RM) $(OBJECTS) test_load_file
