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
typedef struct nodeMath {
    char* data;
    struct nodeMath* next;
} NodeMath;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct LinkedListMath{
    NodeMath* head;
    NodeMath* tail;
    int numberOfElements;
} LinkedListMath;

// Functions that manipulate a linked list
LinkedListMath* createLinkedListMath(void);
NodeMath* initializeNodeMath(char* newData);
void deleteLinkedListMath(LinkedListMath* list);
void appendElementLinkedListMath(LinkedListMath* list, char* number);
char* getElementLinkedListMath(LinkedListMath* list, int position);
int lengthOfLinkedListMath(LinkedListMath* list);
void deleteElementLinkedListMath(LinkedListMath* list, int position);

#endif /* linkedListMath_h */
