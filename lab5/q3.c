#include <stdio.h>
#define MAX 100

typedef struct {
  int row;
  int col;
  int val;
} Triple;

void transpose(Triple b[], Triple t[]) {
  int row_terms[MAX], start_pos[MAX];
  int i, j, num_cols = b[0].col, num_terms = b[0].val;
  t[0].row = num_cols;
  t[0].col = b[0].row;
  t[0].val = num_terms;

  if (num_terms > 0) {
    for (i = 0; i < num_cols; i++)
      row_terms[i] = 0;
    for (i = 1; i <= num_terms; i++)
      row_terms[b[i].col]++;

    start_pos[0] = 1;
    for (i = 1; i < num_cols; i++)
      start_pos[i] = start_pos[i - 1] + row_terms[i - 1];

    for (i = 1; i <= num_terms; i++) {
      j = start_pos[b[i].col]++;
      t[j].row = b[i].col;
      t[j].col = b[i].row;
      t[j].val = b[i].val;
    }
  }
}

int main() {
  Triple a[MAX] = {{3, 3, 2}, {0, 1, 10}, {1, 2, 20}};
  Triple b[MAX] = {{3, 3, 2}, {0, 1, 5}, {2, 2, 30}};
  Triple result[MAX];
  Triple btrans[MAX];
  transpose(b, btrans);

  if (a[0].col != b[0].row) {
    printf("Multiplication not possible: Dimensions mismatch!\n");
    return -1;
  }

  int i = 1, k = 1;
  int a_terms = a[0].val;
  int b_terms = b[0].val;

  while (i <= a_terms) {
    int current_row = a[i].row;
    int j = 1;

    while (j <= b_terms) {
      int current_col = btrans[j].row;
      int temp_a = i;
      int temp_b = j;
      int sum = 0;

      // Compute dot product for the current row of A and column of B
      while (temp_a <= a_terms && a[temp_a].row == current_row &&
             temp_b <= b_terms && btrans[temp_b].row == current_col) {

        if (a[temp_a].col < btrans[temp_b].col) {
          temp_a++;
        } else if (a[temp_a].col > btrans[temp_b].col) {
          temp_b++;
        } else {
          sum += a[temp_a++].val * btrans[temp_b++].val;
        }
      }

      if (sum != 0) {
        result[k].row = current_row;
        result[k].col = current_col;
        result[k].val = sum;
        k++;
      }

      while (j <= b_terms && btrans[j].row == current_col)
        j++;
    }
    while (i <= a_terms && a[i].row == current_row)
      i++;
  }

  result[0].row = a[0].row;
  result[0].col = b[0].col;
  result[0].val = k - 1;

  printf("\nRow\tCol\tValue\n");
  for (int i = 0; i <= result[0].val; i++) {
    printf("%d\t%d\t%d\n", result[i].row, result[i].col, result[i].val);
  }
  return 0;
}
