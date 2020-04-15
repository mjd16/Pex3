/** main.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* Documentation: No help received on this file	
* ===========================================================
*/
#include "PEX3_mathematicalFunctions.h"
#include "PEX3Shunting.h"
#include "PEX3_queue.h"
#include "PEX3_Stack.h"
#include "listAsLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char tester[35] = "4 + 3 * 8"; //"3 + 4 × 2 / ( 1 − 5 ) ^ 2 ^ 3"
    Stack* opStack = stackInit();
    char output[255] = "";
    char* retu = convertToRPN(tester, output, opStack);
    printf("String: %s\nGives: %s\nShould be: %s\n", tester, retu, "4 3 8 * +"); //"3 4 2 × 1 5 − 2 3 ^ ^ / +"
    
//	int num1 = 7;
//	int den1 = 4;
//	int num2 = 10;
//	int den2 = 3;

//	//Testing of math function with two fractions
//	char ret[22];
//	strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '+'));
//	printf("%s\n", ret);
//
//	//Testing of math function with one fraction and one whole number
//	int randnum = 6;
//	strcpy(ret, bigMathOneFrac(num1, den1, randnum, '+'));
//	printf("%s\n", ret);


//Testing the is mixed number function
//	char te1[22] = "22 3 / 4";
//	if (isMixedNum(te1))
//		printf("%s is a mixed number \n", te1);
//	else
//		printf("%s is not a mixed number \n", te1);


	// Testing the mixed number to improper fraction function
//	char te5[30] = "22 31 / 4";
//	char te6[30] = "-4 2/32";
//	char mixedNum[30] = "";
//	strcpy(mixedNum, convertMixedToFraction(te5));
//	char mixedNum1[30] = "";
//	strcpy(mixedNum1, convertMixedToFraction(te6));
//	printf("%s as an improper fraction is %s\n", te5, mixedNum);
//	printf("%s as an improper fraction is %s\n", te6, mixedNum1);

	return 0;
	}
