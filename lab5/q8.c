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

int countLeafNode(struct node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;

    return countLeafNode(root->left) + countLeafNode(root->right);
}

int countInternalNode(struct node* root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;

    return 1+countLeafNode(root->left) + countLeafNode(root->right);
}

int main(){

    struct node* root=createNode(72);
    root->left=createNode(73);
    root->right=createNode(74);
    root->left->left=createNode(75);
    root->left->right=createNode(76);
    root->left->left->left=createNode(77);
    root->left->left->left->left=createNode(78);

    printf("No of Leaf Node is %d\n",countLeafNode(root));
    printf("No of Internal Node is %d\n",countInternalNode(root));
    return 0;
}