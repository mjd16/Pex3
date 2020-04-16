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
    
    char tester[35] = "";
    Stack* opStack = stackInit();
    char output[255] = "";
    char* retu = convertToRPN(tester, output, opStack);

    //thorough testing of output conversion
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
	return 0;
	}
