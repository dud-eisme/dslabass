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

void inOrder(struct node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    inOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    return 0;
}
