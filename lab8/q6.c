#include "stackops.h"
#include <ctype.h>
#include <string.h>

void PostToPre(char* postfix, char* prefix) {
    char stack[MAX][MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            char temp[2] = {postfix[i], '\0'};
            strcpy(stack[++top], temp);
        } 
        else {
            char op2[MAX], op1[MAX], res[MAX];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(res, "%c%s%s", postfix[i], op1, op2);
            strcpy(stack[++top], res);
        }
    }
    strcpy(prefix, stack[top]);
}

int main() {
  char inp[MAX];
  printf("Enter Postfix expression: ");
  fgets(inp, MAX, stdin);
  inp[strcspn(inp, "\n")] = 0;

  char out[MAX];
  PostToPre(inp, out);
  printf("Infix expression: %s\n", out);

  return 0;
}
