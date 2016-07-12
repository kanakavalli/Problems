// Lever order traversal of a tree

#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct Queue {
    int head, tail;
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


bool isEmpty(struct Queue *queue) {
    if(queue->head == -1)
        return true;
    else 
        return false;
}

void pushToQueue(struct Queue *queue, struct node *tempNode) {
    if(isEmpty(queue)) {
        ++queue->head;
        ++queue->tail;
        queue->array[queue->head] = tempNode;
    } else {
        queue->array[++queue->tail] = tempNode;
    }
}

struct node* popFromQueue(struct Queue *queue) {
    if(isEmpty(queue)) {
        return NULL;
    }
    struct node *temp = queue->array[queue->head];
    ++queue->head;
    return temp;
}

struct Queue* createQueue(int sizeOfQueue) {
    struct Queue *queue  = (struct Queue*) malloc(sizeof(struct Queue));
    queue->size = sizeOfQueue;
    queue->head = queue->tail = -1;
    queue->array = (struct node**) malloc(queue->size * sizeof(struct node));
    int i;
    for(i=0; i<sizeOfQueue; i++){
        queue->array[i] = NULL;
    }
    return queue;
}

void levelOrderTraversal(struct node *root, int noOfNodes) {
    struct Queue *queue = createQueue(noOfNodes);
    struct node *tempNode = root;
    pushToQueue(queue, tempNode);
    while(tempNode != NULL) {
        if(tempNode->left != NULL)
            pushToQueue(queue, tempNode->left);
        if(tempNode->right != NULL)
            pushToQueue(queue, tempNode->right);
        struct node *poppedNode = popFromQueue(queue);
        printf("\n %d ", poppedNode->value);
        tempNode = queue->array[queue->head];
    }
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
    
    levelOrderTraversal(node1, 7);
	return 0;
}
