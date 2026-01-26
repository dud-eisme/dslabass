#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	swap(&a, &b);
	printf("A: %d\nB: %d\n", a, b);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
