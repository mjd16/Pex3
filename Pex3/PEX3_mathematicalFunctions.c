/** PEX3_mathematicalFunctions.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* Documentation:
*	- C3C Phillips and I discussed methods for handling mixed numbers. I still have yet to figure
*	out how to do it.
*	- I  used stackoverflow to help me through the process of reducing fractions to their simplest forms
* ===========================================================
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "PEX3_mathematicalFunctions.h"

/** doAllMath will take an entire postix equation and return the answer
 @param str is the postfix string
 @return the result of the equation*/
char* doAllMath(char* str);


 /** bigMath() - handles mathematical operations based on input
  * @param num1 and num 2 are the doubles to be operated on
  * @return the double value of the result */
double bigMath(double num1, double num2, char operation) {
	switch (operation) {
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '^':
		return pow(num1, num2);
	default:
		return 1;
	}
	return 1;
}

/** bigMathTwoFrac() handles mathematical operations for two fractions
 * @param num1 and num3 are the numerators of the fractions and 2/4 are denominators
 * @param op is the character representing the operation to be done
 * @return the double value of the result*/
char* bigMathTwoFrac(int num1, int num2, int num3, int num4, char op) { //nums 1 and 3 are numerators and 2 and 4 are denoms
	char* ret;
	int place1 = 0; //numerator of first fraction when operating
	int place2 = 0; //numerator of second fraction when operating
	int numerator = 0; //numerator of resulting fraction
	int denominator = 0; //denominator of resulting fraction
    double base = (double)num1 / num2;
    double power = (double)num3 / num4;
    double ans = pow(base,power);
	switch (op) {
	case '+':
		place1 = num1 * num4;
		place2 = num2 * num3;
		numerator = place1 + place2;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '-':
		place1 = num1 * num4;
		place2 = num2 * num3;
		numerator = place1 - place2;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '*':
		numerator = num1 * num3;
		denominator = num2 * num4;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '/':
		numerator = num1 * num4;
		denominator = num2 * num3;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '^':
        base = (double)num1 / num2;
        power = (double)num3 / num4;
        ans = pow(base, power);
        ret = malloc(sizeof(char)*22);
        sprintf(ret,"%.2lf",ans);
        return ret;

	default:
		ret = "No result";
		return ret;
	}
}

/**bigMathOneFracFracFirst() - handles mathematical operations for a fraction and normal number where the fraction comes first
 * @Param num and denom are the numerator and denominator of the fraction and number is the normal number
 * @Param op is the character representing the operation to be done
 * @Return character pointer to string of the resulting fraction*/
char* bigMathOneFracFracFirst(int num, int denom, int number, char op) {
	char* ret;
	int numerator = 0; //numerator of resulting fraction
	int denominator = 0; //denominator of resulting fraction
	int place1 = 0;
    double base = 0.0;
    double ans = 0.0;
	switch (op) {
	case '+':
        place1 = denom * number;
		numerator = num + place1;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '-':
        place1 = denom * number;
		numerator = num - place1;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '*':
		numerator = num * number;
		denominator = denom;
		ret = reduceFrac(numerator, denominator);
		return ret;
	case '/':
		numerator = num;
		denominator = denom * number;
		ret = reduceFrac(numerator, denominator);
		return ret;
    case '^':
        base = (double)num / denom;
        ans = pow(base, number);
        ret = malloc(sizeof(char)*22);
        sprintf(ret,"%.2lf",ans);
        return ret;

	default:
		ret = "No result";
		return ret;
	}
}

/**bigMathOneFracWholeFirst() - handles mathematical operations for a fraction and normal number where the fraction comes first
 * @Param num and denom are the numerator and denominator of the fraction and number is the normal number
 * @Param op is the character representing the operation to be done
 * @Return character pointer to string of the resulting fraction*/
char* bigMathOneFracWholeFirst(int num, int denom, int number, char op) {
    char* ret;
    int numerator = 0; //numerator of resulting fraction
    int denominator = 0; //denominator of resulting fraction
    int place1 = 0;
    double exp = 0.0;
    double ans = 0.0;
    switch (op) {
    case '+':
        place1 = denom * number;
        numerator = num + place1;
        denominator = denom;
        ret = reduceFrac(numerator, denominator);
        return ret;
    case '-':
        place1 = denom * number;
        numerator = num - place1;
        denominator = denom;
        ret = reduceFrac(numerator, denominator);
        return ret;
    case '*':
        numerator = num * number;
        denominator = denom;
        ret = reduceFrac(numerator, denominator);
        return ret;
    case '/':
        numerator = denom * number;
            denominator = num;
        ret = reduceFrac(numerator, denominator);
        return ret;
    case '^':
        exp = (double)num / denom;
        ans = pow(number, exp);
        ret = malloc(sizeof(char)*22);
        sprintf(ret,"%.2lf",ans);
        return ret;

    default:
        ret = "No result";
        return ret;
    }
}

