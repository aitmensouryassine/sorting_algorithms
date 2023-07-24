#include "deck.h"
#include <string.h>

/**
 * cardcmp - compares two cards
 * @c1: the first card
 * @c2: the second card
 * Return: int > 1 if c1 comes after c2
 *         int < 1 if c1 comes before c2
 *         int = 0 if c1 is c2
 */
int cardcmp(deck_node_t *c1, deck_node_t *c2)
{
	int c1_card_val, c2_card_val;

	if (strcmp(c1->card->value, "Ace") == 0)
		c1_card_val = 1;
	else if (strcmp(c1->card->value, "10") == 0)
		c1_card_val = 10;
	else if (strcmp(c1->card->value, "Jack") == 0)
		c1_card_val = 11;
	else if (strcmp(c1->card->value, "Queen") == 0)
		c1_card_val = 12;
	else if (strcmp(c1->card->value, "King") == 0)
		c1_card_val = 13;
	else
		c1_card_val = c1->card->value[0] - 48;

	if (strcmp(c2->card->value, "Ace") == 0)
		c2_card_val = 1;
	else if (strcmp(c2->card->value, "10") == 0)
		c2_card_val = 10;
	else if (strcmp(c2->card->value, "Jack") == 0)
		c2_card_val = 11;
	else if (strcmp(c2->card->value, "Queen") == 0)
		c2_card_val = 12;
	else if (strcmp(c2->card->value, "King") == 0)
		c2_card_val = 13;
	else
		c2_card_val = c2->card->value[0] - 48;

	if (c1->card->kind == c2->card->kind)
	{
		return (c1_card_val - c2_card_val);
	}
	return (c1->card->kind - c2->card->kind);
}

/**
 * swap_node - swaps two nodes in a doubly linked list
 * @n1: the first node to swap
 * @n2: the second node to swap
 * @deck: the doubly linked list
 * @t: the tail
 */
void swap_node(deck_node_t *n1, deck_node_t *n2, deck_node_t **deck,
	       deck_node_t **t)
{
	deck_node_t *prev, *curr, *next;

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
		*deck = next;

	if (!(curr->next))
		*t = curr;
}

/**
 * cocktail_sort_list - sort a deck(list) using the cocktail shaker sort
 * algorithm
 * @deck: The doubly linked list to sort
 */
void cocktail_sort_list(deck_node_t **deck)
{
	deck_node_t *tail, *ptr;
	int swapped;

	if (!deck)
		return;

	tail = *deck;
	while (tail->next)
		tail = tail->next;

	do {
		swapped = 0;
		ptr = *deck;
		while (ptr)
		{
			while (ptr->next && cardcmp(ptr, ptr->next) > 0)
			{
				swap_node(ptr, ptr->next, deck, &tail);
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
			while (ptr->prev && cardcmp(ptr, ptr->prev) < 0)
			{
				swap_node(ptr->prev, ptr, deck, &tail);
				swapped = 1;
				ptr = ptr->next;
			}
			ptr = ptr->prev;
		}
	} while (swapped);
}

/**
 * sort_deck - sorts a deck using the cocktail sort algorithm
 * @deck: the deck of cards to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	cocktail_sort_list(deck);
}
