//Find whether given tree is a binary tree

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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

int getHeight(struct node *node) {
    if(node == NULL) {
        return 0;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if(leftHeight > rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

bool isTreeBalanced(struct node *root) {
    if(root == NULL)
        return true;
    int diffInHeights = abs(getHeight(root->left) - getHeight(root->right));
    return (diffInHeights > 1 ) ? false: true;
}

int main() {
    struct node *root = createNode(1);
    struct node *node2 = createNode(2);
    struct node *node3 = createNode(3);
    struct node *node4 = createNode(4);
    struct node *node5 = createNode(5);
    struct node *node6 = createNode(6);
    struct node *node7 = createNode(7);
    struct node *node8 = createNode(8);
    struct node *node9 = createNode(9);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    node6->left = node7;
    node7->right = node8;
    node8->left = node9;
    bool isBalanced = isTreeBalanced(root);
    if(!isBalanced)
        printf("Not a balanced binary tree");
    else
        printf("Given binary tree is balanced!! ");
    return 0;
}