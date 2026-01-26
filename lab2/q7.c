#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 5, b = 6;
	int (*fptr)(int, int);

	fptr = &add;

	printf("Sum of a & b is: %d\n", fptr(a, b));
}
