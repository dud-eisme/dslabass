#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  printf("Name: ");
  fgets(s->name, sizeof(s->name), stdin);
  s->name[strcspn(s->name, "\n")] = 0;
  printf("Department: ");
  fgets(s->dept, sizeof(s->dept), stdin);
  s->dept[strcspn(s->dept, "\n")] = 0;

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

void display(struct StudentDets s) {
  printf("\nRoll: %d | Name: %-15s | Dept: %-10s | Total: %.2f | Avg: %.2f",
         s.rollno, s.name, s.dept, s.total, s.average);
}

int main() {
  int n;
  printf("How many students are there? ");
  scanf("%d", &n);
  struct StudentDets *records =
      (struct StudentDets *)malloc(n * sizeof(struct StudentDets));

  while (true) {
    printf("\n\n");
    printf("---Menu---\n");
    printf("1.\tAdd Students\n2.\tDisplay all Records\n3.\tSearch Student by "
           "Roll Number\n4.\tUpdate Student Marks\nSelect an option: ");
    int opt;
    scanf("%d", &opt);

    if (opt == 1) {
      records = (struct StudentDets *)realloc(
          records, (n + 1) * sizeof(struct StudentDets));

        printf("Student %d Details\n", n + 1);
        inputData(&records[n]);
        calculate(&records[n++]);
    }

    else if (opt == 2) {
      if (n == 0)
        printf("\nNo records found.");
      for (int i = 0; i < n; i++)
        display(records[i]);
    }

    else if (opt == 3) {
      int rollse, found = 0;
      printf("Enter Roll Number to search: ");
      scanf("%d", &rollse);
      for (int i = 0; i < n; i++) {
        if (records[i].rollno == rollse) {
          display(records[i]);
          found = 1;
          break;
        }
      }
      if (!found)
        printf("\nStudent not found.");
    }

    else if (opt == 4) {
      int targetRoll, found = 0;
      printf("\nEnter Roll Number to update marks: ");
      scanf("%d", &targetRoll);

      for (int i = 0; i < n; i++) {
        if (records[i].rollno == targetRoll) {
          printf("Student Found: %s\n", records[i].name);

          // Input new marks
          for (int j = 0; j < 3; j++) {
            printf("Enter new Marks for Subject %d: ", j + 1);
            scanf("%f", &records[i].marks[j]);
          }

          // Important: Update total and average
          calculate(&records[i]);

          printf("Marks updated successfully!\n");
          found = 1;
          break; // Exit loop once found
        }
      }

      if (!found) {
        printf("Error: Roll Number %d not found.\n", targetRoll);
      }
    }

    else if (opt == 5)
      return 0;
  }
}
