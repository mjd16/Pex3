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

void printLinkedList(LinkedList* list) {
	
	if (list->head == NULL)
		printf("List empty");

	Node* point = list->head;
	int counter = 0;

	while (point != NULL) {
		counter++;
		printf("The %d element is %d\n", counter, point->data);
		point = point->next;
	}
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

void changeElementLinkedList(LinkedList* list, int position, int newElement) {
	if (list->head == NULL)
		printf("List empty");
	else if (list->numberOfElements == 0 || list->numberOfElements < position) {
		printf("Error\n");
		exit(0);
	}

	Node* point = list->head;
	int counter = 0;

	while (point != NULL && counter < position) {
		counter++;
		point = point->next;
	}
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

void insertElementLinkedList(LinkedList* list, int position, int element) {
	if (list->numberOfElements == 0 || list->numberOfElements <= position) {
		printf("Error\n");
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

int findElementLinkedList(LinkedList* list, int element) {
	if (list->numberOfElements == 0) {
		printf("List empty\n");
		exit(0);
	}
	int counter = 0;
	Node* point = list->head;

	while (point != NULL && point->data != element) {
		counter++;
		point = point->next;
	}
	if (point != NULL)
		return counter;
	return -1;
}

void selSortLinkedList(LinkedList* list) {
	Node* tempPtr = list->head;
	Node* nodeWithSmallest;
	while (tempPtr != NULL) {
		nodeWithSmallest = findSmallest(tempPtr);
		swapData(tempPtr, nodeWithSmallest);
		tempPtr = tempPtr->next;
	}
}

void insertSortLinkedList(LinkedList* list) {
	int insertElem;
	Node* tempPtr = list->head->next;
	Node* tempPrevPtr = list->head;
	Node* insPtr;
	Node* insPrevPtr = list->head;
	while (tempPtr != NULL) {
		insertElem = tempPtr->data; // the item to insert
		insPtr = list->head;
		while (insPtr->data < insertElem && insPtr != tempPtr) {   // find the insertion
			insPrevPtr = insPtr;
			insPtr = insPtr->next;
		}
		if (insPtr != tempPtr) {
			tempPrevPtr->next = tempPtr->next;
			tempPtr->next = insPtr;
			insPrevPtr->next = tempPtr;
			if (insPtr == list->head) {
				list->head = insPtr;
			}
		}
		tempPrevPtr = tempPtr;
		tempPtr = tempPtr->next;
	}
}

Node* findSmallest(Node* firstNode) {
	Node* nodeWithSmallest = firstNode;
	Node* nodePtr = firstNode;
	while (nodePtr != NULL) {
		if (nodePtr->data < nodeWithSmallest->data) {
			nodeWithSmallest = nodePtr;
		}
		nodePtr = nodePtr->next;
	}
	return nodeWithSmallest;
}

void swapData(Node* j, Node* k) {
	int temp = j->data;
	j->data = k->data;
	k->data = temp;
}
