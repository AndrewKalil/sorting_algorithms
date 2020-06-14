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
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (!list || !(*list))
		return;

	while (current)
	{
		while (current->prev &&
				current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (!(current->prev))
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = current->next;
	}
}

