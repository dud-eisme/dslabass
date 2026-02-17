#include <stdio.h>

#ifndef Stack
#define MAX 100

typedef struct Stack{
  int arr[MAX];
  int top;
}Stack;


void push(struct Stack* s, int n) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = n;
    }
}

int pop(struct Stack* s) {
    if (s->top == -1) 
      return '\0';
    return s->arr[(s->top)--];
}
#endif
