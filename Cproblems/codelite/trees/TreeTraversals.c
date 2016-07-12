// Traversals of a tree

#include <stdio.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->value = data;
    temp->left = NULL;
    temp ->right = NULL;
    return temp;
}

void inorderTraversal(struct node *root){
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d", root->value);
    inorderTraversal(root->right);
}

void postOrderTraversal(struct node *root){
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d", root->value);
}

void preOrderTraversal(struct node *root){
    if(root == NULL) {
        return;
    }
    printf("%d", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(int argc, char **argv)
{
	struct node* node1 = createNode(1);    
    struct node* node2 = createNode(2);
    struct node* node3 = createNode(3);
    struct node* node4 = createNode(4);
    struct node* node5 = createNode(5);
    struct node* node6 = createNode(6);
    struct node* node7 = createNode(7);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    printf("\n******** In-order traversal ********\n");
    inorderTraversal(node1);
    printf("\n\n******** Post-order traversal ********\n");
    postOrderTraversal(node1);
    printf("\n\n******** Pre-order traversal ********\n");
    preOrderTraversal(node1);
	return 0;
}
