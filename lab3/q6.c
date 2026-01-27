#include <stdio.h>

struct Book {
  char title[100];
  char author[50];
  float price;
};

int main() {
  int n;
  printf("Number of books in the Library: ");
  scanf("%d", &n);

  struct Book library[n];

  // Storing
  printf("Enter Details of 5 Books\n");
  for (int i = 0; i < n; i++) {
    printf("Book %d:\n", i + 1);

    printf("Title: ");
    fgets(library[i].title, sizeof(library[i].title), stdin);

    printf("Author: ");
    fgets(library[i].author, sizeof(library[i].author), stdin);

    printf("Price: ");
    scanf("%f", &library[i].price);
  }

  // Printing
  for (int i = 0; i < n; i++) {
    printf("Book %d:\n", i + 1);

    printf("Title:\t%s\n", library[i].title);

    printf("Author:\t%s\n", library[i].author);

    printf("Price:\t%.2f\n", library[i].price);
  }
}
