#include <stdio.h>

int main()
{
  printf("Enter the total number of students: ");
  int n;
  scanf("%d", &n);
  int studarr[n];
  int sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    printf("Enter roll number of student [%d]: ", i + 1);
    scanf("%d", &studarr[i]);
    sum += studarr[i];
  }
  printf("Student [%d] is absent\n", ((n * (n + 1)) / 2) - sum);

  return 0;
}
