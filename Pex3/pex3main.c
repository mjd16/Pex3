/** main.c
* ===========================================================
* Name: Max Di Lalla
* Section: T2
* Project: PEX 3 RPN Calculator
* Documentation: C3C Phillips helped explain tokenization and how to deal with getting full tokens from strings
        *Stack overflow provided a lot of information on error messages like implicit declarations and access violations
        *I watched a youtube video on taking RPN output and doing math with it from Back To Back SWE's channel
* ===========================================================
*/
#include "PEX3_mathematicalFunctions.h"
#include "PEX3Shunting.h"
#include "stackMath.h"
#include "PEX3_Stack.h"
#include "listAsLinkedList.h"
#include "linkedListMath.h"
#include "tokenizeRPN.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    bool view = true;
    if (view){
        printf("Welcome the RPN calculator that took me roughly 60 hours and 1800 lines of code to complete.\nIt is complicated but very functionally decomposed\n\n");
        
        printf("Please separate numbers and operators with spaces and enter decimals as: 0.33 or 1.28\n");
        printf("Please enter the unary minus directly next to the number you wish to make negative\n");
        printf("\nAfter extensive testing I have found a couple problems I can't explain or correct\n1. After a few expressions are evaluated, the next one will have an operator from the last equation in the rpn\nwhich causes the current one to incorrectly evaluate\n2. It is impossible for me to have fractions to the power of another fraction or whole numbers and vis versa.\nThe way my rpn comes out, it makes doing exponents look identical to other operations and there is no way to tell them apart.\n3. It also has some weird issues with things that have multiple sets of parenthesis\n\nIT WORKS WAY BETTER WITH SHORTER FUNCTIONS BECAUSE OF HOW I DID POINTERS WITH THE STACK\n\n");
        printf("Overall, it does essentially what is asked. It reduces fractions, tests for improper inputs, displays rpn and results of the input.\nIt takes mixed numbers, rational numbers, improper fractions and whole numbers as well as negatives of each of those.\nChange view to false in main to only get rid of the project description\n\n");
        printf("**Make sure to actually type everything out and not use autocomplete features**\n\n");
    }
    printf("If you wish to exit at any time, press enter\nExample input: (10 + -3) * 1.28 gives 889 / 99\n");
    char print[256] = "";
    char output[255] = "";
    char print1[256] = ""; //needed to get the string without the newline
        
        do {
            Stack* opStack = stackInit();
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
    
        //free(print1);
        //free(print);
        
    
    
	return 0;
}
