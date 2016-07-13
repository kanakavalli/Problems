// Consider tree like in the given link - http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/image4.png
// Print output like this 1 2 3 4 7 5 6 8 15 9 14 10 13 11 12 16 31 17 30 18 29 19 28 20 27 21 26  22 25 23 24

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
    if(tempNode == NULL)
        return;
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
    struct node *headNode1 = queue->array[queue->head];
    struct node *headNode2 = queue->array[queue->head +1];
    while(headNode1 != NULL || headNode2 != NULL) {
        if(headNode1 != NULL && headNode2 == NULL) {
            pushToQueue(queue, headNode1->left);
            pushToQueue(queue, headNode1->right);
        } else if(headNode2 != NULL && headNode1 == NULL) {
            pushToQueue(queue, headNode2->right);
            pushToQueue(queue, headNode2->left);
        } else {
            pushToQueue(queue, headNode1->left);
            pushToQueue(queue, headNode2->right);
            pushToQueue(queue, headNode1->right);
            pushToQueue(queue, headNode2->left);
        }
        if(headNode1 != NULL) {
            struct node *poppedHeadNode1 = popFromQueue(queue);
            printf("\n %d ", poppedHeadNode1->value);
        }
        if(headNode2 != NULL) {
            struct node *poppedHeadNode2 = popFromQueue(queue);
            printf("\n %d ", poppedHeadNode2->value);
        }
        headNode1 = queue->array[queue->head];
        headNode2 = queue->array[queue->head +1];
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
    struct node* node10 = createNode(10);
    struct node* node11 = createNode(11);
    struct node* node12 = createNode(12);
    struct node* node13 = createNode(13);
    struct node* node14 = createNode(14);
    struct node* node15 = createNode(15);
    
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node3->left = node6;
    node3->right = node7;
    
    node4->left = node8;
    node4->right = node9;

    node5->left = node10;
    node5->right = node11;
    
    node6->left = node12;
    node6->right = node13;

    node7->left = node14;
    node7->right = node15;
    
    levelOrderTraversal(node1, 15);
	return 0;
}
