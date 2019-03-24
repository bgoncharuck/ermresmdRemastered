#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "serialization.h"

#define empty(MEM, SIZE) memset(MEM, 0, SIZE)
#define throw(MSG) { fprintf(stderr, MSG); assert(0 && MSG); }

enum __seriliazationType {
	booleanType,
	integerType,
	floatType,
	stringType,
	objectType,
	arrayType
};

struct __serializationPoint {
	// title must be dynamic
	char * title;

	serializationType type;

	// value must be dynamic
	void * value;
};

serializationPoint * serializationPoint_new
(const char * title, serializationType type, void * value) {

	if (!title || !value)
		throw ("NULL pointer  in serializationPointer_new from /src/serialization.c")

	serializationPoint * self = calloc (sizeof (serializationPoint), 1);
	if (!self) abort();

	self->title = title;
	self->type = type;
	self->value = value;

	return self;
}

void serializationPoint_free (serializationPoint * self) {
	if (self)
		free (self);
}

void serializationPoint_change
(serializationPoint * self, const char * title, serializationType type, void * value) {

	if (!self || !title || !value)
		throw ("NULL pointer in serializationPointer_new from /src/serialization.c")

	self->title = title;
	self->type = type;
	self->value = value;
}

const char * serializationPoint_title (serializationPoint * self) {
	if (self)
		return self->title;
}

serializationType serializationPoint_type (serializationPoint * self) {
	if (self)
		return self->type;
}

void * serializationPoint_value (serializationPoint * self) {
	if (self)
		return self->value;
}

struct __serializationObject {
	size_t size;
	size_t capacity;
	serializationPoint ** serializationPoints;
};

static const int initialCapacity = 4;

// from libprogbase by Ruslan Hadinyak
static void ensureCapacity (serializationObject * self, size_t min) {

    if (self->size <= min) {

		size_t newCapacity = self->size == 0 ? initialCapacity : self->size * 2;
        if (newCapacity < min) newCapacity = min;
        self->capacity = newCapacity;

		size_t newSize = sizeof(serializationPoint *) * self->capacity;
        void * newMem = realloc(self->serializationPoints, newSize);
		if (newMem == NULL)
			throw("Realloc error in ensureCapacity() from /src/serialization.c");

        self->serializationPoints = newMem;
    }
}

serializationObject * serializationObject_new () {

	serializationObject * self = calloc (sizeof(serializationObject), 1);
	if (!self) abort();

	self->capacity = initialCapacity;
	self->size = 0;

	self->serializationPoints = malloc (0);
	ensureCapacity (self, 0);

	return self;
}

void serializationObject_free (serializationObject * self) {
	if (self) {
		if (self->serializationPoints)
			free (self->serializationPoints);

		free (self);
	}
}

serializationPoint * serializationObject_at (serializationObject * self, size_t index) {
	if (index < 0 || index >= self->size)
		throw("Index out of bounds in serializationObject_at from /src/serialization.c");

	return self->serializationPoints[index];
}

void serializationObject_set (serializationObject * self, size_t index, serializationPoint * point) {
    if (!self || !point)
		throw("NULL reference in serializationObject_set from /src/serialization.c");

    if (index < 0 || index >= self->size)
		throw("Index out of bounds in serializationObject_set from /src/serialization.c");

	self->serializationPoints[index] = point;
}

void serializationObject_add (serializationObject * self, serializationPoint * point) {

	if (self->size <= self->capacity)
        ensureCapacity(self, self->size + 1);

    serializationObject_set (self, self->size++, point);
}

void serializationObject_insert (serializationObject * self, size_t index, serializationPoint * point) {

    if (!self || !point)
		throw("NULL reference in serializationObject_insert from /src/serialization.c");

	if (index > self->size)
		throw("Argument out of range in serializationObject_insert from /src/serialization.c");

	if (self->size >= self->capacity - 1)
    	ensureCapacity(self, self->size + 1);

	if (index < self->size) {
		// @TODO
    }

	serializationObject_set (self, index, point);
    self->size++;
}

long long serializationObject_indexOfTitle (serializationObject * self, const char * title) {
	if (!self || !title)
		throw("NULL reference in serializationObject_indexOfTitle from /src/serialization.c");

	for (size_t i = 0; i < self->size; i++) {
        if ( strcmp(self->serializationPoints[i]->title, title) == 0 ) {
            return (long long) i;
        }
    }

    return -1;
}

bool serializationObject_contains (serializationObject * self, const char * title) {
	return serializationObject_indexOfTitle (self, title) >= 0;
}

bool serializationObject_remove(serializationObject * self, const char * title) {

	if (!self || !title)
		throw("NULL reference in serializationObject_indexOfTitle from /src/serialization.c");

    long long index = serializationObject_indexOf (self, title);

	if (index >= 0) {
        serializationObject_removeAt(self, (size_t) index);
        return true;
    }
    return false;
}

void serializationObject_removeAt (serializationObject * self, size_t index) {

    if (index < 0 || index >= self->size)
		throw("Index out of bounds in serializationObject_removeAt from /src/fight_serialization.c");

    self->size--;
    if (index < self->size) {
		// @TODO
    }
}

bool serializationObject_isEmpty (serializationObject * self) {
	if (self)
		return self->size == 0;
}

size_t  serializationObject_count (serializationObject * self) {
	if (self)
		return self->size;
}

void serializationObject_clear (serializationObject * self);
