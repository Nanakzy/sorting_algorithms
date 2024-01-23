#include "sort.h"

/**
 * cocktail_sort_list - Sort doubly linked list of int in ascending order
 * using the Cocktail shaker sort algorithm.
 *
 * @list: Pointer to the pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Traverse forward */
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(curr, curr->next, list);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		/* Traverse backward */
		for (; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(curr->prev, curr, list);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @node1: First node to swap
 * @node2: Second node to swap
 * @list: Pointer to the pointer to the doubly linked list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1->next != NULL)
		node1->next->prev = node1;

	if (node2->prev != NULL)
		node2->prev->next = node2;
}
