#include <stdio.h>

void f1()
{
	printf("In function f1\n");
}

void f2(void (*ptr)())
{
	printf("In function f2\n");
	(*ptr)();
}

int main()
{
	void (*ptr)() = &f1;

	printf("Calling function f2\n");
	f2(ptr);

	return 0;
}
