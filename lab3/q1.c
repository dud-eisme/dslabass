#include <stdio.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int *ptr = arr;
  int opt = 0;

  printf("Which element of the array would you like to print? ");
  scanf("%d", &opt);
  printf("Element at %d is: %d\n", opt, *(ptr + opt));
}
