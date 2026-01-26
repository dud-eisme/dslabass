#include <stdio.h>

int main() {
  int m, n;
  printf("Enter size of array (M x N): ");
  {
    char temp;
    scanf("%d %c %d", &m, &temp, &n);
  }
  int twod_arr[m][n] = {{0}};
  int *aptr[m][n];
  aptr[0][0] = &twod_arr[0][0];
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
      printf("%d", aptr[i][j]);
    printf("\n");
  }
}
