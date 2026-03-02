#include "stackops.h"
#include <string.h>
#include <ctype.h>
//max elemens -> 100

int evalPrefix(char arr[]) {
  int n = strlen(arr);
  struct Stack ops;
  for (int i = n - 1; i >= 0; i--) {
    if (isspace(arr[i])) continue;
    if (isdigit(arr[i])) push(&ops, arr[i] - '0');
    else {
      int op1 = pop(&ops);
      int op2 = pop(&ops);
      push (&ops, op(op1, op2, arr[i]));
    }
  }
  return pop(&ops);
}

int main() {
  char inp[MAX];
  printf("Enter prefix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;
  int ans = evalPrefix(inp);

  printf("Answer: %d\n", ans);

  return 0;
}
