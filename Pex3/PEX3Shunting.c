/** PEX3Shunting.h
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/
#include "PEX3Shunting.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/** convertToRPN converts an input string to rpn output string
* @param str is the input string
* @param output is the output string pointer
* @param opStack is the provided stack to store operators
* @return the output string*/
char* convertToRPN(char* str, char* output, Stack* opStack)
{
    char token[35];
    char popped;
    char temp[255];
    
    if (!isValidString(str))
        return "Invalid expression";
        
    while (str[0] != '\0'){
        //read a token
        strcpy(token, getToken(str));
        if (token[0] != '(')
            str = str + strlen(token) + 1;
        else
            str++;
        
        bool mixed = false;
        
        //if its a mixed num, push it to output and get the next token
        if (isMixedNum(token)){
            strcpy(token, convertMixedToFraction(token));
            mixed = true;
            strcat(output, token);
            strcat(output, " ");
        }

        //if the token is a number, push it to the output
        if (isNum(token) && !mixed){
            strcat(output, token);
            strcat(output, " ");
        }
        //if it is a character, then do this giant mess that I somehow came up
        else if (isCharOp(token[0]) && token[0] != '\0'){
            char op = token[0];
            while(stackPeek(*opStack) != (int)'(' && popOperators(op, stackPeek(*opStack), opStack)){
                popped = convertIntToChar(stackPop(opStack));
                sprintf(temp, "%s%c", output, popped);
                strcpy(output, temp);
                strcat(output, " ");
            }
            stackPush(opStack, (int)op);
        }
        //if it is a left parenthesis
        else if (token[0] == '('){
            stackPush(opStack, token[0]);
        }
        //if it is a right parenthesis, pop the operators to the output queue
        else if (token[0] == ')'){
            while (stackPeek(*opStack) != '(' && !stackIsEmpty(*opStack)){
                popped = convertIntToChar(stackPop(opStack));
                sprintf(temp, "%s%c", output, popped);
                strcpy(output, temp);
                strcat(output, " ");
            }
            if (stackPeek(*opStack) == '\0') {
                strcpy(output, "Error with parentheses");
                return output;
            }
        stackPop(opStack);
        }
    }
    //while there is anything left, pop them all to the output queue
    while (!stackIsEmpty(*opStack)){
        popped = convertIntToChar(stackPop(opStack));
        if (popped != '('){
            sprintf(temp, "%s%c", output, popped);
            strcpy(output, temp);
            strcat(output, " ");
        }
        else
            stackPop(opStack);
    }
    
    return output;
}

/** isNum checks if a given token is numeric
* @param tok is the token string
* @return whether or not it is numeric*/
bool isNum(char* tok){
    //if the first digit isn't a minus and is not a digit, token isn't numeric
    if (tok[0] != '-' && !isdigit(tok[0]))
        return false;
    
    //if it is a minus, move to the next character and if it is a digit, it is numeric, if not, return false
    if (tok[0] == '-'){
        tok += 1;
        return isdigit(tok[0]);
    }
    return isdigit((int)tok[0]);
}

/** isCharOp checks if a given character is an operator
* @param op is the character to be checked
* @return whether or not it is an operator*/
bool isCharOp(char op){
    if (strchr("+-*/^", op) != NULL)
        return true;
    return false;
}

/** precedence() gets a numerical value representing the operator's precedence, higher is more important
* @param op is the character to be checked
* @return the predence */
int precedence(char op){
    int ascii = (int)op;
    int aval[100];
    //checking all ascii values of the entered characters and assigning them levels of precedence.
    //higher value = higher precedence
    //mult
    aval[42] = 2;
    //divide
    aval[47] = 2;
    //add
    aval[43] = 1;
    //sub
    aval[45] = 1;
    //power
    aval[94] = 3;
    
    return aval[ascii];
}

/** convertIntToChar() converts an integer that was stored in the linked list and converts it back to a character operator.
* @param charac is the character to be converted
* @return the operator */
char convertIntToChar(int charac)
{
    return charac;
}

/** isValidString() runs through a few scenarios where an input string can immediately be deemed invalid
 * @param str is the input string
 * @return whether or not it failed any of those tests- false if it failed*/
bool isValidString(char* str){
    int leftPCounter = 0;
    int rightPCounter = 0;
    
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '(')
            leftPCounter++;
        if (str[i] == ')')
            rightPCounter++;
        if (str[i] == '-'){
            if (str[i+1] != ' ' || !isdigit(str[i+1]))
                return false;
        }
        if (isCharOp(str[i]) && str[i] != '-'){
            if (isCharOp(str[i+1]))
                return false;
            if (str[i+1] != '\0')
                if (isCharOp(str[i+2]) && str[i+2] != '-')
                    return false;
        }
        i++;
    }
    if (leftPCounter != rightPCounter)
        return false;
    //if it makes it through all of that it's prolly true
    return true;
}

/** getToken() parses the string and gets the first whole token
* @param str is the input string
* @return the first token from the inputted string*/
char* getToken(char* str){
    int loc = 0;
    char* ret = calloc(sizeof(char)*255, 1);
    if (isMixedNum(str)) {
        int spaces = 0;
        while (spaces < 3) {
            if (str[loc] == ' ')
                spaces++;
            loc++;
        }
        strcpy(ret, str);
        ret[loc-1] = '\0';
        return ret;
    }
    
    while(str[loc] != ' ' && isascii(str[loc]) && str[loc] != '\0') {
        if (str[loc] != '(' && str[loc+1] != ')'){
            ret[loc] = str[loc];
            loc++;
        }
        else if (str[loc+1] == ')'){
            ret[loc] = str[loc];
            ret[loc+1] = '\0';
            return ret;
        }
        else if (str[loc] == '('){
            strcpy(ret, "(");
            loc++;
            break;
        }
            
        else if (str[loc] == ')'){
            strcpy(ret, ")");
            loc++;
            break;
        }
            
    }
    ret[loc] = '\0';
    return ret;
}

/** popOperators() takes operators and the current stack and determines if the operators on the stack should be popped
 * @param op1 is the first operator
 * @param op2 is the second operator
 * @param opStack is the current stack
* @return whether or not to pop the operators off of the stack*/
bool popOperators(char op1, char op2, Stack* opStack){
    if (stackIsEmpty(*opStack))
        return false;
    return precedence(op2) > precedence(op1) || ((precedence(op2) == precedence(op1)) && op1 != '^');
}
