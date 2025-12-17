/*---------------------------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : main.c
 * Title        : Arbitrary Precision Calculator main file
 * Description  : This file program implements a command-line calculator that performs arithmetic operations on large numbers 
                 represented as doubly linked lists.
 
 * Sample I/P 1 :  1234567890 + 0987654321
 * Sample O/P 1 :  2222222211
 
 * Sample I/P 2 :  -123 + 1234
 * Sample O/P 2 :  1111
 
 * Sample I/P 3 :  -1234 - 123
 * Sample O/P 3 :  -1357
 
 * Sample I/P 4 :  1234567890123456789012345678901234567890 '*' 0987654321098765432109876543210987654321
 * Sample O/P 4 :  463487473289728371289371289312893981237128973189237891371897231
 
 * Sample I/P 5 :  -15 / 3
 * Sample O/P 5 :  -5
 ----------------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // validate input arguments
    if (!validate(argc, argv)) return 1;

    // initialize variables 
    int sign1 = 1, sign2 = 1;
    char *num1 = argv[1], *num2 = argv[3];
    char op = argv[2][0];

    // Extract signs
    if (*num1 == '+' || *num1 == '-') {
        if (*num1 == '-') sign1 = -1;
        num1++;
    }
    if (*num2 == '+' || *num2 == '-') {
        if (*num2 == '-') sign2 = -1;
        num2++;
    }

    // Prepare lists
    Dlist *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    Dlist *h3 = NULL, *t3 = NULL;
    // store the numbers as doubly linked lists
    store_list(&h1, &t1, num1);
    store_list(&h2, &t2, num2);

    int effective_sign = 1;  // Default sign for result

    switch (op) {
        case '+':
            if (sign1 == sign2) {
                addition(t1, t2, &h3, &t3);
                if (sign1 < 0) effective_sign = -1;  // Adjust sign if negative
            } else {
                // If signs are different, subtract the larger number from the smaller
                int cmp = check_largest(num1, num2);
                if (cmp >= 0) {
                    subtraction(t1, t2, &h3, &t3);
                    if (sign1 < 0) effective_sign = -1;
                } else {
                    subtraction(t2, t1, &h3, &t3);
                    if (sign2 < 0) effective_sign = -1;
                }
            }
            break;

        case '-':
            // if signs are different, add the numbers
            if (sign1 != sign2) {
                addition(t1, t2, &h3, &t3);
                if (sign1 < 0) effective_sign = -1;
            } else {
                int cmp = check_largest(num1, num2);
                if (cmp >= 0) {
                    subtraction(t1, t2, &h3, &t3);
                    if (sign1 < 0) effective_sign = -1;
                } else {
                    subtraction(t2, t1, &h3, &t3);
                    if (sign1 > 0) effective_sign = -1;
                }
            }
            break;

        case '*':
            // For multiplication, result sign is negative if one of the numbers is negative
            multiplication(t1, t2, &h3, &t3);
            if (sign1 * sign2 < 0) effective_sign = -1;
            break;

        case '/': {
            // Handle division by checking size of the numbers
            int cmp = check_largest(num1, num2);
            if (cmp < 0) {
                // If numerator is smaller, the result is 0
                insert_at_last(&h3, &t3, 0);
            } else if (cmp == 0) {
                // If both number is equal, the result is 1
                insert_at_last(&h3, &t3, 1);
            } else {
                division(t1, t2, &h3, &t3);    // Perform division
            }
            //Adjust sign if necessary
            if (sign1 * sign2 < 0 && (h3 && !(h3->next == NULL && h3->data == 0))) {
                effective_sign = -1;
            }
            break;
        }
        default:
            // Handle unsupported operators
            printf("Unsupported operator '%c'\n", op);
            return 1;
    }
    // Remove leading zeros from result
    remove_starting_zeros(&h3, &t3);

    // Print the result with the correct sign
    printf("Result: ");
    if (effective_sign < 0 && !(h3->next == NULL && h3->data == 0))
    {
        printf("-");
    }
    print_list(h3);
    return 0;
}
