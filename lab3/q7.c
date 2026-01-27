#include <stdio.h>
#include <stdlib.h>

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

int avg(int arr[], int size) {
  int avg = 0;
  for (int i = 0; i < size; i++)
    avg += arr[i];
  return (avg / size);
}

void printElements(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d\t", arr[i]);
  printf("\n");
}

int main() {

#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  int n;
  printf("Enter number of elements in the integer array: ");
  scanf("%d", &n);

  int arr[n];
  int *ptr = arr;

  for (int i = 0; i < n; i++) {
    printf("Enter element [%d]: ", i);
    scanf("%d", &arr[i]);
  }

#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  // Menu
  int opt;
  printf("-----ARRAY OPERATIONS MENU-----\nAvailable Options:\n1.\tSort in "
         "Ascending\n2.\tSort in Descending\n3.\tSearch for an "
         "element\n4.\tFind Maximum and Minimum values\n5.\tCalculate average "
         "of the elements\nChoose and option: ");
  scanf("%d", &opt);

  if (opt == 1) {
    sortAscending(arr, n);
    printElements(arr, n);
  }

  else if (opt == 2) {
    sortDescending(arr, n);
    printElements(arr, n);
  }

  else if (opt == 3) {
    printf("Enter the element you would like the address of (in the array): ");
    int inp;
    scanf("%d", inp);
    printf("Element %d is present at %d\n", inp, returnAdd(arr, n, inp));
  }

  else if (opt == 4) {
    sortAscending(arr, n);
    printf("Maximum Value:\t%d\nMinimum Value:\t%d\n", arr[0], arr[n - 1]);
  }

  else if (opt == 5) {
    printf("Average of all elements in the array is: %d\n", avg(arr, n));
  }
}
