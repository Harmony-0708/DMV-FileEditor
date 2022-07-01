#pragma once
#include <string>
#include "AbilityScore.h"
class Spell
{

private:
	std::string Key{};
	int Level{};
	AbilityScoreEnum::AbilityScore Ability{};

public:
	Spell();
	Spell(std::string);

	std::string get_key();
	int get_level();
	AbilityScoreEnum::AbilityScore get_ability();

	void set_key(std::string key);
	void set_level(int level);
	void set_abilityScore(AbilityScoreEnum::AbilityScore ability);

};

