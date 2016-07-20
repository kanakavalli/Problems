// Given 2 linked lists, perform its add operation

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

struct node* addLinkedLists(struct node *ll1, struct node *ll2) {
    struct node *resultList = NULL;
    struct node *newListHead = NULL;
    struct node *head1 = ll1;
    struct node *head2 = ll2;
    int carry = 0;
    while(head1 != NULL || head2 != NULL) {
        int head1Value = (head1 != NULL) ? head1->value : 0;
        int head2Value = (head2 != NULL) ? head2->value : 0;
        int sumOfTwoNodes = head1Value + head2Value + carry;
        if(sumOfTwoNodes > 9) {
            carry = 1;
            sumOfTwoNodes = sumOfTwoNodes%10;
        } else {
            carry = 0;
        }
        if(resultList != NULL) {
            resultList->next = createNode(sumOfTwoNodes);
            resultList = resultList->next;
        } else {
            resultList = createNode(sumOfTwoNodes);
            newListHead = resultList;
        }
        head1 = (head1 != NULL) ? head1->next : NULL;
        head2 = (head2 != NULL) ? head2->next : NULL;
    }
    return newListHead;
}

void printLinkedList(struct node *head) {
    printf("\nNew linked list \n");
    while(head != NULL){
        printf("  %d   ", head->value);
        head = head->next;
    }
}

int main() {
    struct node *l1n1 = createNode(1);
    struct node *l1n2 = createNode(3);
    struct node *l1n3 = createNode(9);
    l1n1->next = l1n2;
    l1n2->next = l1n3;
    
    struct node *l2n1 = createNode(4);
    struct node *l2n2 = createNode(9);
    struct node *l2n3 = createNode(5);
    l2n1->next = l2n2;
    l2n2->next = l2n3;
    
    struct node *reversedList1 = reverseLinkedList(l1n1);
    struct node *reversedList2 = reverseLinkedList(l2n1);
    struct node *addedLinkedList = addLinkedLists(reversedList1, reversedList2);
    struct node *reverseResultList = reverseLinkedList(addedLinkedList);
    printf("\n Result is ");
    printLinkedList(reverseResultList);
    return 0;
}

//There is a bug find it
//try for other solution