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

char * card_name (card * self) {
	if (self)
		return self->name;
}

unsigned short card_complexity (card * self) {
	if (self)
		return self->complexity;
}

unsigned short card_damage (card * self) {
	if (self)
		return self->damage;
}

unsigned short card_lvl (card * self) {
	if (self)
		return self->lvl;
}

cardSkill * card_skill (card * self) {
	if (self)
		return self->skill;
}

cardSkill * card_kind (card * self) {
	if (self)
		return self->kind;
}

void card_set_name (card * self, char * name) {
	if (self) {
		if (self->name)
			free (self->name);
		self->name = name;
	}
}

void card_set_complexity (card * self, unsigned short complexity) {
	if (self) {
		self->complexity = complexity;
	}
}

void card_set_damage (card * self, unsigned short lvl) {
	if (self) {
		self->damage = damage;
	}
}

void card_set_lvl (card * self, unsigned short lvl) {
	if (self) {
		self->lvl = lvl;
	}
}

void card_set_skill (card * self, cardSkill * skill) {
	if (self) {
		if (self->skill)
			cardSkill_free (self->skill);
		self->skill = skill;
	}
}

void card_set_kind (card * self, cardSkill * kind) {
	if (self) {
		if (self->kind)
			cardSkill_free (self->kind);
		self->kind = kind;
	}
}
