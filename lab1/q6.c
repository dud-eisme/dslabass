#include <stdio.h>

int main()
{
	int a = 7;
	int *ptr;
	ptr = &a;
	int **ptrptr;
	ptrptr = &ptr;

	printf("Value of Integer: %d\nAddress of Integer: %d\nAddress of Pointer: %d\n", a, ptr, ptrptr);
}
