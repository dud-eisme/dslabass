#include <stdio.h>
#include <stdlib.h>

int main()
{
	//NULL Pointers:
	int *ptrnull = NULL;
	printf("Value of NULL pointer = %d\n", ptrnull);


	//Void Pointers:
	int a = 10;
	char b = 'x';
	void *ptrvoid;
	ptrvoid = &a;
	printf("Address of a = %d\n", ptrvoid); //will print address of a
	ptrvoid = &b;				//void printers can point to any variable type
	printf("Address of b = %d\n", ptrvoid); //will print address of b


	//Dangling Pointers:
	int *ptr = (int*)malloc(sizeof(int));
	free(ptr);
	printf("%d\n", ptr); //will print an invalid address of the dangling pointer
	printf("%d\n", &ptr); //will print an invalid value as there is no variablbe it is pinting to anymore
}
