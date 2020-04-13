/** Stack.h
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/
#ifndef PEX3_Stack_h
#define PEX3_Stack_h
#include <stdbool.h>
#include "listAsLinkedList.h"

typedef LinkedList Stack;

/** stackInit() - initializes the stack */
Stack* stackInit(void);

/** stackPush() - puts an element onto the top of the stack
 * @param stack puts a value on the top of the stack
 * @param element is what is being put on the stack */
void stackPush(Stack* stack, int element);

/** stackPop() pops an element off the stack
 * @param stack is a pointer to the stack
 * @return the top of the stack if it works, -1 when it doesn't */
int stackPop(Stack* stack);

/** display() - outputs the stack to the console
 * @param stack - the stack */
void displayStack(Stack stack);

/** stackIsEmpty() determines if stack is empty
 * @param stack is a pointer to the stack
 * @return true if the stack is empty or false if not */
bool stackIsEmpty(Stack stack);

/** stackPeek() returns the item on the top of the
 * stack but doesn't remove it
 * @param stack is a ptr to the stack
 * @return the item on the top of the stack */
int stackPeek(Stack stack);

/** stackSize() returns size of the stack
 * @param stack is a pointer to the stack
 * @return size of stack */
int stackSize(Stack stack);
#endif