/**reduceFrac() reduces an inputted fraction to its simplest form
 @param numer and denom are the numerator and denominator of the fraction
 @return character pointer to string of the resulting fraction*/
char* reduceFrac(int numer, int denom) {
	int num1 = 0;
	int num2 = 0;
	int greatDenom = gcd(abs(numer), abs(denom));
	num1 = numer / greatDenom;
	num2 = denom / greatDenom;
	char ret[22] = "nothing";
	if (strcmp(ret, "\0")) {
		sprintf(ret, "%d", num1);
		strcat(ret, " / ");
	}
	char ret2[22] = "nothing";
	if (strcmp(ret2, "\0")) {
		sprintf(ret2, "%d", num2);
	}
	strcat(ret, ret2);
    char* retu = ret;
	return retu;
}

/**gcd()  finds the greatest common denominator of two numbers
 @param one and two are the numerator and denominator of a fraction
 @return greatest common denominator of a numerator and denominator*/
int gcd(int one, int two) {
	int remain = 0;
		while (one != 0) {
		remain = two % one;
		two = one;
		one = remain;
	}
		return two;
}

/** isMixedNum determines if a number inputted is a mixed number or not
 @param num is the string to be checked
 @return a boolean indicating whether it is a mixed number or not */
bool isMixedNum(char* num) {
    
	if (num[0] == '-') {
		num++;
	}
    
    int c = 0;
    while (num[c] != '\0'){
        if (strchr("*+-^", num[c]))
            return false;
        c++;
    }
    
    bool gotWhole = false;
    bool gotNumer = false;
    bool gotDenom = false;
    
    char whole[20] = "";
    char numer[20] = "";
    char denom[20] = "";
    
    int i = 0;
    
    if (!isdigit((int)num[i]))
        return false;
    
    //getting the first number
    while (!gotWhole){
        if (num[i] == '\0' || num[i+1] == '\0')
            return false;
        if (num[i+1] == ' '){
            gotWhole = true;
            strncat(whole, num, 1);
        }
        else if (isdigit(num[i+1])){
            strncat(whole, num, 1);
        }
        else
            return false;
        i++;
    }
    if (num[i] == '/' || num[i+1] == '/')
        return false;
    num += i + 1;
    i = 0;
    //getting the second number
    while (!gotNumer){
        if (num[i] == '\0' || num[i+1] == '\0')
            return false;
        if (num[i + 1] == ' ' || num[i+1] == '/'){
            gotNumer = true;
            strncat(numer, num, 1);
        }
        else if (isdigit(num[i+1])){
            strncat(numer, num, 1);
        }
        else
            return false;
        i++;
    }
    num += i + 1;
    i = 0;
    if (num[i] == '/' || num[i] == ' ')
        num += 1;
    //getting the last number
    while (!gotDenom){
        if (num[i] == '\0')
            return false;
        if (num[i] == ' ')
            num++;
        if (num[i+1] == '\0'){
            gotDenom = true;
            strncat(denom, num, 1);
            return true;
        }
        else if (isdigit(num[i+1])){
            strncat(numer, num, 1);
        }
        else
            return false;
        i++;
    }
    return false;
}


/** convertMixedToFraction takes a mixed number and returns the equivalent number in fraction form
* @param  mixedNum is the number to convert
* @return  the number in equivalent fraction form*/
char* convertMixedToFraction(char* num) {
    bool isNeg = false;
    if (num[0] == '-') {
        isNeg = true;
        num++;
    }

    bool gotWhole = false;
    bool gotNumer = false;
    bool gotDenom = false;
    
    char whole[20] = "";
    char numer[20] = "";
    char denom[20] = "";
    
    int i = 0;
    
    //getting the first number
    while (!gotWhole){
        if (num[i+1] == ' '){
            gotWhole = true;
            strncat(whole, num, 1);
        }
        else if (isdigit(num[i+1])){
            strncat(whole, num, 1);
        }
        i++;
    }
    num += i + 1;
    i = 0;
    //getting the second number
    while (!gotNumer){
        if (num[i + 1] == ' ' || num[i+1] == '/'){
            gotNumer = true;
            strncat(numer, num, 1);
        }
        else if (isdigit(num[i+1])){
            strncat(numer, num, 1);
        }
        num++;
    }
    num += i + 1;
    i = 0;
    if (num[i] == '/' || num[i] == ' ')
        num += 1;
    //getting the last number
    while (!gotDenom){
        if (num[i] == ' ')
            num += 1;
        if (num[i+1] == '\0' || num[i] == '\0'){
            gotDenom = true;
            strncat(denom, num, 1);
        }
        else if (isdigit(num[i+1])){
            strncat(denom, num, 1);
        }
        num++;
    }
    int wholeNum = atoi(whole);
    int numerator = atoi(numer);
    int denominator = atoi(denom);

    int newTop = wholeNum * denominator;
    numerator =  newTop + numerator;
    if(isNeg)
        numerator = numerator * -1;
    char* output = reduceFrac(numerator,denominator);
    return output;
}
