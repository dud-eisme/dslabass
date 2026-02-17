#include <stdio.h>
#include <stdlib.h>

struct STACK {
    int size;
    int top;   
    int *ptr;
};

void push(struct STACK *s, int value) {
    if (s->top == s->size - 1) {
        printf("Overflow\n");
    } else {
        s->top++;
        s->ptr[s->top] = value;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int k, struct STACK *s) {
    if (k > s->top + 1) k = s->top + 1; 
    for (int i = 0; i < k / 2; i++) {
        swap(&s->ptr[i], &s->ptr[k - 1 - i]);
    }
}

int main() {
    int k, element;
    struct STACK *s = (struct STACK*)malloc(sizeof(struct STACK));
    s->size = 5;
    s->top = -1;
    s->ptr = (int*)malloc(s->size * sizeof(int));

    printf("PUSH THE ELEMENTS ONE BY ONE:\n");
    for (int i = 0; i < s->size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        push(s, element); 
    }

    printf("GIVE VALUE OF K: ");
    scanf("%d", &k);
    
    reverse(k, s);

    printf("Stack elements after reverse: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->ptr[i]);
    }

    return 0;
}