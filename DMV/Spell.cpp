#include "Spell.h"

Spell::Spell()
{
	Key = "";
}
Spell::Spell(std::string key)
{
	Key = key;
}
std::string Spell::get_key()
{
	return Key;
}
int Spell::get_level()
{
	return Level;
}
AbilityScoreEnum::AbilityScore Spell::get_ability()
{
	return Ability;
}

//Assignment
void Spell::set_key(std::string key)
{
	Key = key;
}
void Spell::set_level(int level)
{
	Level = level;
}
void Spell::set_abilityScore(AbilityScoreEnum::AbilityScore ability)
{
	Ability = ability;
}