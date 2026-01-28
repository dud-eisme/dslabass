#include <stdio.h>

void printMatrix(int m, int n, int *aptr[][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      printf("%d\t", *aptr[i][j]);
    printf("\n");
  }
}

void sumOfRaC(int m, int n, int *aptr[][n]) {
  // Row
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++)
      sum += *aptr[i][j];
    printf("Sum of row %d: %d\n", i + 1, sum);
  }

  // Column
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++)
      sum += *aptr[j][i];
    printf("Sum of column %d: %d\n", i + 1, sum);
  }
}

void transposeMatrix(int m, int n, int *aptr[][n]) {
  int twod_arr_tr[n][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      twod_arr_tr[j][i] = *aptr[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      printf("%d\t", twod_arr_tr[i][j]);
    printf("\n");
  }
}

void printMaxMin(int m, int n, int *aptr[][n]) {
  int max = 0, min = *aptr[0][0];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (max < *aptr[i][j])
        max = *aptr[i][j];
      if (min > *aptr[i][j])
        min = *aptr[i][j];
    }
  printf("Maximum: %d\nMinimum: %d\n", max, min);
}

int main() {
  int m, n;
  printf("Enter size of matrix (M x N): ");
  {
    char temp;
    scanf("%d %c %d", &m, &temp, &n);
  }

  int twod_arr[m][n];
  int *aptr[m][n];

  // Initialization and assigning values to the two dimensional array
  for (int i = 0, count = 1; i < m; i++)
    for (int j = 0; j < n; j++, count++)
      twod_arr[i][j] = count;

  // Assigning aptr pointer to the two dimensional array
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      aptr[i][j] = &twod_arr[i][j];

  // Array for above functions
  void (*fptr[4])(int, int, int *arr[][n]) = {printMatrix, sumOfRaC, transposeMatrix,
                                      printMaxMin};

  while (true) {
    printf("\n\n\n");
    printf("---Menu---\n");
    printf("\n1.\tPrint Matrix\n2.\tSum of each Row and Column\n3.\tTranspose "
           "Matrix\n4.\tMaximum and Minimum Element\n5.\tExit\nChoose and "
           "option: ");
    int opt;
    scanf("%d", &opt);

    if (opt == 1)
    {
      fptr[0](m, n, aptr);
    }

    else if (opt == 2)
    {
      fptr[1](m, n, aptr);
    }

    else if (opt == 3)
    {
      fptr[2](m, n, aptr);
    }

    else if (opt == 4)
    {
      fptr[3](m, n, aptr);
    }

    else if (opt == 5) {
      return 0;
    }
  }
}
