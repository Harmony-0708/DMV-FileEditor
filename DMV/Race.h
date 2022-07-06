#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include "TraitType.h"
#include "SizeEnum.h"
#include "Spell.h"
#include "Trait.h"
#include "harmonylib.h"
class Race
{
private:

	//Private variables
	std::string Key{};
	std::string Name{};
	std::string OptionPack{};
	std::string Description{};
	SizeEnum::Size Size{};
	int Str{};
	int Dex{};
	int Con{};
	int Int{};
	int Wis{};
	int Cha{};
	int Speed{};
	int FlyingSpd{};
	int SwimmingSpd{};
	int DarkVision{};
	int SkillOptionsCount{};
	int LanguageOptionsCount{};
	int WeaponOptionsCount{};
	bool LizFolkAC{};
	bool TortAC{};
	std::vector<std::string> Languages{};
	std::vector<std::string> Tools{};
	std::vector<std::string> SkillOptions{};
	std::vector<std::string> SkillProf{};
	std::vector<std::string> LanguageOptions{};
	std::vector<std::string> WeaponOptions{};
	std::vector<std::string> WeaponProf{};
	std::vector<std::string> ArmorProf{};
	std::vector<std::string> DamageRes{};
	std::vector<std::string> DamageImmun{};
	std::vector<Trait> Traits{};
	std::vector<std::vector<Spell>> Spells{};
public:

	//Constructors
	Race();
	Race(std::string);

	//DisplayVector overrides
	void DisplayVector(int wrapLimit, std::vector<Spell> inputVector);
	void DisplayVector(int wrapLimit, std::vector<Trait> inputVector);

	//Get variables
	std::string get_key();
	std::string get_name();
	std::string get_optionPack();
	std::string get_description();
	SizeEnum::Size get_size();
	std::string get_sizename();
	int get_str();
	int get_dex();
	int get_con();
	int get_int();
	int get_wis();
	int get_cha();
	int get_speed();
	int get_flySpeed();
	int get_swimSpeed();
	int get_darkVision();
	int get_skillOptionsCount();
	int get_languageOptionsCount();
	int get_weaponOptionsCount();
	bool get_lizFolkAC();
	bool get_tortAC();
	std::string get_language(int index);
	std::vector<std::string> get_language();
	std::string get_tool(int index);
	std::vector<std::string> get_tool();
	std::string get_skillOption(int index);
	std::vector<std::string> get_skillOption();
	std::string get_skillProf(int index);
	std::vector<std::string> get_skillProf();
	std::string get_languageOption(int index);
	std::vector<std::string> get_languageOption();
	std::string get_weaponOption(int index);
	std::vector<std::string> get_weaponOption();
	std::string get_weaponProf(int index);
	std::vector<std::string> get_weaponProf();
	std::string get_armorProf(int index);
	std::vector<std::string> get_armorProf();
	std::string get_damageRes(int index);
	std::vector<std::string> get_damageRes();
	std::string get_damageImmun(int index);
	std::vector<std::string> get_damageImmun();
	Trait get_trait(int index);
	std::vector<Trait> get_trait();
	Spell get_spell(int index,std::string spellName);
	std::vector<std::vector<Spell>> get_spell();

	//Setting variables
	void set_key(std::string key);
	void set_name(std::string name);
	void set_optionPack(std::string optionPack);
	void set_description(std::string description);
	void set_size(SizeEnum::Size size);
	void set_str(int str);
	void set_dex(int dex);
	void set_con(int con);
	void set_int(int Inte);
	void set_wis(int wis);
	void set_cha(int cha);
	void set_speed(int speed);
	void set_flySpeed(int flyspeed);
	void set_swimSpeed(int swimspeed);
	void set_darkVision(int darkVision);
	void set_skillOptionsCount(int skillOptionsCount);
	void set_languageOptionsCount(int languageOptionsCount);
	void set_weaponOptionsCount(int weaponOptionsCount);
	void set_lizFolkAC(bool lizAC);
	void set_tortAC(bool tortAC);

	//Inserting vectors. Each one has 1 insert method and an ability to overwrite the current vector
	void insert_language(std::string language);
	void insert_language(std::vector<std::string> languages);
	void insert_tool(std::string tool);
	void insert_tool(std::vector<std::string> tools);
	void insert_skillOption(std::string skillOption);
	void insert_skillOption(std::vector<std::string> skillOptions);
	void insert_skillProf(std::string skillProf);
	void insert_skillProf(std::vector<std::string> skillProfs);
	void insert_languageOption(std::string languageOption);
	void insert_languageOption(std::vector<std::string> languageOptions);
	void insert_weaponOption(std::string weaponOption);
	void insert_weaponOption(std::vector<std::string> weaponOptions);
	void insert_weaponProf(std::string weaponProf);
	void insert_weaponProf(std::vector<std::string> weaponProfs);
	void insert_armorProf(std::string armorProf);
	void insert_armorProf(std::vector<std::string> armorProfs);
	void insert_damageRes(std::string damageRes);
	void insert_damageRes(std::vector<std::string> damageResList);
	void insert_damageImmun(std::string damageImmun);
	void insert_damageImmun(std::vector<std::string> damageImmunList);
	void insert_trait(Trait trait);
	void insert_trait(std::vector<Trait> traits);

	//Spells allow for indexing to match levels. 0 is level 1, 2 is level 1, 3 is level 2, etc etc
	void insert_spell(int index, Spell spell);
	void insert_spell(std::vector<std::vector<Spell>> spellList);

	//Gets all info on race, for display reasons
	void display_info();

};

