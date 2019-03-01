#pragma once

#include "skills.h"

typedef struct __cardSkill cardSkill;

cardSkill * cardSkill_new () ;
void cardSkill_free (cardSkill * skill) ;
cardSkill * cardSkill_newFilled (skillCondition condition, skillType type, unsigned short value) ;
skillCondition cardSkill_condition (cardSkill * self) ;
skillType cardSkill_type (cardSkill * self) ;
unsigned short cardSkill_value (cardSkill * self) ;
void cardSkill_set_condition (cardSkill * self, skillCondition condition) ;
void cardSkill_set_type (cardSkill * self, skillType type) ;
void cardSkill_set_value (cardSkill * self, unsigned short value) ;
