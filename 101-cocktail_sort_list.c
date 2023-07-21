#include "sort.h"

/**
 * swap_node - swaps two nodes in a douibly linked list
 * @n1: the first node to swap
 * @n2: the second node to swap
 * @list: the linked list
 * @t: the tail
 */
void swap_node(listint_t *n1, listint_t *n2, listint_t **list, listint_t **t)
{
	listint_t *prev, *curr, *next;

	prev = n1->prev;
	curr = n1;
	next = n2;

	curr->next = next->next;
	next->prev = prev;

	if (prev)
		prev->next = next;

	if (next->next)
		next->next->prev = curr;

	curr->prev = next;
	next->next = curr;

	if (!(next->prev))
		*list = next;
	if (!(curr->next))
		*t = curr;

	print_list(*list);
}

/**
 * cocktail_sort_list - sort a list using the cocktail shaker sort algorithm
 * @list: The doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail, *ptr;
	int swapped;

	if (!list)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;
	head = *list;

	do {
		swapped = 0;
		ptr = head;
		while (ptr)
		{
			while (ptr->next && ptr->n > ptr->next->n)
			{
				swap_node(ptr, ptr->next, list, &tail);
				swapped = 1;
				ptr = ptr->prev;
			}
			ptr = ptr->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		ptr = tail;
		while (ptr)
		{
			while (ptr->prev && ptr->n < ptr->prev->n)
			{
				swap_node(ptr->prev, ptr, list, &tail);
				swapped = 1;
				ptr = ptr->next;
			}
			ptr = ptr->prev;
		}
	} while (swapped);
}
