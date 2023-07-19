#include "sort.h"

/**
 * insertion_sort_list - sorts a list using the insertion sort algorithm
 * @list: A doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *curr_tmp, *prev, *next;

	if (list == NULL)
		return;

	curr = *list;

	while (curr)
	{
		while (curr->next != NULL && curr->n > curr->next->n)
		{
			next = curr->next;
			prev = curr->prev;
			curr_tmp = curr;

			curr->next = next->next;
			next->prev = prev;

			if (prev != NULL)
				prev->next = next;

			if (next->next != NULL)
				next->next->prev = curr;

			curr->prev = next;
			next->next = curr_tmp;

			if (next->prev != NULL)
				curr = next->prev;
			else
				*list = next;

			print_list(*list);
		}
		curr = curr->next;
	}
}
