#include <stdio.h>

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

int main()
{
	float (*fptr)(float, float);

	float a, b;
	printf("Enter two numbers: ");
	scanf("%f %f", &a, &b);

	printf("Select an option:\n1.\tAddition\n2.\tSubtraction\n3.\tMultiplication\n4.\tDivision\n");
	int n;
	scanf("%d", &n);

	if (n == 1)
	{
		fptr = &add;
		printf("Sum of the numbers is: %f\n", fptr(a, b));
	}
	else if (n == 2)
	{
		fptr = &subtract;
		printf("Subtraction of the numbers is: %f\n", fptr(a, b));
	}
	else if (n == 3)
	{
		fptr = &multiply;
		printf("Multiplication of the numbers is: %f\n", fptr(a, b));
	}
	else if (n == 4)
	{
		fptr = &divide;
		if (b)
			printf("Division of the numbers is: %.4f\n", fptr(a, b));
		else
			fptr(a, b);
	}
}

float add(float a, float b)
{
	return a + b;
}

float subtract(float a, float b)
{
	return a - b;
}

float multiply(float a, float b)
{
	return a * b;
}

float divide(float a, float b)
{
	if(!b)
	{
		printf("Divisibility by zero is not possible.\n");
		return 0;
	}
	return a / b;
}
