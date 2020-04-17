//
//  tokenizeRPN.h
//  Pex3
//
//  Created by Max DiLalla  on 4/17/20.
//  Copyright © 2020 Max DiLalla . All rights reserved.
//

#ifndef tokenizeRPN_h
#define tokenizeRPN_h

#include <stdio.h>
#include <stdbool.h>

/** getTokenMath() is used to tokenize the rpn output
 @param str is the rpn output
 @return a token of the rpn string*/
char* getTokenMath(char* str);

/** isMixedMath() determines if the beginning of a string is a mixed number
 @param str is the string to be tester
 @return whether or not it is a mixed num*/
bool isMixedMath(char* str);

/** getMixedMath() is a function to get the mixed number out of the string, convert it to an improper fraction and adequately return it
 @param str is the string that it is getting the mixed num from
 @return the converted mixed number*/
char* getMixedMath(char* str);
#endif /* tokenizeRPN_h */
