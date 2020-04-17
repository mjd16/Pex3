/** stackMath.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/

#include "stackMath.h"

/** stackInit() - initializes the stack */
StackMath* stackMathInit() {
    return createLinkedListMath();
}

/** stackPush() puts an element onto the top of the stack
 * @param stack is a value on the top of the stack
 * @param number is what is being put on the stack */
void stackMathPush(StackMath* stack, char* number) {
    appendElementLinkedListMath(stack,number);
}


/** stackMathPop() pops an element off the stack
 * @param stack is a pointer to the stack
 * @return the top of the stack if it works, -1 when it doesn't */
char* stackMathPop(StackMath* stack) {
    int elemPos = lengthOfLinkedListMath(stack)-1;
    char* elem = getElementLinkedListMath(stack,elemPos);
    deleteElementLinkedListMath(stack,elemPos);
    return elem;
}


/** stackMathIsEmpty() determines if stack is empty
 * @param stack is a pointer to the stack
 * @return true if the stack is empty or false if not */
bool stackMathIsEmpty(StackMath stack) {
    if (lengthOfLinkedListMath(&stack) == 0) {
        return true;
    }
    return false;
}


/** stackMathPeek() returns the item on the top of the
 * stack but doesn't remove it
 * @param stack is a ptr to the stack
 * @return the item on the top of the stack */
char* stackMathPeek(StackMath stack) {
    if (!stackMathIsEmpty(stack)){
        return getElementLinkedListMath(&stack,lengthOfLinkedListMath(&stack)-1);
    }
    return "\0";
}
