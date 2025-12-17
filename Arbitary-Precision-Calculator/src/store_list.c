/*---------------------------------------------------------------------------------------------------------------
 * Name        : Unnathi.N
 * Date        : 26-06-25
 * File        : store_list.c
 * Title       : Arbitrary Precision Calculator - Store lists
 * Description : This file program provides utility functions for storing, printing, and comparing doubly linked 
                 lists used to represent large numbers.
 ---------------------------------------------------------------------------------------------------------------*/


#include "calculate.h"
#include <stdlib.h>
#include <string.h>


// converts a numeric string to a DLL, digit by digit
void store_list(Dlist **head, Dlist **tail, char *str) {
    while (*str) insert_at_last(head, tail, *str++ - '0');
}

void delete_list(Dlist **head, Dlist **tail) { /* standard */ } 
void delete_at_first(Dlist **head, Dlist **tail) { /*standard */ }

// prints the linked list as a number
void print_list(Dlist *head) {
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

// counts and returns the number of nodes in the list
int total_nodes(Dlist *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// compares two linked lists numerically
int compare_lists(Dlist *h1, Dlist *h2) {
    int len1 = total_nodes(h1), len2 = total_nodes(h2);
    // First compare lengths
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    //if lengths are qual, compare digit by digit
    while (h1 && h2) {
        if (h1->data > h2->data) return 1;
        if (h1->data < h2->data) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;
}


