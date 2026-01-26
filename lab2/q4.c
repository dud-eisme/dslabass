#include <stdio.h>

int sqocu(int, int);

int main()
{
	int (*fptr)(int, int);

	fptr = &sqocu;

	int a, b;
	scanf("%d", &a);
	printf("Choose an option:\n1.Square\n2.Cube\n");
	scanf("%d", &b);

	printf("Answer: %d\n", fptr(a, b - 1));
}

int sqocu(int a, int b)
{
	if(!b)
		return a * a;
	else if(b)
		return a * a * a;
	return 0;
}
