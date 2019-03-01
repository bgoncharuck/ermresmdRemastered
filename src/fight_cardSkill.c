#include <stdlib.h>

#include "fight_cardSkill.h"

struct __cardSkill {
	skillCondition condition;
	skillType type;
	unsigned short value;
}

cardSkill * cardSkill_new () {
	cardSkill * self = calloc (sizeof(cardSkill), 1);
	if (!self) abort ();

	return self;
}

void cardSkill_free (cardSkill * skill) {
	if (skill)
		free (skill);
}

cardSkill * cardSkill_newFilled (skillCondition condition, skillType type, unsigned short value) {
	cardSkill * self = cardSkill_new ();

	self->condition = condition;
	self->type = type;
	self->value = value;

	return self;
}

skillCondition cardSkill_condition (cardSkill * self) {
	if (self)
		return self->condition;
}

skillType cardSkill_type (cardSkill * self) {
	if (self)
		return self->type;
}

unsigned short cardSkill_value (cardSkill * self) {
	if (self)
		return self->value;
}

void cardSkill_set_condition (cardSkill * self, skillCondition condition) {
	if (self)
		self->condition = condition;
}

void cardSkill_set_type (cardSkill * self, skillType type) {
	if (self)
		self->type = type;
}

void cardSkill_set_value (cardSkill * self, unsigned short value) {
	if (self)
		self->value = value;
}
