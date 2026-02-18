#include "treeops.h"

struct Node* insert(struct Node* root, int data) {
  if (root == NULL)
    return newNode(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);

  return root;
}
struct Node* createBST(int arr[], int n) {
  struct Node* root = NULL;
  for (int i = 0; i < n; i++)
    root = insert(root, arr[i]);

  return root;
}

int main() {
  printf("How many nodes will you be entering: ");
  int n;
  scanf("%d", &n);
  int arr[n];
  printf("Enter node data: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  struct Node* treeroot = createBST(arr, n);

  printf("Pre Order:\t");
  preOrder(treeroot);
  printf("\nIn Order:\t");
  inOrder(treeroot);
  printf("\nPost Order:\t");
  postOrder(treeroot);
  printf("\n");

  return 0;
}
