#include <stdio.h>

int main() {
  int a[3][3] = {{3, 3, 2}, {0, 1, 10}, {1, 2, 20}};
  int b[3][3] = {{3, 3, 2}, {0, 1, 5}, {2, 2, 30}};

  if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
    printf("Addition not possible: Dimensions mismatch!\n");
    return 1;
  }

  int sum[10][3];

  int i = 1, j = 1, k = 1;
  int m = a[0][2];
  int n = b[0][2];

  while (i <= m && j <= n) {
    if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
      sum[k][0] = a[i][0];
      sum[k][1] = a[i][1];
      sum[k][2] = a[i][2];
      i++;
      k++;
    }
    else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
      sum[k][0] = b[j][0];
      sum[k][1] = b[j][1];
      sum[k][2] = b[j][2];
      j++;
      k++;
    }
    else {
      int val = a[i][2] + b[j][2];
      if (val != 0) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = val;
        k++;
      }
      i++;
      j++;
    }
  }

  while (i <= m) {
    sum[k][0] = a[i][0];
    sum[k][1] = a[i][1];
    sum[k][2] = a[i][2];
    i++;
    k++;
  }
  while (j <= n) {
    sum[k][0] = b[j][0];
    sum[k][1] = b[j][1];
    sum[k][2] = b[j][2];
    j++;
    k++;
  }

  sum[0][0] = a[0][0];
  sum[0][1] = a[0][1];
  sum[0][2] = k - 1;

  printf("\nResultant Triplet:\nRow\tCol\tValue\n");
  for (int x = 0; x <= sum[0][2]; x++) {
    printf("%d\t%d\t%d\n", sum[x][0], sum[x][1], sum[x][2]);
  }

  return 0;
}
