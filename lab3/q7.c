#include <stdio.h>

void sortAscending(int arr[], int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void sortDescending(int arr[], int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int returnAdd(int arr[], int size, int element) {
  for (int i = 0; i < size; i++)
    if (element == arr[i])
      return i;
}

int avg(int arr[], int size)
{
  int avg = 0;
  for (int i = 0; i < size; i++)
    avg += arr[i];
  return avg;
}

int main() {
  int n;
  printf("Enter number of elements in the integer array: ");
  scanf("%d", &n);

  int arr[n];
  int *ptr = arr;

  for (int i = 0; i < n; i++) {
    printf("Enter element [%d]: ", i);
    scanf("%d", &arr[i]);
  }
}
