/*----------------------------------------------------------------------------------------------------------------------
 * Name        : Unnathi.N
 * Date        : 26-06-25
 * File        : insert.c
 * Title       : Arbitrary Precision Calculator - Insert
 * Description : This file contains the program for inserting the data in the double linked list at first position and
                 last position.
 --------------------------------------------------------------------------------------------------------------------------*/

#include "calculate.h"
#include <stdlib.h>

// Insert Data before the first node
void insert_at_first(Dlist **head, Dlist **tail, int num) {
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = num;      // assign data to new node
    new_node->prev = NULL;     // previous of first node should be NULL
    new_node->next = *head;    // new node points to current head

    if (*head)
        (*head)->prev = new_node;  // if list empty
    else
        *tail = new_node;   // if list empty, new node is also the tail

    *head = new_node;      // update head to new node
}

// Insert data after the last node
void insert_at_last(Dlist **head, Dlist **tail, int num) {
    Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = num;        // assign data
    new_node->next = NULL;      // next of last node should be NULL
    new_node->prev = *tail;     // new node's previous is current tail

    if (*tail)
        (*tail)->next = new_node; // if list not empty
    else
        *head = new_node;   // if list empty, new node is also the head

    *tail = new_node;     // update tail to new node
}

