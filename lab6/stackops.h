#include <stdio.h>

#ifndef StackOps
#define StackOps
#define MAX 100
struct Stack {
  int arr[MAX];
  int top;
};

void init(struct Stack *s);
void push(struct Stack *s, int val);
int pop(struct Stack *s);
int peek(struct Stack *s);
bool isEmpty(struct Stack *s);
bool isFull(struct Stack *s);
#endif
