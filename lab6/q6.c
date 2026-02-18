#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

bool isPalindrome(char* str) {
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        push(tolower(str[i]));
    }

    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != pop()) {
            return false;
        }
    }

    return true;
}

int main() {
    char word[] = "RADAR";
    
    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}
