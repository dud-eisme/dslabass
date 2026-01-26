#include <stdio.h>

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int *ptr = &arr[0];

	for (int i = 0; i < 5; i++, ptr++)
		printf("Address of element %d: %d\n", i, ptr);
}
