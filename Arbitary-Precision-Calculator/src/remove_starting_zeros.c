/*-------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : remove_starting_zeros.c
 * Title        : Arbitrary Precision Calculator - Remove Zeros
 * Description  : This file program implements a function to remove leading zeros from a doubly linked 
                  list representing a number.
 ------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>

// Removes leading zeros from the list
void remove_starting_zeros(Dlist **head, Dlist **tail) {
    // continue removing nodes from the front as long as the digit is 0
    while (*head && (*head)->data == 0 && (*head)->next != NULL) {
        Dlist *temp = *head;         // Store the current node to be deleted
        *head = (*head)->next;       // Move head to the next node
        (*head)->prev = NULL;       // Update new head's previous point
        free(temp);                 // free memory
    }
    // If the list becomes empty, also reset the tail
    if (*head == NULL) {
        *tail = NULL;
    }
}

