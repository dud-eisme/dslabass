#include "stackops.h"
#include <string.h>
#include <ctype.h>

char* PosttoIn(char arr[]) {
  struct Stack s;
  int j = 0;
  static char newarr[MAX];

  int count = 0;

  for (int i = 0; i < strlen(arr); i++)
    if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') newarr[j++] = '(';

  for (int i = strlen(arr) - 1; i >= 0; i--) {
    if (isspace(arr[i])) continue;
    if (isalnum(arr[i])) push(&s, arr[i]);
    else {
      int op2 = pop(&s);
      if (!count) {
        int op1 = pop(&s);
        newarr[j++] = op1;
        count++;
      }
      newarr[j++] = arr[i];
      newarr[j++] = op2;
      newarr[j++] = ')';
    }
  }
  return newarr;
}

int main() {
  char inp[MAX];
  printf("Enter Postfix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;

  char out[MAX];
  strcpy(out, PosttoIn(inp));
  printf("Infix expression: %s\n", out);

  return 0;
}
