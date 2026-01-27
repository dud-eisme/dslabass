#include <stdio.h>
#include <stdlib.h>

struct StudentDets {
  int studID;
  char name[50];
  char dept[20];
  float marks;
};

int main() {
  {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
  }

  int i = 0;

  struct StudentDets *records =
      (struct StudentDets *)malloc(50 * sizeof(struct StudentDets));

  while (true) {
    int opt;

    printf("-----Student Menu-----\n");
    printf("Available options:\n1.\tAdd Record\n2.\tDelete Record\n3.\tSearch "
           "Record\n4.\tExit\nWhich operation would you like to preform? ");
    scanf("%d", &opt);

    if (opt == 1) {
      printf("Student %d Details:\n", i + 1);

      printf("Student ID: ");
      scanf("%d", &records[i].studID);

      printf("Department: ");
      fgets(records[i].dept, sizeof(records[i].dept), stdin);

      printf("Student Name: ");
      fgets(records[i].name, sizeof(records[i].name), stdin);

      printf("Total Marks Obtained: ");
      scanf("%d", &records[i].marks);
      i++;
    }

    if (opt == 2) {
      int optrem;
      printf("Which record would you like to delete? ");
      printf("Available elements: ");

      for (int j = 0; j <= i; j++)
        printf("%d.\tStudent: %d\n", j, records[j].studID);
      printf("Choose option: ");
      scanf("%d", &optrem);

      for (int j = optrem; j < i; j++)
        records[j] = records[j + 1];
      i--;
    }

    if (opt == 3) {
      int idsearch;
      printf("Enter the ID of the Student you would like to access the details "
             "of: ");
      scanf("%d", &idsearch);

      for (int j = 0; j <= i; j++)
        if (records[j].studID == idsearch) {
          printf("Student Details:\n");
          printf("Student ID:\t%d\nStudent Name:\t%s\nDepartment:\t%s\nTotal "
                 "Marks:\t%f\n",
                 records[j].studID, records[j].name, records[j].dept,
                 records[j].marks);
        }
    }

    if (opt == 4)
      return 0;
  }
}
