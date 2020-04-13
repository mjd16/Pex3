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
    char* tester = "4 + 3 * 8";
    Stack* opStack = stackInit();
    char output[255];
    char* retu = convertToRPN(tester, output, opStack);
    printf("%s\n%s\n\n", tester, retu);
    
	int num1 = 7;
	int den1 = 4;
	int num2 = 10;
	int den2 = 3;

	//Testing of math function with two fractions
	char ret[22];
	strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '+'));
	printf("%s\n", ret);
	strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '-'));
	printf("%s\n", ret);
	strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '*'));
	printf("%s\n", ret);
	strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '/'));
	printf("%s\n", ret);
    strcpy(ret, bigMathTwoFrac(num1, den1, num2, den2, '^'));
    printf("%s\n\n", ret);

	//Testing of math function with one fraction and one whole number
	int randnum = 6;
	strcpy(ret, bigMathOneFrac(num1, den1, randnum, '+'));
	printf("%s\n", ret);
	strcpy(ret, bigMathOneFrac(num1, den1, randnum, '-'));
	printf("%s\n", ret);
	strcpy(ret, bigMathOneFrac(num1, den1, randnum, '*'));
	printf("%s\n", ret);
	strcpy(ret, bigMathOneFrac(num1, den1, randnum, '/'));
	printf("%s\n", ret);
    strcpy(ret, bigMathOneFrac(num1, den1, randnum, '^'));
    printf("%s\n\n", ret);

	//Testing of math function with two whole numbers
	printf("%lf \n", bigMath(10.0, 5.0, '+'));
	printf("%lf \n", bigMath(10.0, 5.0, '-'));
	printf("%lf \n", bigMath(10.0, 5.0, '*'));
	printf("%lf \n", bigMath(10.0, 5.0, '/'));
    printf("%.2lf \n\n", bigMath(10.0,5.0, '^'));

	//Testing the is mixed number function
	char te1[22] = "2 3 / 4";
	if (isMixedNum(te1))
		printf("%s is a mixed number \n", te1);
	else
		printf("%s is not a mixed number \n", te1);

	char te2[22] = "-2 3 / 4";
	if (isMixedNum(te2))
		printf("%s is a mixed number \n", te2);
	else
		printf("%s is not a mixed number \n", te2);

	char te3[22] = "3 / 4";
	if (isMixedNum(te3))
		printf("%s is a mixed number \n", te3);
	else
		printf("%s is not a mixed number \n", te3);

	char te4[22] = "3";
	if (isMixedNum(te4))
		printf("%s is a mixed number \n", te4);
	else
		printf("%s is not a mixed number \n\n", te4);

	//Testing the mixed number to improper fraction function
	//char* te5 = "2 3 / 4";
	//char* te6 = "-4 2 / 3";
	//char* mixedNum = malloc(sizeof(char)*22);
	//mixedNum = convertMixedToFraction(te5);
	//char* mixedNum1 = malloc(sizeof(char) * 22);
	//mixedNum1 = convertMixedToFraction(te6);
	//printf("%s as an improper fraction is %s\n", te5, mixedNum);
	//printf("%s as an improper fraction is %s\n", te6, mixedNum1);

	return 0;
	}
