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
    printf("Welcome to the RPN Calculator that took my almost 60 hours because I went in with a poor stratgey\n");
    printf("If you wish to exit at any time, press enter\n");
    char print[256] = "";
    Stack* opStack = stackInit();
    char output[255] = "";
    char print1[256] = ""; //needed to get the string without the newline
    
//    char tester[35] = "";
//    strcpy(tester, "3 + 4");
//    printf("%s", convertToRPN(tester, output, opStack));
    do {
        printf("Enter your equation:\n");
        fgets(print, 256, stdin);
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
    } while (print[0] != '\n');
    
    
    
//    char tester[35] = "3 + 4";
//    char* retu = convertToRPN(tester, output, opStack);
//    printf("String: %s\nGives: %s\nShould be: %s\n\n", tester, retu, "3 4 +");
//    printf("Result is: %s \nShould be: 7", doAllMath(retu));

//    char tester[35] = "1.28";
//    printf("%s\n", convertRationalToFrac(tester));
    
    free(opStack);
	return 0;
	}
