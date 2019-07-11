#include <stdlib.h>

#include "fight_deck.h"

struct __deck {
	card ** cards;
};

deck * deck_new () {
	deck * self = calloc (sizeof (deck), 1);
	self->cards = calloc (sizeof (card *), DECK_SIZE);
	if (!self) abort();

	return self;
}

void deck_free (deck * self) {
	if (self) {

		if (self->cards)
			free (self->cards);

		free (self);
	}
}

void deck_set (deck * self, const unsigned short id, card * toSet) {

	if (self && toSet) {

		if (self->cards[id])
			card_free (self->cards[id]);

		self->cards[id] = toSet;
	}
}

card * deck_at (deck * self, const unsigned short id) {
	if (self)
		return self->cards[id];
}
