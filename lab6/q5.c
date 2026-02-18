#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int bit) {
    if (top < MAX - 1) {
        stack[++top] = bit;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int temp = n;
    while (temp > 0) {
        push(temp % 2);
        temp = temp / 2;
    }

    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int num;
    scanf("%d", &num);
    printf("Decimal: %d\n", num);
    printf("Binary: ");
    decimalToBinary(num);
    return 0;
}
