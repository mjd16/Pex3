#pragma once
/** PEX3Shunting.h
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/
#include "PEX3_queue.h"
#include "PEX3_Stack.h"
#include "PEX3_mathematicalFunctions.h"

/** convertToRPN converts an input string to rpn output string
* @param str is the input string
* @param output is the output string pointer
* @param opStack is the provided stack to store operators
* @return the output string*/
char* convertToRPN(char* str, char* output, Stack* opStack);

/** isNum checks if a given token is numeric
* @param tok is the token string
* @return whether or not it is numeric*/
bool isNum(char* tok);

/** isCharOp checks if a given character is an operator
* @param op is the character to be checked
* @return whether or not it is an operator*/
bool isCharOp(char op);

/** precedence() gets a numerical value representing the operator's precedence, higher is more important
* @param op is the character to be checked
* @return the predence */
int precedence(char op);

/** convertIntToChar() converts an integer that was stored in the linked list and converts it back to a character operator.
* @param charac is the character to be converted
* @return the operator */
char convertIntToChar(int charac);

/** isValidString() runs through a few scenarios where an input string can immediately be deemed invalid
* @param str is the input string
* @return whether or not it failed any of those tests- false if it failed*/
bool isValidString(char* str);

/** getToken() parses the string and gets the first whole token
* @param str is the input string
* @return the first token from the inputted string*/
char* getToken(char* str);

/** popOperators() takes operators and the current stack and determines if the operators on the stack should be popped
 * @param op1 is the first operator
 * @param op2 is the second operator
 * @param opStack is the current stack
* @return whether or not to pop the operators off of the stack*/
bool popOperators(char op1, char op2, Stack* opStack);


