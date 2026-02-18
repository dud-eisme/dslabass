#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int dat) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = dat;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
