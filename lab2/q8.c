#include <stdio.h>

void apply(int*, int (*ptr)(int), int);
int fun(int);

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;
	apply(arr, fun, n);

	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void apply(int arr[], int (*fptr)(int), int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = fptr(arr[i]);
}

int fun(int x)
{
	return x * x;
}
