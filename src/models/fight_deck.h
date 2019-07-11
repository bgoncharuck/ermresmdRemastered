#pragma once

#define DECK_SIZE 8

#include "fight_card.h"

typedef struct __deck deck;

deck * deck_new () ;
void deck_free (deck * self) ;

void deck_set (deck * self, const unsigned short id, card * toSet) ;
card * deck_at (deck * self, const unsigned short id) ;
