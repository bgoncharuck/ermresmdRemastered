#include <stdlib.h>

#include "fight_card.h"

struct __card {
	char * name;
	unsigned short complexity;
	unsigned short damage;
	unsigned short lvl;
	cardSkill * skill;
	cardSkill * kind;
};

card * card_new () {
	card * self = calloc (sizeof(card), 1);
	is (!self) abort();

	return self;
}

void card_free (card * self) {
	if (self) {

		if (self->name)
			free (self->name);
		if (self->skill)
			cardSkill_free (self->skill);
		if (self->kind)
			cardSkill_free (self->kind);

		free (self);
	}
}

card * card_newFilled (char * name, unsigned short complexity, unsigned short damage,
unsigned short lvl, cardSkill * skill, cardSkill * kind) {

	card * self = card_new();

	self->name = name;
	self->complexity = complexity;
	self->damage = damage;
	self->lvl = lvl;
	self->skill = skill;
	self->kind = kind;

	return self;
}
