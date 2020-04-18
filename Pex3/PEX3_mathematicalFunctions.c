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
#include <stdlib.h>
#include <ctype.h>
#include "PEX3_mathematicalFunctions.h"
#include "tokenizeRPN.h"
#include "stackMath.h"
#include "PEX3Shunting.h"

/** doAllMath will take an entire postix equation and return the answer
 @param str is the postfix string
 @return the result of the equation*/
char* doAllMath(char* str){
    char token[22][22];
    char arg1[22] = "";
    char arg2[22] = "";
    
    //initialize the stack and the output string
    StackMath* stack = stackMathInit();
    char result[256] = "";

    int i = 0;
    
    while(str[0] != '\0'){
        //get the token from the rpn output
        strcpy(result, "");
        strcpy(token[i], getTokenMath(str));
        bool isMixed = false;
        str = str + strlen(token[i]) + 1;
        //if it is a mixed number (which in my rpn is an improper fraction) store it in the stack
        if (isMixedMath(token[i])){
            isMixed = true;
            stackMathPush(stack, token[i]);
        } //if it is just a number, push it to the stack
        else if(isNum(token[i]) && !isMixed){
            stackMathPush(stack, token[i]);
        } //if it is an operator, pop the top two arguments off the stack, determine what kind of number they are and do math with them appropriately
        else if (isCharOp(token[i][0]) && !isMixed){
            strcpy(arg2, stackMathPop(stack));
            strcpy(arg1, stackMathPop(stack));
                        
            //if the first argument is a fraction
            if (isFrac(arg1)){
                char numer1[22] = "";
                char denom1[22] = "";
                //get first numbers numerator and denominator
                int j = 0;
                while (arg1[j] != ' '){
                    numer1[j] = arg1[j];
                    j++;
                }
                //getting to the next number in the string
                int c = (int)strlen(numer1) + 3;
                
                int q = 0;
                while(arg1[c] != '\0'){
                    denom1[q] = arg1[c];
                    c++;
                    q++;
                }
                //and the second number is also a fraction... get the second numerator and denominator
                if (isFrac(arg2)){
                    char numer2[22];
                    char denom2[22];

                    int j = 0;
                    while (arg2[j] != ' '){
                        numer2[j] = arg2[j];
                        j++;
                    }
                    //getting to the next number in the string
                    int c = (int)strlen(numer2)+3;
                    
                    int q = 0;
                    while(arg2[c] != '\0'){
                        denom2[q] = arg2[c];
                        c++;
                        q++;
                    } //do the math with the two fractions and the operator stored in token
                    stackMathPush(stack, bigMathTwoFrac(atoi(numer1),atoi(denom1),atoi(numer2),atoi(denom2),token[i][0]));
                    
                } //end of second number also fraction (first is a fraction)
                else if (!isFrac(arg2)){
                    int num = atoi(arg2);
                    stackMathPush(stack, bigMathOneFracFracFirst(atoi(numer1),atoi(denom1),num,token[i][0]));

                } // end of second number whole and first fraction
            }// end of first number is a fraction
            
            //if the first argument is a number
            else if (!isFrac(arg1)){
                int number = atoi(arg1);
                
                //if the second number is a fraction
                if (isFrac(arg2)){
                    char numer1[22] = "";
                    char denom1[22] = "";
                    
                    int j = 0;
                    while (arg2[j] != ' '){
                        numer1[j] = arg2[j];
                        j++;
                    }
                    //getting to the next number in the string
                    int c = (int)strlen(numer1) + 3;
                    
                    int q = 0;
                    while(arg2[c] != '\0'){
                        denom1[q] = arg2[c];
                        c++;
                        q++;
                    }
                    stackMathPush(stack, bigMathOneFracWholeFirst(atoi(numer1), atoi(denom1), number, token[i][0]));
                    
                }
                else if (!isFrac(arg2) && !isFrac(arg1)){
                    int number2 = atoi(arg2);
                    char op = token[i][0];
                    stackMathPush(stack, bigMath(number, number2, op));
                }
            } //end of first argument is a number
            
        }//end of if char is opp
        i++;
    }
    //pop last thing off the stack, should be the result
    strcpy(result, stackMathPop(stack));
    free(stack);
    //making a returnable string because I needed a static string to do the work and needed to return a pointer
    char *retun = malloc(sizeof(char)*255);
    strcpy(retun, result);
    return retun;
}

/**isFrac is a simple function to determine if a string is a fraction
 @param str is the string to be tested
 @return whether or not it is a fraction*/
bool isFrac(char* str){
    int i = 0;
    //simply checks if a string has a division sign in it, used in doAllMath to check what kind of number was popped
    while (str[i] != '\0'){
        if (str[i] == '/')
            return true;
        i++;
    }
    return false;
}

 /** bigMath() - handles mathematical operations based on input
  * @param num1 and num 2 are the doubles to be operated on
  * @return the double value of the result */
