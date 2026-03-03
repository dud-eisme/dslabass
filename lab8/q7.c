#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    int n = strlen(infix);
    reverse(infix);

    for (int i = 0; i < n; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char stack[MAX];
    int top = -1;
    int j = 0;

    for (int i = 0; i < n; i++) {
        
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = '(';
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[j++] = stack[top--];
            top--;
        } else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) prefix[j++] = stack[top--];
    prefix[j] = '\0';

    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter Infix: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    return 0;
}
