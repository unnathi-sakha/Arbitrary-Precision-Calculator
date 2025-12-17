/*------------------------------------------------------------------------------------------------------------------------------
 * Name         : Unnathi.N
 * Date         : 26-06-25
 * File         : calculate.h
 * Title        : Arbitrary Precision Calculator header file
 * Description  : This file defines a header for a program that implements arithmetic operations and utilities on doubly linked lists.
 --------------------------------------------------------------------------------------------------------------------------------*/

#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Dlist {
    int data;
    struct Dlist *prev;
    struct Dlist *next;
} Dlist;

// Validation
int validate(int argc, char *argv[]);

// Linked List Utilities
void store_list(Dlist **head, Dlist **tail, char *str);
void insert_at_first(Dlist **head, Dlist **tail, int num);
void insert_at_last(Dlist **head, Dlist **tail, int num);
void delete_at_first(Dlist **head, Dlist **tail);
void delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head);
void copy_list(Dlist *src_head, Dlist *src_tail, Dlist **dest_head, Dlist **dest_tail);
void add_zeros(Dlist **head, Dlist **tail, int count);

// Arithmetic Operations
int addition(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3);
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3);
int division(Dlist *tail1, Dlist *tail2, Dlist **head3, Dlist **tail3);

// Utility
Dlist* get_tail(Dlist *head);
Dlist* get_head_from_tail(Dlist *tail);
int check_largest(char *num1, char *num2);
void swap(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
void remove_starting_zeros(Dlist **head, Dlist **tail);
int compare_lists(Dlist *head1, Dlist *head2);
int total_nodes(Dlist *head);
#endif

