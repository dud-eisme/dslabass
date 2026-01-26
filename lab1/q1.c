#include <stdio.h>

int main()
{
	int *ptr;
	int val = 10;
	ptr = &val;

	printf("Value of the integer: %d\n", *ptr);
	printf("Address of the variable: %d\n", ptr);
}
