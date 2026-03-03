#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) { strcpy(stack[++top], str); }

void pop(char *dest) { strcpy(dest, stack[top--]); }

int main() {
  char inp[MAX];
  printf("Enter Postfix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;

  for (int i = 0; inp[i] != '\0'; i++) {
    if (isalnum(inp[i])) {
      char operand[2] = {inp[i], '\0'};
      push(operand);
    } else {
      char op1[MAX], op2[MAX];
      pop(op2);
      pop(op1);

      char temp[MAX];
      snprintf(temp, MAX, "(%s%c%s)", op1, inp[i], op2);
      push(temp);
    }
  }

  return 0;
}
