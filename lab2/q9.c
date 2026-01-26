#include <stdio.h>

int asc(int*, int);

int main()
{
	int arr[] = {2, 3, 23, 34};
	int n = sizeof(arr) / sizeof(int);
	int (*fptr)(int*, int);

	printf("Choose an option:\n1.Ascending\n2.Descending\n");
	int opt;
	scanf("%d", &opt);
	fptr = &asc;
	fptr(arr, n);

	if(!(opt - 1))
		for(int i = 0; i < n; i++)
			printf("%d ", arr[i]);
	else if(opt - 1)
		for(int i = 0; i < n; i++)
			printf("%d ", arr[n - i - 1]);
	printf("\n");
}

int asc(int arr[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - 1 - i; j++)
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
