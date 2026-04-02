Q1:

What “list type” means

When they say “list type”, they mean your implementation of the List data structure—basically everything defined in your:

list.h → the interface (the type and function declarations)
list.c → the implementation (how it actually works)

So “list type” = your custom linked list abstraction, including:

The List struct
The Node struct
All functions like:
create_list
append_to_list
prepend_to_list
find_position_in_list
copy_list
destroy_list
etc.

Important nuance
_____________________________________________________________________________________________
It does NOT guarantee:

Your code is perfect
No memory leaks (unless explicitly checked)
No inefficiencies

It only means:
“Your implementation passed all the expected behavior tests.”
_____________________________________________________________________________________________

In exercise 2:
Compiled by:
    gcc ex2.c list.c -o program 
Run by:
    ./program

Q6:
    Successor wont be found in list L2 since the node input already include the biggest value, 
    therefore, printing a null -> keyvalue will crash the program