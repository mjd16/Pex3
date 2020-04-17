//
//  tokenizeRPN.c
//  Pex3
//
//  Created by Max DiLalla  on 4/17/20.
//  Copyright © 2020 Max DiLalla . All rights reserved.
//

#include "tokenizeRPN.h"
#include "PEX3Shunting.h"
#include "PEX3_mathematicalFunctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/** isMixedMath() determines if the beginning of a string is a mixed number
 @param str is the string to be tester
 @return whether or not it is a mixed num*/
bool isMixedMath(char* str){
    if (str[0] == ' ')
        str++;
    if (!isdigit(str[0]))
        return false;
    
    char first[15] = "";
    char second[15] = "";
    //gets the numerator
    while (str[0] != ' ' && str[0] != '\0'){
        strncpy(first, str,1);
        str++;
    }
    if (str[0] == '\0')
        return false;
    str++;
    //if the character 2 after the last digit is not a division symbol, it's not a mixed num
    //if it is, go 2 past the division symbol
    if (str[0] != '/')
        return false;
    else
        str+=2;
    //if the symbol there is not a number, return false;
    if(!isdigit(str[0]))
        return false;
    //gets the second number
    while (str[0] != ' ' && str[0] != '\0'){
        strncpy(second, str,1);
        str++;
    }
    //if the numerator is not greater than the denominator then it isnt a mixed number
    if (atoi(second) > atoi(first))
        return false;
    
    return true;
}

/** getMixedMath() is a function to get the mixed number out of the string, convert it to an improper fraction and adequately return it
 @param str is the string that it is getting the mixed num from
 @return the converted mixed number*/
char* getMixedMath(char* str){    
    bool neg = false;
    if (str[0] == '-'){
        neg = true;
        str++;
    }
    
    char numer[15] = "";
    char denom[15] = "";
    
    while (str[0] != ' '){
        strncat(numer,str,1);
        str++;
    }
    str+=3;
    while (str[0] != '\0' && str[0] != ' ' ){
        strncat(denom,str,1);
        str++;
    }

    char* retun = malloc(sizeof(char)*30);
    if (!neg)
        sprintf(retun, "%s / %s", numer, denom);
    else
        sprintf(retun, "-%s / %s", numer, denom);
    
    return retun;
}

/** getTokenMath() is used to tokenize the rpn output
@param str is the rpn output
@return a token of the rpn string*/
char* getTokenMath(char* str){

    char *output = malloc(sizeof(char)*30);
    
    if (isMixedMath(str)){
        output = getMixedMath(str);
        return output;
    }else if (isCharOp(str[0])){
        strncpy(output, str, 1);
        return output;
    }
    else if(isNum(str)){
        while (str[0] != ' ' && str[0] != '\0'){
            strncat(output, str, 1);
            str++;
        }
    }
    
    return output;
}
