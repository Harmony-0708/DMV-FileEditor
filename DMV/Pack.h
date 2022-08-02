#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include "GUI.h"
#include "SizeEnum.h"
#include "Race.h"
#include "Trait.h"
#include "Item.h"
#include "Spell.h"

class Pack
{
private:
	std::string Name{};
	std::vector<Race> Races{};
	std::vector<Trait> Traits{};
	std::vector<Spell> Spells{};
	std::vector<Item> Items{};

public:

	Pack();
	Pack(std::string name);

	std::string get_name();
	std::vector<Race> get_races();

	void set_name(std::string name);

	void update_race(Race inputRace);
	void update_trait(Trait inputTrait);
	void update_spell(Spell inputSpell);
	void update_item(Item inputItem);
	void set_races(Race inputRace);
	void set_races(std::vector<Race> inputRaces);
	void set_traits(Trait inputTrait);
	void set_traits(std::vector<Trait> inputTraits);
	void set_spells(Spell inputSpell);
	void set_spells(std::vector<Spell> inputSpells);
	void set_items(Item inputItem);
	void set_items(std::vector<Item> inputItems);

	int load_pack(std::string packName);
	Pack load_pack(std::fstream& myfile);
	Pack load_orcbrew(std::fstream& myfile);
	void save_pack();
	void save_pack(std::ofstream& myfile);
	void print_pack();
	void print_pack(bool multi, std::ofstream& outputfile);

};

