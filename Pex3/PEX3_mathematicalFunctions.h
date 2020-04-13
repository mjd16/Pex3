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

/**
 bigMath() - handles mathematical operations based on input
 - Parameters:
   - num1 and num 2 are the doubles to be operated on
 - returns:
   - the double value of the result */
double bigMath(double num1, double num2, char operation);

/**
bigMathTwoFrac() - handles mathematical operations for two fractions
- Parameters:
  - num1 and num3 are the numerators of the fractions and 2/4 are denominators
  - op is the character representing the operation to be done
- returns:
  - the double value of the result*/
char* bigMathTwoFrac(int num1, int num2, int num3, int num4, char op);

/**
bigMathOneFrac() - handles mathematical operations for a fraction and normal number
- Parameters:
  - num and denom are the numerator and denominator of the fraction and number is the normal number
  - op is the character representing the operation to be done
- returns:
  - character pointer to string of the resulting fraction*/
char* bigMathOneFrac(int num1, int num2, int num3, char op);

/**
reduceFrac() - reduces an inputted fraction to its simplest form
- Parameters:
  - num1 and num2 are the numerator and denominator of the fraction
  - op is the character representing the operation to be done
- returns:
  - character pointer to string of the resulting fraction*/
char* reduceFrac(int numer, int denom);

/**
gcd() - finds the greatest common denominator of two numbers
- Parameters
   - num1 and num2 are the numerator and denominator of a fraction
-Returns:
   - greatest common denominator of a numerator and denominator*/
int gcd(int one, int two);

/** isMixedNum determines if a number inputted is a mixed number or not
Parameters:
    - num is the number to be checked
Returns:
    - is a boolean indicating whether it is a mixed number or not */
bool isMixedNum(char* num);
//
///** convertMixedToFraction takes a mixed number and returns the equivalent number in fraction form
//* @param - mixedNum is the number to convert
//* @return - the number in equivalent fraction form*/
//char* convertMixedToFraction(char* mixedNum);



#endif
