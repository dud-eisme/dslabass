#include <stdio.h>
#include <string.h>

int main() {
  char inp[50];
  printf("Enter a string: ");
  scanf("%s", &inp);
  int count = 0;
  for (; inp[count] != '\0'; count++)
    ;
  printf("Length of inputted string (only first word taken as input): %d\n",
         count);
}
