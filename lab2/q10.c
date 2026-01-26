#include <stdio.h>
#include <stdlib.h>

void ptrchange(int **ptr);

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int a = 5;
	int *ptr = &a;
	printf("Before:\n%d %d\n", *ptr, ptr);
	ptrchange(&ptr);
	printf("After:\n%d %d\n", *ptr, ptr);
}

void ptrchange(int **ptr)
{
	*ptr = (int*)malloc(sizeof(int));
	**ptr = 100;
}
