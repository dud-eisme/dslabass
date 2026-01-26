#include <stdio.h>


int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int *p1, *p2;
	p1 = &arr[4];
	p2 = &arr[1];

	printf("p1 element: %d\n", *p1);
	printf("p2 element: %d\n", *p2);
	
	printf("p1-- element: %d\n", *(--p1));
	printf("p2++ element: %d\n", *(++p2));

	printf("p2 - 2 element: %d\n", *(p2 - 2));

	printf("Distance b/w p1 & p2: %d\n", p1 - p2);
}
