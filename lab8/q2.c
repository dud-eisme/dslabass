#include "stackops.h"
#include <string.h>
#include <ctype.h>

void IntoPost(char arr[]) {
  struct Stack fix;
  int j = 0;
  for (int i = 0; i < strlen(arr); i++) {
    if (isspace(arr[i])) continue;
    if (isalnum(arr[i])) arr[j++] = arr[i];
    else if (arr[i] == '(' || arr[i] == ')' || arr[i] == '[' || arr[i] == ']' || arr[i] == '{' || arr[i] == '}') continue;
    else push(&fix, arr[i]);
  }
  while (fix.top != -1)
    arr[j++] = pop(&fix);

}

int main() {
  char inp[MAX];
  printf("Enter Infix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;
  IntoPost(inp);

  printf("Postfix expression: %s \n", inp);
  return 0;
}
