#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

int check(char str[])
{

    top = -1;
    int i = 0;

    while (str[i] == 'a')
    {
        push('a');
        i++;
    }

    while (str[i] == 'b')
    {

        if (top == -1)
            return 0;

        pop();
        i++;
    }

    if (str[i] == '\0' && top == -1)
        return 1;

    return 0;
}

int main()
{

    char str[MAX];

    printf("Enter the string: ");
    scanf("%s", str);

    if (check(str))
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}
