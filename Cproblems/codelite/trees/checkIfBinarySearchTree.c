#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* tempNode = (struct node*) malloc(sizeof (struct node));
    tempNode->value = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}

bool isLeafNode(struct node *root) {
    return root->left == NULL && root->right == NULL;
}

bool isBinarySearchTree(struct node *root, int min, int max) {
    if(root == NULL)
        return true;
    if((root->value < min && root->value > max)) {
        return false;
    }
    bool isLeftBST = isBinarySearchTree(root->left, min, root->value-1);
    bool isRightBST = isBinarySearchTree(root->right, root->value +1, max);
    return isLeftBST && isRightBST;
}

int main() {
    struct node *node1 = createNode(1);
    struct node *node2 = createNode(2);
    struct node *node3 = createNode(3);
    struct node *node4 = createNode(4);
    struct node *node5 = createNode(5);
    struct node *node6 = createNode(6);
    struct node *node7 = createNode(7);
    struct node *node8 = createNode(8);
    struct node *node9 = createNode(9);
    node5->right = node8;
    node5->left = node3;
    node3->left = node2;
    node3->right = node4;
    node2->left = node1;
    node8->left = node6;
    node8->right = node9;
    node6->right = node7;
    int minValue = -99999;
    int maxValue = 99999;
    bool isTreeBinarySearchTree = isBinarySearchTree(node5, minValue, maxValue);
    if(!isTreeBinarySearchTree)
        printf("Not a binary search tree! :( ");
    else
        printf("Yayyyyy!! Tree is a binary search tree!! :D ");
    return 0;
}