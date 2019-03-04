#pragma once

#include "fight_cardSkill.h"

typedef struct __card card;

card * card_new () ;
void card_free (card * self) ;
card * card_newFilled (char * name, unsigned short complexity, unsigned short damage,
unsigned short lvl, cardSkill * skill, cardSkill * kind) ;


char * card_name (card * self) ;
unsigned short card_complexity (card * self) ;
unsigned short card_damage (card * self) ;
unsigned short card_lvl (card * self) ;
cardSkill * card_skill (card * self) ;
cardSkill * card_kind (card * self) ;


void card_set_name (card * self, char * name) ;
void card_set_complexity (card * self, unsigned short complexity) ;
void card_set_damage (card * self, unsigned short lvl) ;
void card_set_lvl (card * self, unsigned short lvl) ;
void card_set_skill (card * self, cardSkill * skill) ;
void card_set_kind (card * self, cardSkill * kind) ;
