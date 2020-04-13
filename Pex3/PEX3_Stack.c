/** Stack.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator Stack
* Documentation: I called all the functions that are provided in linked list library provided on canvas.
* I also referenced the stack file provided when writing my file to ensure it is right.
* ===========================================================
*/
#include "PEX3_Stack.h"

/** stackInit() - initializes the stack */
Stack* stackInit() {
    return createLinkedList();
}

/** stackPush() puts an element onto the top of the stack
 * @param stack is a value on the top of the stack
 * @param val is what is being put on the stack */
void stackPush(Stack* stack, int val) {
    appendElementLinkedList(stack,val);
}


/** stackPop() pops an element off the stack
 * @param stack is a pointer to the stack
 * @return the top of the stack if it works, -1 when it doesn't */
int stackPop(Stack* stack) {
    int elemPos = lengthOfLinkedList(stack)-1;
    int elem = getElementLinkedList(stack,elemPos);
    deleteElementLinkedList(stack,elemPos);
    return elem;
}

/** display() - outputs the stack to the console
 * @param stack - the stack */
void displayStack(Stack stack) {
    printLinkedList(&stack);
}


/** stackIsEmpty() determines if stack is empty
 * @param stack is a pointer to the stack
 * @return true if the stack is empty or false if not */
bool stackIsEmpty(Stack stack) {
    if (lengthOfLinkedList(&stack) == 0) {
        return true;
    }
    return false;
}


/** stackPeek() returns the item on the top of the
 * stack but doesn't remove it
 * @param stack is a ptr to the stack 
 * @return the item on the top of the stack */
int stackPeek(Stack stack) {
    if (!stackIsEmpty(stack)){
        return getElementLinkedList(&stack,lengthOfLinkedList(&stack)-1);
    }
    return -1;
}

/** stackSize() returns size of the stack
 * @param stack is a pointer to the stack 
 * @return size of stack */
int stackSize(Stack stack) {
    return lengthOfLinkedList(&stack);
}

