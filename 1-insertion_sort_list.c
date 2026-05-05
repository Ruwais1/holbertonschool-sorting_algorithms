#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next_node = curr->next;
		while (curr->prev != NULL && curr->prev->n > curr->n)
		{
			prev_node = curr->prev;

			/* Disconnect prev_node and curr to swap them */
			prev_node->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev_node;

			curr->prev = prev_node->prev;
			curr->next = prev_node;

			/* Reconnect the surrounding nodes */
			if (prev_node->prev != NULL)
				prev_node->prev->next = curr;
			else
				*list = curr; /* Update head if curr moved to the front */

			prev_node->prev = curr;

			/* Print the list after every successful swap */
			print_list(*list);
		}
		curr = next_node;
	}
}
