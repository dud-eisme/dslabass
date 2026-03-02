#include "stackops.h"
#include <string.h>
#include <ctype.h>

bool checkValid(char arr[]) {
  int count = 0;
  for (int i = 0; i < strlen(arr); i++) {
    if (isspace(arr[i])) continue;
    if (isalnum(arr[i])) count++;
    else count--;
  }
  if (count == 1) return true;
  return false;
}

int main() {
  char inp[MAX];
  printf("Enter Infix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;

  if (checkValid(inp)) printf("Valid expression.\n");
  else printf("Invalid expression.\n");

  return 0;
}
