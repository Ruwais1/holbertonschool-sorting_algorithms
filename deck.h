#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Enumerates the suits of a deck of cards
 *
 * @SPADE: Spades
 * @HEART: Hearts
 * @CLUB: Clubs
 * @DIAMOND: Diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Defines a playing card
 *
 * @value: Value of the card (Ace, 2-10, Jack, Queen, King)
 * @kind: Suit of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node of a doubly linked list
 *
 * @card: Pointer to the card
 * @prev: Pointer to previous node
 * @next: Pointer to next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototype */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
