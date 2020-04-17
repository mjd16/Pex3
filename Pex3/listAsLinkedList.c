/** listAsLinkedList.c
* ================================================================
* Name: Maxwell Di Lalla
* Section: T2
* Project: Linked List Library .c
* Documentation: This is just the library off of canvas, work is not my own.
* =================================================================
*/
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

Node* initializeNode(newData) {
	Node* newNode;
	newNode = malloc(sizeof(Node));
	newNode->data = newData;
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

void appendElementLinkedList(LinkedList* list, int element) {
	Node* temp = malloc(sizeof(Node));
	temp = initializeNode(element);
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

int getElementLinkedList(LinkedList* list, int position) {
	if (list->head == NULL)
		printf("List empty");
	else if (list->numberOfElements == 0 || list->numberOfElements < position) {
		return -1;
	}

	Node* point = list->head;
	int counter = 0;

	while (point != NULL && counter < position) {
		counter++;
		point = point->next;
	}
	int ret = point->data;
	return ret;
}

void deleteElementLinkedList(LinkedList* list, int position) {
	if (list->numberOfElements == 0 || list->numberOfElements <= position) { 
		printf("Error in deleteElem\n");        exit(0);
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

void insertElementLinkedList(LinkedList* list, int position, int element) {
	if (list->numberOfElements == 0 || list->numberOfElements <= position) {
		printf("Error in insertElem\n");
		exit(0);
	}
	int counter = 0;
	Node* point = list->head;

	while (point != NULL && counter < position) {
		counter++;
		point = point->next;
	}
	point->data = element;
}


