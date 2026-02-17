#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int size;
    int *ptr;
};

void push(struct stack *s, int value) {
    if (s->top == s->size - 1) {
        printf("Overflow\n");
    } else {
        s->top++;
        s->ptr[s->top] = value;
    }
}

int pop(struct stack *s, int *store) {
    if (s->top == -1) {
        return 0; 
    } else {
        *store = s->ptr[s->top];
        s->top--;
        return 1; 
    }
}

void main() {
    int n, element, val1, val2, current;
    int max, smax;

    printf("ENTER HOW MANY ELEMENTS YOU WANT: ");
    scanf("%d", &n);
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = n;
    s->ptr = (int*)malloc(s->size * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("[%d]->", i + 1);
        scanf("%d", &element);
        push(s, element);
    }
//to store peek element at the address of val1 snd val 2.
    pop(s, &val1);
    pop(s, &val2);

    if (val1 > val2) {
        max = val1;
        smax = val2;
    } else {
        max = val2;
        smax = val1;
    }
    while (pop(s, &current) != 0) { 
        if (current > max) {
            smax = max;
            max = current;
        } else if (current > smax && current < max) {
            smax = current;
        }
    }

    printf("THE SECOND LARGEST ELEMENT IS %d\n", smax);
}