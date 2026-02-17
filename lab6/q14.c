#include <stdio.h>
#include <stdlib.h>

struct STACK {
    int size;
    int top;
    int *ptr;
};

void push(struct STACK *s, int data) {
    if (s->top == s->size - 1) {
        printf("Overflow\n");
    } else {
        s->top++;
        s->ptr[s->top] = data;
    }
}

int sum(struct STACK *s) {
    int total = 0;
    for (int i = 0; i <= s->top; i++) {
        total = total + s->ptr[i];
    }
    return total;
}

void main() {
    struct STACK *s = (struct STACK*)malloc(sizeof(struct STACK));
    s->size = 5;
    s->top = -1;
    s->ptr = (int*)malloc(s->size * sizeof(int));

    printf("PUSH THE ELEMENTS ONE BY ONE INTO THE STACK:\n");
    for (int i = 0; i < s->size; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        push(s, element);
    }

    printf("THE SUM OF ALL ELEMENTS OF THE STACK: %d\n", sum(s));
}