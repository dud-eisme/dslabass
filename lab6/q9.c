#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void deleteMiddle(int currentIdx, int midIdx) {
    if (currentIdx == midIdx) {
        pop();
        return;
    }

    int temp = pop();
    deleteMiddle(currentIdx + 1, midIdx);
    push(temp);
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    int mid = top / 2;
    deleteMiddle(0, mid);

    printStack();

    return 0;
}
