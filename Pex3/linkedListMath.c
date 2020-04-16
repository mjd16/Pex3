//
//  linkedListMath.c
//  Pex3
//
//  Created by Max DiLalla  on 4/16/20.
//  Copyright © 2020 Max DiLalla . All rights reserved.
//

#include "linkedListMath.h"

#include <stdio.h>
#include "listAsLinkedList.h"
#include <stdlib.h>


LinkedList* createLinkedList() {
    LinkedList* list;
    list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

Node* initializeNode(char* newData, bool isMixed) {
    Node* newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->isMixed = isMixed;
    newNode->next = NULL;
    
    return newNode;
}

void deleteLinkedList(LinkedList* list) {
    if (list->head == NULL)
        return;
    Node* tempPtr = list->head;
    Node* freePtr = NULL;
    while (tempPtr != NULL) {
        freePtr = tempPtr;
        tempPtr = tempPtr->next;
        free(freePtr);
    }
    free(list);
}

void appendElementLinkedList(LinkedList* list, char* number, bool isMixed) {
    Node* temp = malloc(sizeof(Node));
    temp = initializeNode(number, isMixed);
    if (list->head == NULL) {
        list->head = temp;
    }
    else {
        list->tail->next = temp;
    }
    list->tail = temp;
    list->numberOfElements = list->numberOfElements + 1;
}

int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

void deleteElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error\n");        exit(0);
    }
    int curPos = 0;
    Node* tempPtr = list->head;
    Node* prevPtr = NULL;
    while (curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }
    if (tempPtr == list->head && tempPtr == list->tail) {// only 1 item in list
        list->head = NULL;
        list->tail = NULL;
    } else if (tempPtr == list->head) { //removing head
        list->head = tempPtr->next;
    } else if (tempPtr == list->tail) { //removing tail
        list->tail = prevPtr;
        list->tail->next = NULL;
    } else {  // internal node
        prevPtr->next = tempPtr->next;
    }
    list->numberOfElements--;
        free(tempPtr);
}
