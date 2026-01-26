#include <stdio.h>

int main()
{
	int a = 5, b = 6;
	int *p1, *p2;
	p1 = &a;
	p2 = &b;

	printf("Sum of %d and %d is: %d\n", a, b, *p1 + *p2);
}
