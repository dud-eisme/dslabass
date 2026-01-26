#include <stdio.h>

int main()
{
	const int a = 5;
	int b = 4;

	//pointer to constant integer a
	const int *ptrcon = &a;
	
	//constant pointer to integer b
	int *const conptr = &b;

	//constant pointer to constant integer a
	const int *const conptrcon = &a;

	printf("value of a: %d\n", *ptrcon);
	//these commands will not be executed as constant integers and constant pointers cannot be reassigned
	//*ptrcon = 25;
	//printf("value of a after reassigning: %d\n", *ptrcon);
	//*conptrcon = 30;
	//printf("value of a after reassigning: %d\n", *conptrcon);
	//conptrcon = &b;
	printf("value of b: %d\n", *conptr);
	*conptr = 25;
	printf("value of b after reassigning: %d\n", *conptr);
}
