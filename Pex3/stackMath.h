//
//  queueMath.h
//  Pex3
//
//  Created by Max DiLalla  on 4/16/20.
//  Copyright © 2020 Max DiLalla . All rights reserved.
//

#ifndef queueMath_h
#define queueMath_h

#include <stdio.h>
#include <stdbool.h>
#include "linkedListMath.h"

typedef LinkedListMath StackMath;

/** stackInit() - initializes the stack */
StackMath* stackMathInit(void);

/** stackPush() - puts an element onto the top of the stack
 * @param stack puts a value on the top of the stack
 * @param number is what is being put on the stack*/
void stackMathPush(StackMath* stack, char* number);

/** stackPop() pops an element off the stack
 * @param stack is a pointer to the stack
 * @return the top of the stack if it works, NULL when it doesn't */
char* stackMathPop(StackMath* stack);

/** stackIsEmpty() determines if stack is empty
 * @param stack is a pointer to the stack
 * @return true if the stack is empty or false if not */
bool stackMathIsEmpty(StackMath stack);

/** stackPeek() returns the item on the top of the
 * stack but doesn't remove it
 * @param stack is a ptr to the stack
 * @return the item on the top of the stack */
char* stackMathPeek(StackMath stack);

#endif /* queueMath_h */
