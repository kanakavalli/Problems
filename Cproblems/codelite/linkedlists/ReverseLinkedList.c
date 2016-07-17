//Reverse a given linked list

#include <stdio.h>

struct node{
    int value;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;
    return temp;
}

struct node* reverseLinkedList(struct node *head) {
    struct node* tempNode = NULL;
    struct node* tempHead = NULL;
    while(head != NULL) {
        tempNode = head -> next;
        head->next = tempHead;
        tempHead = head;
        head = tempNode;
    }
    return tempHead;
}

void printLinkedList(struct node *head) {
    printf("\nNew linked list \n");
    while(head != NULL){
        printf("  %d   ", head->value);
        head = head->next;
    }
}

int main(int argc, char **argv) {
    struct node *node1 = createNode(1);
    struct node *node2 = createNode(2);
    struct node *node3 = createNode(3);
    struct node *node4 = createNode(4);
    struct node *node5 = createNode(5);
    struct node *node6 = createNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    struct node* reversedList = reverseLinkedList(node1);
    printLinkedList(reversedList);
    return 0;
}
