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
    //printf("Welcome to the RPN Calculator that took my almost 60 hours because I went in with a poor stratgey\n");
    //printf("If you wish to exit at any time, press enter\n");
    //char* print = malloc(sizeof(char)*256);
    Stack* opStack = stackInit();
    char output[255] = "";
    
//    do {
//        printf("Enter your equation:\n");
//        fgets(print, 256, stdin);
//        if (print[0] == '\n')
//            break;
//        printf("Your function in RPN notation is: %s", convertToRPN(print, output, opStack));
//    } while (print[0] != '\n');
    
    
    
    char tester[35] = "3 + 4";
    char* retu = convertToRPN(tester, output, opStack);
    printf("String: %s\nGives: %s\nShould be: %s\n\n", tester, retu, "3 4 +");
    printf("Result is: %s \nShould be: 7", doAllMath(retu));
//
//    //thorough testing of output conversion
//    strcpy(tester, "3 + 4 * 8");
//    strcpy(output, "");
//    retu = convertToRPN(tester,output,opStack);
//    printf("String: %s\nGives: %s\nShould be: %s\n\n", tester, retu, "3 4 8 * +");
//
//    strcpy(tester, "4 ^ 2 1 / 3");
//    strcpy(output, "");
//    retu = convertToRPN(tester,output,opStack);
//    printf("String: %s\nGives: %s\nShould be: %s\n\n", tester, retu, "4 2 1 / 3 ^");
//
//    strcpy(tester, "7 * 3 + ( 8 / 6 )");
//    strcpy(output, "");
//    retu = convertToRPN(tester,output,opStack);
//    printf("String: %s\nGives: %s\nShould be: %s\n\n", tester, retu, "7 3 * 8 6 / +");
    free(opStack);
    //free(print);
	return 0;
	}
