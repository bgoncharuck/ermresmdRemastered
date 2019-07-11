#include <stdlib.h>

#include "fight_intel.h"

struct __intelCompRound {
	unsigned short id;
	unsigned short energy;
};

intelCompRound * intelCompRound_new () {
	intelCompRound * self = calloc (sizeof (intelCompRound), 1);
	if (!self) abort();
	return self;
}

void intelCompRound_free (intelCompRound * self) {
	if (self) free (self);
}

intelCompRound * intelCompRound_newFilled (unsigned short id, unsigned short energy) {
	intelCompRound * self = intelCompRound_new ();
	self->id = id;
	self->energy = energy;
	return self;
}

unsigned short intelCompRound_id (intelCompRound * self) {
	if (self) return self->id;
}

unsigned short intelCompRound_energy (intelCompRound * self) {
	if (self) return self->energy;
}

void intelCompRound_set_id (intelCompRound * self, unsigned short id) {
	if (self) self->id = id;
}

void intelCompRound_set_energy (intelCompRound * self, unsigned short energy) {
	if (self) self->energy = energy;
}


struct __intel {
	intelCompRound ** round;
};

intel * intel_new () {
	intel * self = calloc (sizeof (intel), 1);
	self->round = calloc (sizeof (intelCompRound *), DECK_SIZE);
	if (!self) abort();

	return self;
}

void intel_free (intel * self) {
	if (self) {

		if (self->round)
			free (self->round);

		free (self);
	}
}

void intel_set (intel * self, const unsigned short numOfRound, intelCompRound * toSet) {

	if (self && toSet) {

		if (self->round[numOfRound])
			intelCompRound_free (self->round[numOfRound]);

		self->round[numOfRound] = toSet;
	}
}

intelCompRound * intel_at (intel * self, const unsigned short numOfRound) {
	if (self)
		return self->round[numOfRound];
}
