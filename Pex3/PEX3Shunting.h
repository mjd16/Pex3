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


char* convertToRPN(char* str, char* output, Stack* opStack);
bool isNum(char* tok);
bool isCharOp(char op);
int precedence(char op);
bool isValidString(char* str);
char* getToken(char* str);
bool popOperators(char op1, char op2, Stack* opStack);
char convertIntToChar(int charac);

