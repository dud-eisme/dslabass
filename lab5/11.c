#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left;
    struct node* right;
};

struct node* createNode(int x){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));

    newNode->value=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int search(struct node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->value == key)
        return 1;

    return search(root->left, key) || search(root->right, key);
}

int main(){

    struct node* root=createNode(72);
    root->left=createNode(73);
    root->right=createNode(74);
    root->left->left=createNode(75);
    root->left->right=createNode(76);
    root->left->left->left=createNode(77);
    root->left->left->left->left=createNode(78);

    int key=76;

    if (search(root, key))
        printf("SUCCESS\n");
    else
        printf("Element not found\n");

    return 0;
}