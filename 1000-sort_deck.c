#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_value - returns numeric value of card
 * @value: string value
 * Return: number
 */
int get_value(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * card_cmp - comparison function for qsort
 * @a: pointer a
 * @b: pointer b
 * Return: comparison result
 */
int card_cmp(const void *a, const void *b)
{
	const deck_node_t *card_a = *(const deck_node_t **)a;
	const deck_node_t *card_b = *(const deck_node_t **)b;

	int suit_a = card_a->card->kind;
	int suit_b = card_b->card->kind;

	int val_a = get_value(card_a->card->value);
	int val_b = get_value(card_b->card->value);

	if (suit_a != suit_b)
		return (suit_a - suit_b);

	return (val_a - val_b);
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	deck_node_t **array;
	size_t count = 0, i;

	if (!deck || !*deck)
		return;

	/* count nodes */
	current = *deck;
	while (current)
	{
		count++;
		current = current->next;
	}

	array = malloc(sizeof(deck_node_t *) * count);
	if (!array)
		return;

	/* fill array */
	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}

	/* sort */
	qsort(array, count, sizeof(deck_node_t *), card_cmp);

	/* rebuild linked list */
	for (i = 0; i < count; i++)
	{
		array[i]->prev = (i == 0) ? NULL : array[i - 1];
		array[i]->next = (i == count - 1) ? NULL : array[i + 1];
	}

	*deck = array[0];

	free(array);
}
