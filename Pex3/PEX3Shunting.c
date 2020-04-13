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

char* convertToRPN(char* str, char* output, Stack* opStack)
{
    char token[22];
    char popped;
    char temp[255];
    
    while (str[0] != '\0'){
        //read a token
        strcpy(token, getToken(str));
        str = str + strlen(token) + 1;
        
        /* Need to do the thing with mixed numbers here- convert to improper frac*/
        
        //if the token is a number, push it to the output
        if (isNum(token)){
            strcat(output, token);
            strcat(output, " ");
        }
        //if it is a character, then do this giant mess that I somehow came up
        else if (isCharOp(token[0])){
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
            stackPush(opStack, (int)token[0]);
        }
        //if it is a right parenthesis, pop the operators to the output queue
        else if (token[0] == ')'){
            while (stackPeek(*opStack) != (int)'(' && !stackIsEmpty(*opStack)){
                popped = convertIntToChar(stackPop(opStack));
                sprintf(temp, "%s%c", output, popped);
                strcpy(output, temp);
                strcat(output, " ");
            }
            if (stackPeek(*opStack) == -1){
                strcpy(output, "Error with parenthesis");
                return output;
            }
            //if a left parenthesis is on the top, remove it without doing anything
            if (stackPeek(*opStack) == (int)'(')
                stackPop(opStack);
        }
        
        //while there is anything left, pop them all to the output queue
        while (!stackIsEmpty(*opStack)){
            popped = convertIntToChar(stackPop(opStack));
            if (popped == ')' || popped == '('){
                strcpy(output,"Error with parenthesis");
                return output;
            }
            sprintf(temp, "%s%c", output, popped);
            strcpy(output, temp);
            strcat(output, " ");
        }
        
    }
    while (!stackIsEmpty(*opStack)){
        if (token[0] == ')' || token[0] == ')'){
            printf("Error, mismatched parenthesis\n");
            return output;
        }
        char popped = convertIntToChar(stackPop(opStack));
        char* temp = "nothing";
        sprintf(temp, "%s%c", output, popped);
        strcpy(output, temp);
        strcat(output, " ");
    }
    return output;
}


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

bool isCharOp(char op){
    return strchr("+-x/^", op);
}

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

char convertIntToChar(int charac){
    return charac + '0';
}

bool isValidString(char* str);

char* getToken(char* str){
    int loc = 0;
    char* ret = calloc(1, 22 * sizeof(char));
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
        ret[loc] = str[loc];
        loc++;
    }
    ret[loc] = '\0';
    return ret;
}


//working on the loop dealing with characters being the token
bool popOperators(char op1, char op2, Stack* opStack){
    return precedence(op2) > precedence(op1) || ((precedence(op2) == precedence(op1)) && op1 == '^');
}