char* bigMath(int num1, int num2, char operation) {
    char* ret = malloc(sizeof(char)*35);
	switch (operation) {
	case '+':
            sprintf(ret, "%d", num1 + num2);
                return ret;
	case '-':
            sprintf(ret, "%d", num1 - num2);
                return ret;
	case '*':
            sprintf(ret, "%d", num1 * num2);
                return ret;
	case '/':
            ret = reduceFrac(num1,num2);
                return ret;
	case '^':
            sprintf(ret, "%d", (int)pow(num1, num2));
                return ret;
	default:
		return "WRONG AT BIGMATH";
	}
	return ret;
}

/** bigMathTwoFrac() handles mathematical operations for two fractions
 * @param num1 and num3 are the numerators of the fractions and 2/4 are denominators
 * @param op is the character representing the operation to be done
 * @return the double value of the result*/
char* bigMathTwoFrac(int num1, int num2, int num3, int num4, char op) { //nums 1 and 3 are numerators and 2 and 4 are denoms
    char* ret = malloc(sizeof(char) * 30);
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
            //could never really tell if this worked because it rarely got called due to my issue stated in the intro
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
	char* ret = malloc(sizeof(char) * 30);
    int numerator = 0; //numerator of resulting fraction
	int denominator = 0; //denominator of resulting fraction
	int place1 = 0;
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
    case '^': //also do not know if this ever really worked for the same problem stated in the intro
        ans = pow((double)num / (double)denom, number);
        sprintf(ret, "%.3lf", ans);
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
    char* ret = malloc(sizeof(char) * 30);
    int numerator = 0; //numerator of resulting fraction
    int denominator = 0; //denominator of resulting fraction
    int place1 = 0;
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
        ans = pow((double)num / (double)denom, number);
        sprintf(ret, "%.3lf", ans);
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
    //gets the greatest common denominator of the numerator and denominator
	int greatDenom = gcd(abs(numer), abs(denom));
    //divides each by the gcd to get the reduced numerator and denominator
	num1 = numer / greatDenom;
	num2 = denom / greatDenom;
	char ret1[22] = "nothing";
    //all of this string stuff to make a suitable output with a division symbol in it
	if (strcmp(ret1, "\0")) {
		sprintf(ret1, "%d", num1);
		strcat(ret1, " / ");
	}
	char ret2[22] = "nothing";
	if (strcmp(ret2, "\0")) {
		sprintf(ret2, "%d", num2);
	}
    char *retu = malloc(sizeof(char) * 20);
    if (num2 != 1){
        strcat(ret1, ret2);
        retu = ret1;
    }
    else if (num1 % num2 == 0)
        sprintf(retu, "%d", num1 / num2);
    else
        sprintf(retu, "%d", num1);
    
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
    //checks if it is a negative, no need to store if it is or not
	if (num[0] == '-') {
		num++;
	}
    
    //if it finds an operator other than a minus sign before three digits are read, it can't be a mixed number
    int c = 0;
    int spaces = 0;
    while (num[c] != '\0' && spaces < 4){
        if(num[c] == ' ')
            spaces++;
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
        if (num[i+1] == '\0' || num[i+1] == ' '){
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
* @param  num is the number to convert
* @return  the number in equivalent fraction form*/
char* convertMixedToFraction(char* num) {
    //this function is very much the same as isMixedNum but it converts it at the end
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

/** isRational() checks if a token is a rational number
@param str is the token to be checked
@return true if it is a rational, false otherwise*/
bool isRational(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == '.')
            return true;
        i++;
    }
    return false;
}

/** convertRationalToFrac() takes a rational and converts it to a fraction
@param str is the token to be converted
@return the converted string*/
char* convertRationalToFrac(char* str){
    //checks if it is a negative and stores that information
    bool isNeg = false;
    if (str[0] == '-'){
        isNeg = true;
        str++;
    }
    //gets the whole number in front
    int counter = 0;
    char wholeNum[22] = "";
    char dec[22] = "";
    
    int i = 0;
    while (str[i] != '.'){
        wholeNum[i] = str[i];
        i++;
    }
    i++;
    int c = 0;
    while (str[i] != '\0'){
        dec[c] = str[i];
        i++;
        c++;
    }
    //does some math I found on stackOverflow and returns a fraction that is close to the answer
    int whole = atoi(wholeNum);
    counter = (int)strlen(dec);
    int denom = (int)pow(10,counter) - 1;
    int numer = atoi(dec) + whole * denom;
    
    char* retun = convertImpropToMixed(numer,denom);
    if (isNeg)
       retun = convertImpropToMixed(-1 * numer, denom);
    
    return retun;
}

/** convertImpropToMixed() converts an improper fraction to a mixed number
@param numer and denom are the numerator and denominator
@return the converted mixed number*/
char* convertImpropToMixed(int numer, int denom){
    bool neg = false;
    if (numer < 0){
        neg = true;
        numer = numer * -1;
    }
    int counter = 0;
    while (numer > denom){
        numer = numer - denom;
        counter++;
    }
    char *out = malloc(sizeof(char)*30);
    if (!neg)
        sprintf(out, "%d %d / %d", counter, numer, denom);
    else
        sprintf(out, "-%d %d / %d", counter, numer, denom);
    return out;
}
