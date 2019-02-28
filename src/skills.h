#pragma once

typedef enum __skillType {
	SkillIsNone,
	Power_increase,
	Power_decrease,
	Cancel_power_modif,
	Cancel_complexity_modif,
	Cancel_damage_modif,
	Cancel_energy_modif,
	Cancel_life_modif,
	Copy_kind,
	Copy_skill,
	Damage_increase,
	Damage_decrease,
	Complexity_increase,
	Complexity_decrease,
	Exchange_complexity,
	Exchange_damage,
	Exchange_complexityAndDamage,
	Stop_skill,
	Stop_kind,
	Energy_increae,
	Energy_decrease,
	Life_increase,
	Life_decrease,
	Curse,
	HealingSpell,
	Absorb_health,
	Absorb_energy,
	Protection_skill,
	Protection_kind
} skillType;

const char * info_skillType[] = {
	"",
	"Increase power by ",
	"Decrease op power by ",
	"Op power modifers not working",
	"Op complexity modifers not working",
	"Op damage modifers not working",
	"Op energy modifers not working",
	"Op life modifers not working",
	"Copy op kind",
	"Copy op skill",
	"Increase damage by ",
	"Decrease op damage by ",
	"Increase complexity by ",
	"Decrease op complexity by ",
	"Exhcange complexity with op",
	"Exchange damage with op",
	"Exchange damage and complexity with op",
	"Stop op skill",
	"Stop op kind",
	"Increase energy by ",
	"Decrease op energy by ",
	"Increase life by ",
	"Decrease op life by ",
	"Curse",
	"Healing spell",
	"Absorb health from op fro damage per ",
	"Absorb energy from op fro damage per ",
	"Protect skill",
	"Protect kind"
};

typedef enum __skillCondition {
	ConditionIsNone,
	Defeat,
	Revenge,
	Confidence
} skillCondition;

const char * info_skillCondition[] = {
	"",
	"Defeat",
	"Revenge",
	"Confidence"
};
