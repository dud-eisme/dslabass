#include <stdio.h>

int main()
{
	int a = 5, b = 100;
	int *p1, *p2;
	p1 = &a;
	p2 = &b;

	if(*p1 >= *p2)
		printf("%d\n", *p1);
	else if(*p1 < *p2)
		printf("%d\n", *p2);
}
