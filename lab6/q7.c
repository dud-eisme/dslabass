#include <stdio.h>
#include "stackops.h"
#define MAX 100

int main() {
  struct Stack s;
  init(&s);

  while (true) {
    printf("\n\n");
    printf("--- Operations in Stack ---\n");
    printf("1.\tPush Element\n2.\tPop Element\n3.\tPeek Element\n4.\tCheck if Stack is Empty\n5.\tCheck if Stack is Full\n6.\tExit\nChoose an option: ");
    int opt;
    scanf("%d", &opt);

    if (opt == 1) {
      printf("\n\n\n");
      printf("Enter Element you want to push: ");
      int inp;
      scanf("%d", &inp);
      push(&s, inp);
    }

    else if (opt == 2) {
      int popped = pop(&s);
      printf("Popped: %d\n", popped);
    }

    else if (opt == 3) {
      int peeked = peek(&s);
      printf("Top Element: %d\n", peeked);
    }

    else if (opt == 4) {
      if (isEmpty(&s))
        printf("Stack is Empty.\n");
      else
        printf("Stack is Not Empty.\n");
    }

    else if (opt == 5) {
      if (isFull(&s))
        printf("Stack is Full.\n");
      else 
        printf("Stack is Not Full.\n");
    }

    else if (opt == 6) {
      printf("Exiting Menu...\n");
      return 0;
    }

    else 
      printf("Invalid Operation.\n");
  }
}
