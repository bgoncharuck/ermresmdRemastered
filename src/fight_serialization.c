#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fight_serialization.h"

serializationObject * cardSkill_serialize (cardSkill * skill) {

	// Titles
	char * title_condition = calloc (sizeof (char), 9);
	sprintf (title_condition, "Condition\0");
	char * title_type = calloc (sizeof (char), 5);
	sprintf (title_type, "Type\0");
	char * title_value = calloc (sizeof (char), 6);
	sprintf (title_value, "Value\0");

	// Values
	unsigned short * value_condition = calloc (sizeof (unsigned short), 1);
	unsigned short * value_type = calloc (sizeof (unsigned short), 1);
	unsigned short * value_value = calloc (sizeof (unsigned short), 1);

	*value_condition = cardSkill_condition (skill);
	*value_type = cardSkill_type (skill);
	*value_value = cardSkill_value (skill);

	// Points
	serializationPoint * condition =
	serializationPoint_new (title_condition, integerType, (void *) value_condition) ;

	serializationPoint * type =
	serializationPoint_new (title_type, integerType, (void *) value_type) ;

	serializationPoint * value =
	serializationPoint_new (title_value, integerType, (void *) value_value) ;

	// Object
	serializationObject * self = serializationObject_new();

	serializationObject_insert (self, 0, condition);
	serializationObject_insert (self, 1, type);
	serializationObject_insert (self, 2, value);

	return self;
}

void serialized_cardSkill_free (serializationObject * self) {

	free ((unsigned short *)(serializationPoint_value( (serializationObject_at (self, 2)))));
	free ((serializationPoint_title( (serializationObject_at (self, 2)))));
	serializationPoint_free (serializationPoint_title( (serializationObject_at (self, 2))));

	free ((unsigned short *)(serializationPoint_value( (serializationObject_at (self, 1)))));
	free ((serializationPoint_title( (serializationObject_at (self, 1)))));
	serializationPoint_free (serializationPoint_title( (serializationObject_at (self, 1))));

	free ((unsigned short *)(serializationPoint_value( (serializationObject_at (self, 0)))));
	free ((serializationPoint_title( (serializationObject_at (self, 0)))));
	serializationPoint_free (serializationPoint_title( (serializationObject_at (self, 0))));

	serializationObject_free (self);
}

cardSkill * serialized_cardSkill_load (serializationObject * self) {

}


serializationObject * card_serialize (card * Card) {

	// Titles
	char * title_name = calloc (sizeof (char), 5);
	sprintf (title_name, "Name\0");
	char * title_complexity = calloc (sizeof (char), 11);
	sprintf (title_complexity, "Complexity\0");
	char * title_damage = calloc (sizeof (char), 7);
	sprintf (title_damage, "Damage\0");
	char * title_lvl = calloc (sizeof (char), 4);
	sprintf (title_lvl, "Lvl\0");
	char * title_skill = calloc (sizeof (char), 6);
	sprintf (title_skill, "Skill\0");
	char * title_kind = calloc (sizeof (char), 5);
	sprintf (title_kind, "Kind\0");

	// Values
	char * value_name = calloc (sizeof (char), 1 + strlen (card_name (Card)) );
	unsigned short * value_complexity = calloc (sizeof (unsigned short), 1);
	unsigned short * value_damage = calloc (sizeof (unsigned short), 1);
	unsigned short * value_lvl = calloc (sizeof (unsigned short), 1);

	sprintf (value_name, "%s\0", card_name(Card) );
	*value_complexity = card_complexity (Card);
	*value_damage = card_damage (Card);
	*value_lvl = card_lvl (Card);

	serializationObject * value_skill = cardSkill_serialize (card_skill (Card) );
	serializationObject * value_kind = cardSkill_serialize (card_kind (Card) );

	// Points
	serializationPoint * name =
	serializationPoint_new (title_name, stringType, (void *) value_name) ;

	serializationPoint * complexity =
	serializationPoint_new (title_complexity, integerType, (void *) value_complexity) ;

	serializationPoint * damage =
	serializationPoint_new (title_damage, integerType, (void *) value_damage) ;

	serializationPoint * lvl =
	serializationPoint_new (title_lvl, integerType, (void *) value_lvl) ;

	serializationPoint * skill =
	serializationPoint_new (title_skill, objectType, (void *) value_skill) ;

	serializationPoint * kind =
	serializationPoint_new (title_kind, objectType, (void *) value_kind) ;

	// Object
	serializationObject * self = serializationObject_new();

	serializationObject_insert (self, 0, name);
	serializationObject_insert (self, 1, complexity);
	serializationObject_insert (self, 2, damage);
	serializationObject_insert (self, 3, lvl);
	serializationObject_insert (self, 4, skill);
	serializationObject_insert (self, 5, kind);

	return self;
}

void serialized_card_free (serializationObject * self) {

}

card * serialized_card_load (serializationObject * self) {

}


serializationObject * deck_serialize (deck * Deck) {

}

void serialized_deck_free (serializationObject * self) {

}

deck * serialized_deck_load (serializationObject * self) {


}
