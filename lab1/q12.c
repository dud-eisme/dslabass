#include <stdio.h>
#include <stdlib.h>

int main()
{
	//malloc does not assign values to the initialised array
	int *ptrm = (int *)malloc(sizeof(int) * 4);
	for(int i = 0; i < 5; i++)
		ptrm[i] = i + 1;

	for(int i = 0; i < 5; i++)
		printf("%d ", ptrm[i]);
	printf("\n");

	//calloc assigns default value 0 to the initialised array
	int *ptrc = (int *)calloc(5, sizeof(int));

	if(ptrc == NULL)
	{
		printf("allocation failed\n");
		return 1;
	}

	for(int i = 0; i < 5; i++)
		printf("%d ", ptrc[i]);
	printf("\n");

	//realloc for changing/reassigning the size of memory block of an array
	int *ptrr = (int *)calloc(5, sizeof(int));
	ptrr = (int *)realloc(ptrr, 10 * sizeof(int));

	if(ptrr == NULL)
	{
		printf("memory reallocation failed\n");
		return 1;
	}

	return 0;
}
