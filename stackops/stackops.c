#include "stackops.h"


struct Stack {
  int arr[MAX];
  int top;
};

void init(struct Stack *s) { s->top = -1; }

void push(struct Stack *s, int val) {
  if (s->top < MAX - 1) {
    s->arr[++(s->top)] = val;
    return;
  }
  printf("Stack Overflow: No more elements can be pushed.\n");
}

int pop(struct Stack *s) {
  if (s->top > -1)
    return s->arr[(s->top)--];
  printf("Stack Empty.\n");
  return -1;
}

int peek(struct Stack *s) {
  if (s->top > -1)
    return s->arr[(s->top)];
  printf("Stack Empty.\n");
  return -1;
}

bool isEmpty(struct Stack *s) {
  if (s->top == -1)
    return 1;
  return 0;
}

bool isFull(struct Stack *s) {
  if (s->top == MAX - 1)
    return 1;
  return 0;
}
