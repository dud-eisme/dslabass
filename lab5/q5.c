#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int x)
{
    struct node *n1 = (struct node *)malloc(sizeof(struct node));

    n1->data = x;
    n1->left = NULL;
    n1->right = NULL;
    return n1;
}

int height(struct node *root)
{
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}

int countLeafNodes(struct node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(struct node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);

    printf("Height of tree: %d\n", height(root));
    printf("Total leaf nodes: %d\n", countLeafNodes(root));
    printf("Total internal nodes: %d\n", countInternalNodes(root));

    return 0;
}