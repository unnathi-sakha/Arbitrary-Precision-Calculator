/*------------------------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : subtraction.c
 * Title        : Arbitrary Precision Calculator - Subtraction
 * Description  : This file program implements subtraction of two numbers represented as doubly linked lists, storing the 
                  result in a new list.
   -----------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>

// performs subtraction
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3) {
    int borrow = 0, diff;

    // Loop continues till all digits from both lists are processed
    while (tail1 != NULL || tail2 != NULL) {
        // Get current digits or 0 if list is exhausted
        int d1 = (tail1) ? tail1->data : 0;
        int d2 = (tail2) ? tail2->data : 0;

        // Subtract digits and borrow
        diff = d1 - d2 - borrow;

        // If result is negative, borrow from the next higher digit
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else
            borrow = 0;

        // insert the resulting digit at the begininng of the result list
        insert_at_first(head3, tail3, diff);

        // Move to previous digits
        if (tail1) tail1 = tail1->prev;
        if (tail2) tail2 = tail2->prev;
    }

    remove_starting_zeros(head3, tail3); // remove any leading zeros

    return 0;
}

