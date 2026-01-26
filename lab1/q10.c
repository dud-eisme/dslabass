#include <stdio.h>

struct Student{
	char name[50];
	int rollno;
	float marks;
};

int main()
{
	struct Student s1 = {"student", 34, 23.50};

	struct Student *ptr;
	ptr = &s1;

	printf("%d\n", ptr->rollno);
	return 0;
}
