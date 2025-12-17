/*------------------------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : addition.c
 * Title        : Arbitrary Precision Calculator - Addition
 * Description  : This file program implements digit-wise addition of two numbers represented as doubly linked lists,
                  storing the result in a new list.

 -----------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>

// Performs addition of two numbers represented by doubly Linked lists
int addition(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3) {
    int carry = 0, sum;

    // Loop continues 
    while (tail1 != NULL || tail2 != NULL || carry) {
        // Get current digits or 0 if list is exhausted
        int d1 = (tail1) ? tail1->data : 0;
        int d2 = (tail2) ? tail2->data : 0;
        
        // Add digits along with carry
        sum = d1 + d2 + carry;
        //calculate new carry and digit to store
        carry = sum / 10;
        sum %= 10;
       
        // insert result at the beginning
        insert_at_first(head3, tail3, sum);

        // Move to previous digit in both lists
        if (tail1) tail1 = tail1->prev;
        if (tail2) tail2 = tail2->prev;
    }

    return 0;
}

