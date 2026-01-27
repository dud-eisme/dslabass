#include <stdio.h>

float power(float x, int degree)
{
  if (degree == 0)
    return 1;
  return x * power(x, degree - 1);
}

float evaluatePolynomial(int poly[], int degree, float x)
{
  int eval = 0;
  for (int i = 0; i <= degree; i++)
    eval += (poly[i] * (power(x, degree - i)));
  return eval;
}

int main()
{
  printf("Enter Highest Degree in you Polynomial: ");
  int degree;
  scanf("%d", &degree);

  int poly[degree];
  for (int i = 0; i <= degree; i++)
  {
    printf("Enter Coefficient of Degree %d: ", degree - i);
    scanf("%d", &poly[i]);
  }

  for (int i = 0; i <= degree; i++)
  {
    printf("%dx^%d ", poly[i], degree - i);
    if (i == degree)
      printf("\n\n");
    else 
      printf("+ ");
  }

  float x;
  printf("Enter the value of x for which you would like to solve this polynimial: ");
  scanf("%f", &x);

  printf("Value of polynomial for x = %f is %f\n", x, evaluatePolynomial(poly, degree, x));
}
