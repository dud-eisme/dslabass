#include <stdio.h>

void getPoly(int poly[])
{
    for (int i = 0; i <= 2; i++)
  {
    printf("Enter Coefficient of Degree %d: ", i);
    scanf("%d", &poly[i]);
  }
}

int* polySum(int poly1[], int poly2[], int sum[])
{
  for (int i = 0; i <= 2; i++)
    sum[i] = poly1[i] + poly2[i];
  return sum;
}

int main()
{
  int poly1[3], poly2[3], sum[3];
  printf("Polynomial 1:\n");
  getPoly(poly1);
  printf("Polynomial 2:\n");
  getPoly(poly2);

  polySum(poly1, poly2, sum);
  printf("%dx^2 + %dx + %d\n", sum[2], sum[1], sum[0]);

  return 0;
}
