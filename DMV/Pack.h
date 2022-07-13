#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include "GUI.h"
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

	void set_name(std::string name);

	void set_races(Race inputRace);
	void set_races(std::vector<Race> inputRaces);
	void set_traits(Race inputRace);
	void set_traits(std::vector<Race> inputRaces);
	void set_spells(Race inputRace);
	void set_spells(std::vector<Race> inputRaces);
	void set_items(Race inputRace);
	void set_items(std::vector<Race> inputRaces);

	void print_pack();

};

