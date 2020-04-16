//
//  linkedListMath.h
//  Pex3
//
//  Created by Max DiLalla  on 4/16/20.
//  Copyright © 2020 Max DiLalla . All rights reserved.
//

#ifndef linkedListMath_h
#define linkedListMath_h

#include <stdio.h>
#include <stdbool.h>

// Define a node of the linked list
typedef struct node {
    bool isMixed;
    char* data;
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
Node* initializeNode(char* newData, bool isMixed);
void deleteLinkedList(LinkedList* list);
void appendElementLinkedList(LinkedList* list, char* number, bool isMixed);
int lengthOfLinkedList(LinkedList* list);
void deleteElementLinkedList(LinkedList* list, int position);

#endif /* linkedListMath_h */
