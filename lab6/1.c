#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    if (top >= 0)
        return stack[top--];

    return '\0';
}

int check(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);

        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (top == -1)
                return 0;

            char popped = pop();

            if (ch == ')' && popped != '(' ||
                ch == '}' && popped != '{' ||
                ch == ']' && popped != '[')
            {
                return 0;
            }
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{

    char str[MAX];
    printf("Enter the Expression :");
    scanf("%s", str);

    if (check(str))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}