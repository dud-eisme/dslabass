#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

int main()
{
  printf("Enter total elements in the array: ");
  int n;
  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter element [%d]: ", i);
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n / 2; i++)
  {
    swap(&arr[i], &arr[n - i - 1]);
  }

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
