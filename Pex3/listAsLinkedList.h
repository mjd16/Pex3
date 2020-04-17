/** listAsLinkedList.h
* ================================================================
* Name: Maxwell Di Lalla
* Section: T2
* Project: Linked List Library Header
* =================================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
#define USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
#include <stdbool.h>

// Define a node of the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct LinkedList{
    Node* head;
    Node* tail;
    int numberOfElements;
} LinkedList;

// Functions that manipulate a linked list
LinkedList* createLinkedList(void);
Node* initializeNode(int newData);
void deleteLinkedList(LinkedList* list);
void appendElementLinkedList(LinkedList* list, int element);
int lengthOfLinkedList(LinkedList* list);

int getElementLinkedList(LinkedList* list, int position);


void deleteElementLinkedList(LinkedList* list, int position);


#endif //USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
