/** linkedListMath.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/

#include "linkedListMath.h"
#include <stdio.h>
#include "listAsLinkedList.h"
#include <stdlib.h>


LinkedListMath* createLinkedListMath() {
    LinkedListMath* list;
    list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

NodeMath* initializeNodeMath(char* newData) {
    NodeMath* newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    
    return newNode;
}

void deleteLinkedListMath(LinkedListMath* list) {
    if (list->head == NULL)
        return;
    NodeMath* tempPtr = list->head;
    NodeMath* freePtr = NULL;
    while (tempPtr != NULL) {
        freePtr = tempPtr;
        tempPtr = tempPtr->next;
        free(freePtr);
    }
    free(list);
}

void appendElementLinkedListMath(LinkedListMath* list, char* number) {
    NodeMath* temp = malloc(sizeof(Node));
    temp = initializeNodeMath(number);
    if (list->head == NULL) {
        list->head = temp;
    }
    else {
        list->tail->next = temp;
    }
    list->tail = temp;
    list->numberOfElements = list->numberOfElements + 1;
}

int lengthOfLinkedListMath(LinkedListMath* list) {
    return list->numberOfElements;
}

char* getElementLinkedListMath(LinkedListMath* list, int position) {
    if (position < 0){
        printf("Error Here");
        return "ERRR";
    }
    if (list->head == NULL)
        printf("List empty");
    else if (list->numberOfElements == 0 || list->numberOfElements < position) {
        return "\0";
    }

    NodeMath* point = list->head;
    int counter = 0;

    while (point != NULL && counter < position) {
        counter++;
        point = point->next;
    }
    char* ret = point->data;
    return ret;
}

void deleteElementLinkedListMath(LinkedListMath* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error\n");        exit(0);
    }
    int curPos = 0;
    NodeMath* tempPtr = list->head;
    NodeMath* prevPtr = NULL;
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
