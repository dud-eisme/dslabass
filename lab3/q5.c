#include <stdio.h>

struct Book {
  int bookID;
  char title[100];
  char author[50];
  float price;
};

int main() {
  struct Book library[5];

  // Storing
  printf("Enter Details of 5 Books\n");
  for (int i = 0; i < 5; i++) {
    printf("Book %d:\n", i + 1);
    printf("Book ID: ");
    scanf("%d", &library[i].bookID);

    printf("Title: ");
    fgets(library[i].title, sizeof(library[i].title), stdin);

    printf("Author: ");
    fgets(library[i].author, sizeof(library[i].author), stdin);

    printf("Price: ");
    scanf("%f", &library[i].price);
  }

  // Printing
  for (int i = 0; i < 5; i++) {
    printf("Book %d:\n", i + 1);

    printf("Book ID:\t%d\n", library[i].bookID);

    printf("Title:\t%s\n", library[i].title);

    printf("Author:\t%s\n", library[i].author);

    printf("Price:\t%.2f\n", library[i].price);
  }
}
