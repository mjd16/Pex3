#pragma once
/** PEX3_mathematicalFunction.h
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* ===========================================================
*/
#ifndef PEX3_mathemaicalFunctions_h
#define PEX3_mathemaicalFunctions_h

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

/** doAllMath will take an entire postix equation and return the answer
 @param str is the postfix string
 @return the result of the equation*/
char* doAllMath(char* str);

/** getTokenMath() is used to tokenize the rpn output
 @param str is the rpn output
 @return a token of the rpn string*/
char* getTokenMath(char* str);

/**isFrac is a simple function to determine if a string is a fraction
 @param str is the string to be tested
 @return whether or not it is a fraction*/
bool isFrac(char* str);

/** bigMath() - handles mathematical operations based on input
 * @param num1 and num 2 are the int to be operated on
 * @return the int value of the result */
int bigMath(int num1, int num2, char operation);

/** bigMathTwoFrac() handles mathematical operations for two fractions
* @param num1 and num3 are the numerators of the fractions and 2/4 are denominators
* @param op is the character representing the operation to be done
* @return the double value of the result*/
char* bigMathTwoFrac(int num1, int num2, int num3, int num4, char op);

/**bigMathOneFracFracFirst() - handles mathematical operations for a fraction and normal number where the fraction comes first
 * @Param num and denom are the numerator and denominator of the fraction and number is the normal number
 * @Param op is the character representing the operation to be done
 * @Return character pointer to string of the resulting fraction*/
char* bigMathOneFracFracFirst(int num, int denom, int number, char op);

/**bigMathOneFracWholeFirst() - handles mathematical operations for a fraction and normal number where the fraction comes first
 * @Param num and denom are the numerator and denominator of the fraction and number is the normal number
 * @Param op is the character representing the operation to be done
 * @Return character pointer to string of the resulting fraction*/
char* bigMathOneFracWholeFirst(int num, int denom, int number, char op);

/**reduceFrac() reduces an inputted fraction to its simplest form
@param numer and denom are the numerator and denominator of the fraction
@return character pointer to string of the resulting fraction*/
char* reduceFrac(int numer, int denom);

/**gcd()  finds the greatest common denominator of two numbers
@param one and two are the numerator and denominator of a fraction
@return greatest common denominator of a numerator and denominator*/
int gcd(int one, int two);

/** isMixedNum determines if a number inputted is a mixed number or not
@param num is the string to be checked
@return a boolean indicating whether it is a mixed number or not */
bool isMixedNum(char* num);

/** convertMixedToFraction takes a mixed number and returns the equivalent number in fraction form
* @param  mixedNum is the number to convert
* @return  the number in equivalent fraction form*/
char* convertMixedToFraction(char* mixedNum);

/** isRational() checks if a token is a rational number
 @param str is the token to be checked
 @return true if it is a rational, false otherwise*/
bool isRational(char* str);

/** convertRationalToFrac() takes a rational and converts it to a fraction
@param str is the token to be converted
@return the converted string*/
char* convertRationalToFrac(char* str);

/** convertImpropToMixed() converts an improper fraction to a mixed number
 @param numer and denom are the numerator and denominator
 @return the converted mixed number*/
char* convertImpropToMixed(int numer, int denom);

#endif
