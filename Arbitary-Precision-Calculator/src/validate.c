/*---------------------------------------------------------------------------------------------------------------
 * Name        : Unnathi.N
 * Date        : 26-06-25
 * File        : validate.c
 * Title       : Arbitrary Precision Calculator - validation
 * Description : This file program implements input validation for a command-line arithmetic calculator,
                 checking the format, operator, and numeric inputs.
 ---------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

// Validate the input arguments
int validate(int argc, char *argv[]) {
    if (argc != 4) {  // check if exactly 3 arguments are passed 
        printf("Usage: <number1> <operator> <number2>\n");
        printf("Note: Use quotes for '*' to avoid shell expansion, e.g., './a.out 2 '*' 3'\n");
        return 0;
    }

    // Validate operator
    if (argv[2][1] != '\0' ||
       (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/')) {
        printf("Error: Invalid operator. Use + - * /\n");
        return 0;
    }

    // Validate first number (can start with '+' or '-')
    int i = 0;
    if (argv[1][0] == '+' || argv[1][0] == '-') i++;
    for (; argv[1][i]; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Error: First argument must be numeric.\n");
            return 0;
        }
    }

    // Validate third number (can start with '+' or '-')
    i = 0;
    if (argv[3][0] == '+' || argv[3][0] == '-') i++;
    for (; argv[3][i]; i++) {
        if (!isdigit(argv[3][i])) {
            printf("Error: Third argument must be numeric.\n");
            return 0;
        }
    }

    return 1;
}

