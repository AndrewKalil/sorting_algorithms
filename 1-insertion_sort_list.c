/*
 * ============================================
 *
 *       Filename:  1-insertion_sort_list.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  14/06/2020 16:43:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew Kalil & Samuel Gómez
 *   Organization:  Holberton
 *
 * ============================================
 */
#include "sort.h"

/**
 * insertion_sort_list - function to sort doubly linked list in ascending order
 * @list: doubly linked list
 */

void sorted_insert(listint_t **head_ref, listint_t *new_node);

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	while (current != NULL) {
		listint_t *next = current->next;
		current->prev = current->next = NULL;
		sorted_insert(&sorted, current);
		current = next;
	}
	*list = sorted;
}

void sorted_insert(listint_t **head_ref, listint_t *new_node)
{
	listint_t *current;

	if (*head_ref == NULL)
		*head_ref = new_node;

	else if ((*head_ref)->n >= new_node->n) {
		new_node->next = *head_ref;
		new_node->next->prev = new_node;
		*head_ref = new_node;
	}

	else {
		current = *head_ref;
		while (current->next != NULL &&
				current->next->n < new_node->n)
			current = current->next;

		new_node->next = current->next;

		if (current->next != NULL)
			new_node->next->prev = new_node;

		current->next = new_node;
		new_node->prev = current;
	}
}
