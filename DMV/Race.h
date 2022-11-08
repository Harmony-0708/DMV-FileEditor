#pragma once
#include <iostream>
#include <fstream>
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
#include "GUI.h"
#include "harmonylib.h"
#include "CommandObject.h"
#include "Console.h"

class Race :
	public CommandObject
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

	Console RaceConsole{};

	//Virtual 

	std::string Title{"Race"};
	std::string DoneVariable{};
	std::vector<std::string> Commands{
		"done",
		"help",
		"cancel",
		"add",
		"edit",
		"clear",
		"remove"
	};
	std::vector<std::string> CommandDefs{
		"Finishes Race",
		"Get help on command",
		"Cancels current action",
		"Add an aspect of race",
		"Edit aspect",
		"Clears race",
		"Remove element"
	};
	std::vector<std::string> GlobalRaceOptions{
		"name",
		"option-pack",
		"description",
		"size",
		"str",
		"dex",
		"con",
		"int",
		"wis",
		"cha",
		"speed",
		"flying-speed",
		"swimming-speed",
		"dark-vision",
		"skill-opscount",
		"lang-opscount",
		"weapon-opscount",
		"lizard-ac",
		"tortle-ac",
		"languages",
		"tools",
		"skill-ops",
		"skill-profs",
		"language-ops",
		"weapon-ops",
		"Weapon-profs",
		"armor-profs",
		"damage-res",
		"damage-imm",
		"trait"
	};
	std::vector<std::string> GlobalRaceDefs{
		"The name of your Race",
		"The name of the pack your race is in",
		"The Description of your race",
		"The size of your race",
		"Strength mod",
		"Dexterity mod",
		"Constitution mod",
		"Intelligence mod",
		"Wisdom mod",
		"Charisma mod",
		"Your race's speed",
		"Your race's flying speed, 0 if none",
		"Your race's swimming speed",
		"Your race's dark vision",
		"The ammount of skill options you have, Min 1",
		"The ammount of language options you have, Min 1",
		"The ammount of weapon options you have, Min 1",
		"Whether or no your race has lizardfolk AC",
		"Whether or no your race has tortle AC",
		"The languages your race knows",
		"The tools your race is proficent in",
		"Your race's skill options",
		"Your race's skill proficencies",
		"Your race's language options",
		"Your race's weapon options",
		"Your race's weapon proficiencies",
		"Your race's armor proficiencies",
		"Types of damage your race is resistance to",
		"Types of damage your race is immune to",
		"The specific traits of your race"
	};

public:

	//Constructors
	Race();
	Race(std::string);

	//Clear
	void clear();

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

	//Race merge(Race r1, Race r2);

	void print(std::ofstream& myfile);

	void load(bool& inTraits, std::string& declared, bool& input, Race& newRace, Trait& newTrait, std::string& variable, bool& inObject, std::vector<Race>& myRaces, bool& inRaces);

	//Gets all info on race, for display reasons
	void display_info();

	CommandObject* Add(CommandObject* currentRace, std::vector<std::string>& parameters);

	CommandObject* Edit(CommandObject* currentRace, std::vector<std::string>& parameters);

	CommandObject* Remove(CommandObject* currentRace, std::vector<std::string>& parameters);

		//Virtual Overrides
		CommandObject* ExecuteCommand(int cmdCode, CommandObject* object, std::vector<std::string> parameters = {}, std::string context = {});
		void Display();
		std::string get_title();
		bool IsDone(std::string input);
		std::vector<std::string> get_commands();
		std::vector<std::string> get_command_defs();
};

