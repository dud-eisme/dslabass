#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

bool checkRedundancy(char* str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == ')') {
            char topChar = pop();
            bool hasOperator = false;

            while (topChar != '(') {
                if (topChar == '+' || topChar == '-' || 
                    topChar == '*' || topChar == '/') {
                    hasOperator = true;
                }
                topChar = pop();
            }

            if (!hasOperator) {
                return true;
            }
        } else {
            push(str[i]);
        }
    }
    return false;
}

int main() {
    char expr1[] = "((a+b))";
    char expr2[] = "(a+(b*c))";

    if (checkRedundancy(expr1)) {
        printf("Expression 1 has redundant brackets\n");
    } else {
        printf("Expression 1 has no redundant brackets\n");
    }

    top = -1; 

    if (checkRedundancy(expr2)) {
        printf("Expression 2 has redundant brackets\n");
    } else {
        printf("Expression 2 has no redundant brackets\n");
    }

    return 0;
}
