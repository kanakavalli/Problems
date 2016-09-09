//The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree

//Yet to finish this - TODO

//Please find the updated code in JS folder of the repo.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node *tempNode = (struct node*) malloc (sizeof (struct node));
    tempNode->value = data;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}

bool isLeafNode(struct node *root) {
    return root->left == NULL && root->right == NULL;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth(struct node *root) {
    if(root == NULL) {
        return 0;
    }
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int findDiameter(struct node *root) {
    if(root == NULL)
        return 0;
    int depthOfLeftSubTree = depth(root->left);
    int depthOfRightSubTree = depth(root->right);
    int maxDepthOfLeftTree = findDiameter(root->left);
    int maxDepthOfRightTree = findDiameter(root->right);
    return max(depthOfLeftSubTree+depthOfRightSubTree+1,max(maxDepthOfLeftTree, maxDepthOfRightTree));
}

int main(){
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
    int maximumDepth = findDiameter(root);
    printf("\n Diameter of given binary tree is %d", maximumDepth);
}
