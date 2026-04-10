#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

typedef struct stackArray{
    int stack[SIZE];
    int top;
}Stack;

Stack* createStack(){
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

bool isEmpty(Stack* s){
    if(s->top==-1){ return true;} 
    else{ return false;}
}

void push(Stack* s){
    if(s->top == (SIZE-1)){ //check if stack has reached max SIZE
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = data;
}

int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;}
    s->top--;
    return s->stack[s->top+1]; //return the last value that was removed from stack
}

