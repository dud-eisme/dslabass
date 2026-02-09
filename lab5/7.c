#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    n1->data = data;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    printf("Nodes to the left of root: %d\n", leftCount);
    printf("Nodes to the right of root: %d\n", rightCount);

    return 0;
}
