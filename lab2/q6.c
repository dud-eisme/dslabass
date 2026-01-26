#include <stdio.h>

void genswap(char*, char*);

int main()
{
	char a, b;
	scanf("%c %c", &a, &b);
	printf("Before:\n%c %c\n", a, b);
	genswap(&a, &b);
	printf("After:\n%c %c\n", a, b);
}

void genswap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
