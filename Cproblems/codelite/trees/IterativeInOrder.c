// Iterative In-order traversal of a tree

#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct Stack {
    int head;
    int size;
    struct node* *array;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->value = data;
    temp->left = NULL;
    temp ->right = NULL;
    return temp;
}

bool isEmpty(struct Stack *stack) {
    if(stack->head == -1)
        return true;
    else 
        return false;
}

void pushToStack(struct Stack *stack, struct node *tempNode) {
    if(tempNode == NULL)
        return;
    if(stack->head == stack->size -1) {
        printf("Stack size exceeded");
        return;
    } else {
        ++stack->head;
        stack->array[stack->head] = tempNode;
    }
}

struct node* popFromStack(struct Stack *stack) {
    if(isEmpty(stack)) {
        return NULL;
    }
    struct node *temp = stack->array[stack->head];
    --stack->head;
    return temp;
}

struct Stack* createStack(int sizeOfStack) {
    struct Stack *stack  = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = sizeOfStack;
    stack->head = -1;
    stack->array = (struct node**) malloc(stack->size * sizeof(struct node));
    int i;
    for(i=0; i<sizeOfStack; i++){
        stack->array[i] = NULL;
    }
    return stack;
}

void iterativeInOrderTraversal(struct node *root, int noOfNodes) {
    printf("\n********* Iterative in-order traversal of a binary tree *********\n");
    struct Stack *stack = createStack(noOfNodes);
    struct node *tempNode = root;
    pushToStack(stack, tempNode);
    while(!isEmpty(stack)) {
        while(tempNode != NULL){
            pushToStack(stack, tempNode->left);
            tempNode = tempNode->left;
        }
        struct node* poppedItem = popFromStack(stack);
        printf("\n %d", poppedItem->value);
        pushToStack(stack, poppedItem->right);
        tempNode = poppedItem->right;
    }
}

int main(int argc, char **argv) {
    struct node* node1 = createNode(1);    
    struct node* node2 = createNode(2);
    struct node* node3 = createNode(3);
    struct node* node4 = createNode(4);
    struct node* node5 = createNode(5);
    struct node* node6 = createNode(6);
    struct node* node7 = createNode(7);
    struct node* node8 = createNode(8);
    struct node* node9 = createNode(9);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->right = node6;
    node5->left = node7;
    node5->right = node8;
    node6->left = node9;
    
    iterativeInOrderTraversal(node1, 9);
    return 0;
}
