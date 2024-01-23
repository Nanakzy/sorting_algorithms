#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of int in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
