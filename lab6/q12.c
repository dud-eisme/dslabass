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
        printf("Overflow\n");
    } else {
        s->top++;
        s->ptr[s->top] = ch;
    }
}

char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    } else {
        char ch = s->ptr[s->top];
        s->top--;
        return ch;
    }
}

void main() {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->ptr = (char*)malloc(s->size * sizeof(char));

    char input[100];
    printf("PUSH STRING:\n");
    fgets(input, 100, stdin);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '\n' && input[i] != '\0') {
            push(s, input[i]);
        }
    }

    

    printf("REVERSED STRING USING STACK:\n");
    while (s->top != -1) {
        printf("%c", pop(s));
    }
    printf("\n");
}