/*-----------------------------------------------------------------------------------------------------------
 * Name        : Unnathi.N
 * Date        : 26-06-25
 * File        : utils.c
 * Title       : Arbitrary Precision Calculator - Utils
 * Description : This file program implements utility functions for manipulating doubly linked lists, 
                 including copying, swapping, and comparing numeric values.
 ------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <string.h>

// Get tail of list
Dlist* get_tail(Dlist *head) {
    while (head && head->next)
        head = head->next;
    return head;
}

// get head of the list
Dlist* get_head_from_tail(Dlist *tail) {
    while (tail && tail->prev)
        tail = tail->prev;
    return tail;
}


// Copy a list
void copy_list(Dlist *src_head, Dlist *src_tail, Dlist **dest_head, Dlist **dest_tail) {
    int compare_lists(Dlist *h1, Dlist *h2) {
    int len1 = total_nodes(h1), len2 = total_nodes(h2);
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    while (h1 && h2) {
        if (h1->data > h2->data) return 1;
        if (h1->data < h2->data) return -1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return 0;
}

    Dlist *temp = src_head;
    while (temp) {
        insert_at_last(dest_head, dest_tail, temp->data);
        temp = temp->next;
    }
}

// Swap two doubly linked lists
void swap(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2) {
    Dlist *temp_head = *head1;
    Dlist *temp_tail = *tail1;
    *head1 = *head2;
    *tail1 = *tail2;
    *head2 = temp_head;
    *tail2 = temp_tail;
}

// Check which number is larger
int check_largest(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 != len2)
        return (len1 > len2) ? 1 : -1;

    for (int i = 0; i < len1; i++) {
        if (num1[i] != num2[i])
            return (num1[i] > num2[i]) ? 1 : -1;
    }
    return 0; // Equal
}

