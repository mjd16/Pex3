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




/** isMixedMath() determines if the beginning of a string is a mixed number
 @param str is the string to be tester
 @return whether or not it is a mixed num*/
bool isMixedMath(char* str){
    int counter = 0;
    int i = 0;
    while (counter < 3){
        if (isCharOp(str[i]))
            return false;
        else if (str[i] == ' '){
            counter++;
        }
        else if (str[i] == '\0')
            return false;
        i++;
    }
    return true;
}

/** getMixedMath() is a function to get the mixed number out of the string, convert it to an improper fraction and adequately return it
 @param str is the string that it is getting the mixed num from
 @return the converted mixed number*/
char* getMixedMath(char* str){
    int counter = 0;
    
    bool neg = false;
    if (str[0] == '-'){
        neg = true;
        str++;
    }
    
    char whole[10] = "";
    char numer[10] = "";
    char denom[10] = "";
    
    while (counter < 1){
        if (str[0] != ' '){
            strncpy(whole, str,1);
            str++;
        }
        else
            counter++;
    }
    str = str + strlen(whole) + 1;
    

    while (counter < 2){
        if (str[0] != ' '){
            strncpy(numer, str,1);
            str++;
        }
        else
            counter++;
    }
    
    while (counter < 3){
        if (str[0] != ' '){
            strncpy(denom, str,1);
            str++;
        }
        else
            counter++;
    }

    char* retun = malloc(sizeof(char)*30);
    if (!neg)
        sprintf(retun, "%s %s / %s", whole, numer, denom);
    else
        sprintf(retun, "-%s %s / %s", whole, numer, denom);
    
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
