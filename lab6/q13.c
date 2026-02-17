#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int top;
    int size;
    char *ptr;
};

void push(struct stack *s, char ch) {
    if (s->top == s->size - 1) {
        return;
    }
    s->top++;
    s->ptr[s->top] = ch;
}

char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    char ch = s->ptr[s->top];
    s->top--;
    return ch;
}

void main() {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->ptr = (char*)malloc(s->size * sizeof(char));

    char input[100];
    printf("ENTER STRING (format: abc$abc):\n");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '$' && input[i] != '\0') {
        push(s, input[i]);
        i++;
    }

    

    if (input[i] == '\0') {
        printf("INVALID INPUT: MISSING $\n");
        return;
    }

    i++; 
    int valid = 1;
    while (input[i] != '\0') {
        if (s->top == -1 || input[i] != pop(s)) {
            valid = 0;
            break;
        }
        i++;
    }

    if (valid && s->top == -1) {
        printf("VALID STRING\n");
    } else {
        printf("INVALID STRING\n");
    }
}