#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StudentDets {
  int rollno;
  char name[50];
  char dept[25];
  float marks[3];
  float total, average;
};

void inputData(struct StudentDets *s) {
    printf("Roll Number: ");
    scanf("%d", &s->rollno);
    printf("Name: ");
    scanf(" %[^\n]s", s->name); // Reads string with spaces
    printf("Department: ");
    scanf(" %[^\n]s", s->dept);
    
    for (int i = 0; i < 3; i++) {
        printf("Marks in Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
}

void calculate(struct StudentDets *s) {
    s->total = 0;
    for (int i = 0; i < 3; i++) {
        s->total += s->marks[i];
    }
    s->average = s->total / 3.0;
}

int main()
{
  int n;
  printf("How many students are there? ");
  scanf("%d", &n);

  struct StudentDets *records = (struct StudentDets *)malloc(n * sizeof(struct StudentDets));

  if (records == NULL)
  {
    printf("Memory allocation falied\n");
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    printf("Student %d Details\n", i + 1);
    inputData(&records[i]);
    calculate(&records[i]);
  }
}
