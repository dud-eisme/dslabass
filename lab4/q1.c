#include <stdio.h>

int main() {
  printf("Enter the number of elements the array should have: ");
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Enter element [%d]: ", i);
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
      printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
