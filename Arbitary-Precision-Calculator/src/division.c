/*------------------------------------------------------------------------------------------------------------------------
  * Name         : Unnathi.N
  * Date         : 26-06-25
  * File         : division.c
  * Title        : Arbitrary Precision Calculator - Division
  * Description  : This file program implements long division of two numbers represented as doubly linked lists, producing
                   the quotient as a new list.                 
 -----------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>
#include <stdio.h> 

// Performs deletion
int division(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3) {
    Dlist *dividend_head = get_head_from_tail(tail1);
    Dlist *divisor_head = get_head_from_tail(tail2);

    // Initialize quotient list to empty
    *head3 = NULL;
    *tail3 = NULL;

    // Temporary number representing partial dividend
    Dlist *temp_dividend_head = NULL, *temp_dividend_tail = NULL;

    Dlist *current = dividend_head;
    while (current != NULL) {
        // Append current digit to temp_dividend
        insert_at_last(&temp_dividend_head, &temp_dividend_tail, current->data);

        // Remove leading zeros in temp_dividend
        remove_starting_zeros(&temp_dividend_head, &temp_dividend_tail);

        int q_digit = 0;
        // While temp_dividend >= divisor, subtract divisor and increment q_digit
        while (compare_lists(temp_dividend_head, divisor_head) >= 0) {
            Dlist *res_head = NULL, *res_tail = NULL;
            subtraction(temp_dividend_tail, tail2, &res_head, &res_tail);

            delete_list(&temp_dividend_head, &temp_dividend_tail);
            temp_dividend_head = res_head;
            temp_dividend_tail = res_tail;

            q_digit++;
        }

        // Append quotient digit
        insert_at_last(head3, tail3, q_digit);

        current = current->next;
    }

    // Remove leading zeros from quotient
    remove_starting_zeros(head3, tail3);

    // If quotient is empty, means 0
    if (*head3 == NULL) {
        insert_at_last(head3, tail3, 0);
    }

    // Free temporary dividend list
    delete_list(&temp_dividend_head, &temp_dividend_tail);

    return 0;
}

