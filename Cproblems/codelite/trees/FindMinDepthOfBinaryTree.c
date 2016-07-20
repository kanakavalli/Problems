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

int findMinDepthOfBinaryTree(struct node *root) {
    if(root == NULL) {
        return 0;
    }
    if(isLeafNode(root)) {
        return 1;
    }
    if(root->left != NULL) {
        return 1 + findMinDepthOfBinaryTree(root->left);
    } else if(root->right != NULL) {
        return 1 + findMinDepthOfBinaryTree(root->right);
    } else {
        int depthOfLeftSubtree = findMinDepthOfBinaryTree(root->left);
        int depthOfRightSubtree = findMinDepthOfBinaryTree(root->right);
        if(depthOfLeftSubtree < depthOfRightSubtree)
            return depthOfLeftSubtree + 1;
        else 
            return depthOfRightSubtree + 1;
    }
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
    int minDepth = findMinDepthOfBinaryTree(root);
    printf("\n Minimum depth of given binary tree is %d", minDepth);
}