#include <stdio.h>

int add(int, int);
void printAns(int (*operation)(int, int), int, int);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printAns(add, a, b);
}

int add(int a, int b)
{
	return a + b;
}

void printAns(int (*operation)(int, int), int a, int b)
{
	printf("Addition: %d\n", operation(a, b));
}
