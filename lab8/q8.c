#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }

int pop() { return stack[top--]; }

int main() {
  char exp[200];
  char *token;

  printf("Enter Postfix Expression: ");
  fgets(exp, sizeof(exp), stdin);

  token = strtok(exp, " ");

  while (token != NULL) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      push(atoi(token));
    } else {
      int b = pop();
      int a = pop();
      int result;

      switch (token[0]) {
      case '+':
        result = a + b;
        break;
      case '-':
        result = a - b;
        break;
      case '*':
        result = a * b;
        break;
      case '/':
        if (b != 0)
          result = a / b;
        else
          result = 1;
        break;
      }
      push(result);
    }
    token = strtok(NULL, " ");
  }

  printf("Result = %d\n", pop());

  return 0;
}
