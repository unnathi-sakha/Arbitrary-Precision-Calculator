/*------------------------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : multiplication.c
 * Title        : Arbitrary Precision Calculator - multiplication
 * Description  : This file program implements multiplication of two numbers represented as doubly linked lists, storing 
                  the product in a new list.                
 -----------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>
#include <stdio.h>  // For printf in case of error

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3) {
    int len1 = total_nodes(get_head_from_tail(tail1));  // Use head, not tail, for length
    int len2 = total_nodes(get_head_from_tail(tail2));
    int *result;
    int i, j;
    Dlist *p1, *p2;

    result = (int *)calloc(len1 + len2, sizeof(int));
    if (!result) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Loop from least significant digit (tail) backward through lists
    for (i = 0, p1 = tail1; p1 != NULL; p1 = p1->prev, i++) {
        int carry = 0;
        int n1 = p1->data;

        for (j = 0, p2 = tail2; p2 != NULL; p2 = p2->prev, j++) {
            int n2 = p2->data;
            int sum = n1 * n2 + result[i + j] + carry;
            carry = sum / 10;
            result[i + j] = sum % 10;
        }
        if (carry > 0)
            result[i + j] += carry;
    }

    // Skip leading zeros (most significant side)
    int k = len1 + len2 - 1;
    while (k > 0 && result[k] == 0)
        k--;

    // Insert digits from most significant to least significant
    for (; k >= 0; k--) {
        insert_at_last(head3, tail3, result[k]);
    }

    free(result);
    return 0;
}

