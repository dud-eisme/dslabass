#include <stdio.h>
#include <stdlib.h>

struct StudentDets {
  int rollno;
  char name[50];
  char dept[20];
  float marks;
};

int main() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  int opt;
  printf("-----Student Menu-----\n");
  printf("Available options:\n1.\tAdd Record\n2.\tDelete Record\n3.\tSearch Record\nWhich operation would you like to preform? ");
  scanf("%d", &opt);

  if (opt == 1)
  {

  }
}
