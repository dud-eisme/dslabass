#include <stdio.h>

void mTriplet(int rows, int cols, int matrix[rows][cols],
              int triplet[rows][3]) {
  int k = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] != 0) {
        triplet[k][0] = i;
        triplet[k][1] = j;
        triplet[k][2] = matrix[i][j];
        k++;
      }
    }
  }
  triplet[0][2] = k - 1;
}

int main() {
  int rows, cols;
  printf("Enter rows and columns: ");
  scanf("%d %d", &rows, &cols);
  int matrix[rows][cols];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) {
      printf("Enter element [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }

  int triplet[rows][3];
  triplet[0][0] = rows;
  triplet[0][1] = cols;
  mTriplet(rows, cols, matrix, triplet);

  int n = triplet[0][2];
  printf("\nRow\tCol\tValue\n");
  for (int i = 0; i <= n; i++) {
    printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
  }

  return 0;
}
