#include <stdio.h>

int main()
{
  printf("Enter number of elements in the array: ");
  int n;
  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter element [%d]: ", i);
    scanf("%d", &arr[i]);
  }

  int firstL = 0, secondL = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > firstL)
    {
      secondL = firstL;
      firstL = arr[i];
    }
    else if (arr[i] > secondL && arr[i] != firstL)
      secondL = arr[i];
  }

  printf("Second Largest Element: %d\n", secondL);

  return 0;
}
