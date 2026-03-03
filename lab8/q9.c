#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct node {
  char data;
  struct node *left, *right;
};

struct node *stack[MAX];
int top = -1;

void push(struct node *n) { stack[++top] = n; }

struct node *pop() { return stack[top--]; }

struct node *newNode(char c) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = c;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *buildTree(char prefix[]) {
  int len = strlen(prefix);

  // Process from right to left for Prefix expressions
  for (int i = len - 1; i >= 0; i--) {
    if (isalnum(prefix[i])) {
      push(newNode(prefix[i]));
    } else {
      struct node *node = newNode(prefix[i]);

      // First pop becomes the left child, second becomes the right child
      node->left = pop();
      node->right = pop();

      push(node);
    }
  }
  return pop();
}

void inorder(struct node *root) {
  if (root) {
    // Add parentheses around sub-expressions for clarity
    if (!isalnum(root->data))
      printf("(");

    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);

    if (!isalnum(root->data))
      printf(")");
  }
}

void postorder(struct node *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
  }
}

int main() {
  char prefix[MAX];
  printf("Enter Prefix Expression: ");
  scanf("%s", prefix);

  struct node *root = buildTree(prefix);

  printf("Inorder : ");
  inorder(root);

  printf("\nPostorder : ");
  postorder(root);

  return 0;
}
