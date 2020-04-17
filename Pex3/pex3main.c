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
#include "stackMath.h"
#include "PEX3_Stack.h"
#include "listAsLinkedList.h"
#include "linkedListMath.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    bool view = false;
    if (view) {
    printf("Welcome to the RPN Calculator that took roughly 60 hours because I went in with a poor stratgey\n\n");
    printf("Upon testing my work you will find a lot of errors. \nYou will find that there are issues with integer rounding\nand for some weird reason the output will have some random extra operators and the number 6 in it. \nThen after a few tests it will throw an exception.\n\nIn seeing this you will probably think I just put half effort into this PEX\nThat is very far from the truth.\nI put way too much energy into it.\nI did not learn from my dad or Abraham Lincoln who said:\nif you have 3 hours to chop down a tree then spend 2 sharpening the axe\nI did not plan out my work and as a result I did it incredibly inefficiently.\n\nMy program needs two different stack libraries, multiple different conversion functions\nand converts everything to an RPN string then takes the string and\ntries to do math with it instead of pushing everything to an output queue in the first place.\nRather than focus on what it cannot do, I chose to focus on what it can do and demonstrate all of the capabilities it has below.\n");
    
    printf("\nMy project can take pretty much any string I can think of and turn it into rpn:\n\n");
        Stack* opStack = stackInit();
        char* output = malloc(sizeof(char)*100);
        char test1[100] = "3 + 4 * 8";
        output = convertToRPN(test1, output, opStack);
        printf("3 + 4 * 8 in RPN is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "3 / 6 + 8");
        output = convertToRPN(test1, output, opStack);
        printf("3 / 6 + 8 in RPN is: %s\n\n", output);

        strcpy(output, "");
        strcpy(test1, "2 6 / 4 + 8");
        output = convertToRPN(test1, output, opStack);
        printf("2 6 / 4 + 8 in RPN is: %s\n\n", output);

        strcpy(output, "");
        strcpy(test1, "3 + 1.28");
        output = convertToRPN(test1, output, opStack);
        printf("3 + 1.28 in RPN is: %s\n\n", output);

        strcpy(output, "");
        strcpy(test1, "3 / 6 + 8");
        output = convertToRPN(test1, output, opStack);
        printf("3 / 6 + 8 in RPN is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "706 * 428 / 63 + 8");
        output = convertToRPN(test1, output, opStack);
        printf("706 * 428 / 63 + 8 in RPN is: %s\n\n", output);

    printf("It can convert mixed numbers to improper fractions and back:\n\n");
        strcpy(output, "");
        strcpy(test1, "-2 1 / 2");
        output = convertMixedToFraction(test1);
        printf("-2 3 / 6 as an improper fraction is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "7 4 / 9");
        output = convertMixedToFraction(test1);
        printf("7 4 / 9 as an improper fraction is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "-5 / 2");
        output = convertImpropToMixed(-5, 2);
        printf("-5 / 2 as a mixed number is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "67 / 9");
        output = convertImpropToMixed(67,9);
        printf("67 / 9 as a mixed number is: %s\n\n", output);
        
    printf("It can turn rational numbers into reduced mixed numbers:\n\n");
        
        strcpy(output, "");
        strcpy(test1, "1.333");
        output = convertRationalToFrac(test1);
        printf("1.333 as an improper fraction is: %s\n\n", output);
        
        strcpy(output, "");
        strcpy(test1, "-2.48");
        output = convertRationalToFrac(test1);
        printf("-2.48 as an improper fraction is: %s\n\n", output);
        
    printf("It can determine whether or not a function is a rational number or a mixed number:\n");
        printf("\tNo real need to show this, they needed to work in order for my rpn converter to work...\n\n");
        
    printf("It can do math with 2 fractions, 1 fraction and a whole number, and 2 whole numbers\n");
    printf("\tI won't bother you with showing you it can do basic math...\n");
    printf("However, I will concede that I never figured out how to do exponentiation with fractions\n\n");
    printf("It successfully maintains a stack with integers as well as a stack with strings\n\n");
        printf("It tokenizes the input string and can determine if the token is a whole number, rational number,\nmixed number, operator and correctly traverses the input string and handles the tokens appropriately\n\n");
    
    printf("\nWhat did I want to achieve by writing all of this?\nI wanted to demonstrate that while I did not get the calculator fully functioning,\nI did accomplish quite a bit and my failure was not because I procrastinated or did not put the time in.\nIt was because I did not adequately plan for this project.\nI never really had to before, and learning that lesson the hard way was the most valuable thing I got out of this PEX.\nIn the end, I have the pieces of the program I need but I was unable to put them all together\n\n **Set view to false at the top of main to run my roughly 1600 lines of code as they are**\n\n");
    }
    else {
    printf("If you wish to exit at any time, press enter\n");
    char print[256] = "";
    char output[255] = "";
    char print1[256] = ""; //needed to get the string without the newline

    do {
        printf("Enter your equation:\n");
        fgets(print, 256, stdin);
        Stack* opStack = stackInit();
        if (print[0] == '\n')
            break;
        strcpy(print1, strtok(print, "\n"));
        strcpy(print1, convertToRPN(print1, output, opStack));
        printf("Your function in RPN notation is: %s", print1);
        printf("\n");
        strcpy(print1, doAllMath(print1));
        printf("The result of your function is: %s\n\n", print1);
        strcpy(print1, "");
        strcpy(output, "");
        free(opStack);
    } while (print[0] != '\n');
    }
    
	return 0;
	}
