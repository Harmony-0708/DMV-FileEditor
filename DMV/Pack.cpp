#include "Pack.h"

Pack::Pack()
{
	Name = "Default";
}

Pack::Pack(std::string name)
{
	Name = name;
}

std::string Pack::get_name()
{
	return this->Name;
}

std::vector<Race> Pack::get_races()
{
	return this->Races;
}

std::vector<Spell> Pack::get_spells()
{
	return this->Spells;
}

void Pack::set_name(std::string name)
{
	Name = name;
	int index{};
	for (Race i : get_races()) {
		Races.at(index).set_optionPack(Name);
		index++;
	}
}

void Pack::update_race(Race inputRace)
{
	int index{-1};
	bool found{ false };
	for (Race i : get_races()) {
		index++;
		if (i.get_key() == inputRace.get_key()) {
			Races[index] = inputRace;
			found = true;
			break;
		}
	}
	if (!found) {
		set_races(inputRace);
	}
}

void Pack::update_spell(Spell inputSpell)
{
	int index{ -1 };
	bool found{ false };
	for (Spell i : get_spells()) {
		index++;
		if (i.get_key() == inputSpell.get_key()) {
			Spells[index] = inputSpell;
			found = true;
			break;
		}
	}
	if (!found) {
		set_spells(inputSpell);
	}
}

void Pack::set_races(Race inputRace)
{
	this->Races.push_back(inputRace);
}

void Pack::set_races(std::vector<Race> inputRaces)
{
	this->Races = inputRaces;
}

void Pack::set_traits(Trait inputTrait)
{
}

void Pack::set_traits(std::vector<Trait> inputTraits)
{
}

void Pack::set_spells(Spell inputSpell)
{
	this->Spells.push_back(inputSpell);
}

void Pack::set_spells(std::vector<Spell> inputSpells)
{
	this->Spells = inputSpells;
}

void Pack::set_items(Item inputItem)
{
}

void Pack::set_items(std::vector<Item> inputItems)
{
}

int Pack::load_pack(std::string packName)
{
	Name = packName;
	std::ifstream myfile{};
	std::vector<Race> myRaces{ Races };
	std::vector<Spell> mySpells{ Spells };
	Race newRace{};
	Spell newSpell{};
	Trait newTrait{};

	

	myfile.open("CustomPacks/" + Name + ".pck", std::ios::out);

	std::string line;
	int counter{};
	bool inRaces{};
	bool inSpells{};
	bool inTraits{};
	bool input{};



	while (std::getline(myfile, line))
	{
		std::istringstream iss(line);
		std::string variable{ line };
		std::string declared{};
		for (char i : line) {
			if (inTraits) {
				if (!isalpha(i) && i != '{' && i != '}') {
					variable.erase(0, 1);
					break;
				}
			}
			else if (!isalpha(i) && i != '}') {
				variable.erase(0, 1);
				break;
			}
			variable.erase(0, 1);
			declared += i;
		}

		if (!inRaces && !inTraits && !inSpells) {

			if (counter == 0) {
				unsigned first = line.find('\"');
				unsigned last = line.find_last_of('\"');
				std::string lineNew = line.substr(first+1, last - first-1);
				Name = lineNew;
			}
			if (declared == "Races") {
				inRaces = true;
			}
			else if (declared == "Spells") {
				inSpells = true;
			}
		}
		else if (inRaces) {
			if (inTraits) {
				if (declared == "}" && input) {
					input = false;
					newRace.insert_trait(newTrait);
					newTrait.clear();
				}
				else if (declared == "}" && !input) {
					inTraits = false;
				}
				else if (declared == "{name") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_name(variableNew);
					input = true;
				}
				else if (declared == "description") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_description(variableNew);
				}
				else if (declared == "type") {
					switch (std::stoi(variable)) {
					case 0:
						newTrait.set_type(TraitType::Action);
						break;
					case 1:
						newTrait.set_type(TraitType::BAction);
						break;
					case 2:
						newTrait.set_type(TraitType::Reaction);
						break;
					case 3:
						newTrait.set_type(TraitType::Other);
						break;
					}
				}
			}
			else if (declared == "Name") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_name(variableNew);
			}
			else if (declared == "OptionPack") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_optionPack(variableNew);
			}
			else if (declared == "Description") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first+1, last - first-1);
				newRace.set_description(variableNew);
			}
			else if (declared == "Size") {
				if (variable == "Small") {
					newRace.set_size(SizeEnum::small);
				}
				else if (variable == "Medium") {
					newRace.set_size(SizeEnum::medium);
				}
				else if (variable == "Large") {
					newRace.set_size(SizeEnum::large);
				}
			}
			else if (declared == "Str") {
				newRace.set_str(std::stoi(variable));
			}
			else if (declared == "Dex") {
				newRace.set_dex(std::stoi(variable));
			}
			else if (declared == "Con") {
				newRace.set_con(std::stoi(variable));
			}
			else if (declared == "Int") {
				newRace.set_int(std::stoi(variable));
			}
			else if (declared == "Wis") {
				newRace.set_wis(std::stoi(variable));
			}
			else if (declared == "Cha") {
				newRace.set_cha(std::stoi(variable));
			}
			else if (declared == "Speed") {
				newRace.set_speed(std::stoi(variable));
			}
			else if (declared == "FlySpeed") {
				newRace.set_flySpeed(std::stoi(variable));
			}
			else if (declared == "SwimSpeed") {
				newRace.set_swimSpeed(std::stoi(variable));
			}
			else if (declared == "DarkVision") {
				newRace.set_darkVision(std::stoi(variable));
			}
			else if (declared == "SKOC") {
				newRace.set_skillOptionsCount(std::stoi(variable));
			}
			else if (declared == "LNOC") {
				newRace.set_languageOptionsCount(std::stoi(variable));
			}
			else if (declared == "WPOC") {
				newRace.set_weaponOptionsCount(std::stoi(variable));
			}
			else if (declared == "LizFolkAC") {
				if (variable == "0") {
					newRace.set_lizFolkAC(false);
				}
				else {
					newRace.set_lizFolkAC(true);
				}
			}
			else if (declared == "TortAC") {
				if (variable == "0") {
					newRace.set_tortAC(false);
				}
				else {
					newRace.set_tortAC(true);
				}
			}
			else if (declared == "Languages") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_language(vector);
			}
			else if (declared == "LanguageOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_languageOption(vector);

			}
			else if (declared == "SkillProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_skillProf(vector);

			}
			else if (declared == "SkillOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_skillOption(vector);

			}
			else if (declared == "WeaponProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponProf(vector);

			}
			else if (declared == "WeaponOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponOption(vector);

			}
			else if (declared == "DamageRes") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_damageRes(vector);

			}
			else if (declared == "DamageImmun") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_damageImmun(vector);

			}
			else if (declared == "ArmorProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_armorProf(vector);

			}
			else if (declared == "Tools") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != ""){
						vector.push_back(segment);
					}
				}
				newRace.insert_tool(vector);
			}
			else if (declared == "Traits") {
				inTraits = true;
			}
			else if (!inTraits && declared == "}") {
				if (newRace.get_name() != "") {
				myRaces.push_back(newRace);
				}
				newRace.clear();
				inRaces = false;
			}
		}
		else if (inSpells) {
			if (declared == "Name") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_name(variableNew);
			}
			else if (declared == "OptionPack") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_optionPack(variableNew);
			}
			else if (declared == "School") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_school(variableNew);
			}
			else if (declared == "Duration") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_duration(variableNew);
			}
			else if (declared == "Component") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_component(variableNew);
			}
			else if (declared == "CastingTime") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_castingTime(variableNew);
			}
			else if (declared == "Range") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_range(variableNew);
			}
			else if (declared == "Level") {
				newSpell.set_level(std::stoi(variable));
			}
			else if (declared == "Verbal") {
				newSpell.set_verbal(HLib::StringToBool(variable));
			}
			else if (declared == "Somatic") {
				newSpell.set_somatic(HLib::StringToBool(variable));
			}
			else if (declared == "Material") {
				newSpell.set_material(HLib::StringToBool(variable));
			}
			else if (declared == "Ritual") {
				newSpell.set_ritual(HLib::StringToBool(variable));
			}
			else if (declared == "AttackRoll") {
				newSpell.set_attackRoll(HLib::StringToBool(variable));
			}
			else if (declared == "}") {
				if (newSpell.get_name() != "") {
					mySpells.push_back(newSpell);
				}
				newSpell.clear();
				inSpells = false;
			}

		}
		counter++;
	}
	
	set_races(myRaces);
	set_spells(mySpells);
	return 0;
}

Pack Pack::load_pack(std::fstream& myfile)
{
	myfile.clear();
	myfile.seekg(0);
	std::vector<Race> myRaces{ Races };
	std::vector<Spell> mySpells{ Spells };
	Race newRace{};
	Spell newSpell{};
	Trait newTrait{};

	std::string line;
	int counter{};
	bool inRaces{};
	bool inSpells{};
	bool inTraits{};
	bool input{};

	while (std::getline(myfile, line))
	{
		std::istringstream iss(line);
		std::string variable{ line };
		std::string declared{};
		for (char i : line) {
			if (inTraits) {
				if (!isalpha(i) && i != '{' && i != '}') {
					variable.erase(0, 1);
					break;
				}
			}
			else if (!isalpha(i) && i != '}') {
				variable.erase(0, 1);
				break;
			}
			variable.erase(0, 1);
			declared += i;
		}

		if (!inRaces && !inTraits && !inSpells) {

			if (counter == 0) {
				if (line != "{") {
					unsigned first = line.find('\"');
					unsigned last = line.find_last_of('\"');
					std::string lineNew = line.substr(first + 1, last - first - 1);
					Name = lineNew;
				}
				else {
					counter--;
				}
			}
			if (declared == "Races") {
				inRaces = true;
			}
			else if (declared == "Spells") {
				inSpells = true;
			}
		}
		else if (inRaces) {
			if (inTraits) {
				if (declared == "}" && input) {
					input = false;
					newRace.insert_trait(newTrait);
					newTrait.clear();
				}
				else if (declared == "}" && !input) {
					inTraits = false;
				}
				else if (declared == "{name") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_name(variableNew);
					input = true;
				}
				else if (declared == "description") {
					unsigned first = variable.find("\"");
					unsigned last = variable.find_last_of("\"");
					std::string variableNew = variable.substr(first + 1, last - first - 1);
					newTrait.set_description(variableNew);
				}
				else if (declared == "type") {
					switch (std::stoi(variable)) {
					case 0:
						newTrait.set_type(TraitType::Action);
						break;
					case 1:
						newTrait.set_type(TraitType::BAction);
						break;
					case 2:
						newTrait.set_type(TraitType::Reaction);
						break;
					case 3:
						newTrait.set_type(TraitType::Other);
						break;
					}
				}
			}
			else if (declared == "Name") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newRace.set_name(variableNew);
			}
			else if (declared == "OptionPack") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newRace.set_optionPack(variableNew);
			}
			else if (declared == "Description") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newRace.set_description(variableNew);
			}
			else if (declared == "Size") {
				if (variable == "Small") {
					newRace.set_size(SizeEnum::small);
				}
				else if (variable == "Medium") {
					newRace.set_size(SizeEnum::medium);
				}
				else if (variable == "Large") {
					newRace.set_size(SizeEnum::large);
				}
			}
			else if (declared == "Str") {
				newRace.set_str(std::stoi(variable));
			}
			else if (declared == "Dex") {
				newRace.set_dex(std::stoi(variable));
			}
			else if (declared == "Con") {
				newRace.set_con(std::stoi(variable));
			}
			else if (declared == "Int") {
				newRace.set_int(std::stoi(variable));
			}
			else if (declared == "Wis") {
				newRace.set_wis(std::stoi(variable));
			}
			else if (declared == "Cha") {
				newRace.set_cha(std::stoi(variable));
			}
			else if (declared == "Speed") {
				newRace.set_speed(std::stoi(variable));
			}
			else if (declared == "FlySpeed") {
				newRace.set_flySpeed(std::stoi(variable));
			}
			else if (declared == "SwimSpeed") {
				newRace.set_swimSpeed(std::stoi(variable));
			}
			else if (declared == "DarkVision") {
				newRace.set_darkVision(std::stoi(variable));
			}
			else if (declared == "SKOC") {
				newRace.set_skillOptionsCount(std::stoi(variable));
			}
			else if (declared == "LNOC") {
				newRace.set_languageOptionsCount(std::stoi(variable));
			}
			else if (declared == "WPOC") {
				newRace.set_weaponOptionsCount(std::stoi(variable));
			}
			else if (declared == "LizFolkAC") {
				if (variable == "0") {
					newRace.set_lizFolkAC(false);
				}
				else {
					newRace.set_lizFolkAC(true);
				}
			}
			else if (declared == "TortAC") {
				if (variable == "0") {
					newRace.set_tortAC(false);
				}
				else {
					newRace.set_tortAC(true);
				}
			}
			else if (declared == "Languages") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_language(vector);
			}
			else if (declared == "LanguageOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_languageOption(vector);

			}
			else if (declared == "SkillProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_skillProf(vector);

			}
			else if (declared == "SkillOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_skillOption(vector);

			}
			else if (declared == "WeaponProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponProf(vector);

			}
			else if (declared == "WeaponOptions") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_weaponOption(vector);

			}
			else if (declared == "DamageRes") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_damageRes(vector);

			}
			else if (declared == "DamageImmun") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_damageImmun(vector);

			}
			else if (declared == "ArmorProf") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_armorProf(vector);

			}
			else if (declared == "Tools") {
				std::stringstream ssvar(variable);
				std::string segment{};
				std::vector<std::string> vector{};
				while (std::getline(ssvar, segment, '\"'))
				{
					if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
						vector.push_back(segment);
					}
				}
				newRace.insert_tool(vector);
			}
			else if (declared == "Traits") {
				inTraits = true;
			}
			else if (!inTraits && declared == "}") {
				if (newRace.get_name() != "") {
					myRaces.push_back(newRace);
				}
				newRace.clear();
				inRaces = false;
			}
		}
		else if (inSpells) {
			if (declared == "Name") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_name(variableNew);
			}
			else if (declared == "OptionPack") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_optionPack(variableNew);
			}
			else if (declared == "School") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_school(variableNew);
			}
			else if (declared == "Duration") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_duration(variableNew);
			}
			else if (declared == "Component") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_component(variableNew);
			}
			else if (declared == "CastingTime") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_castingTime(variableNew);
			}
			else if (declared == "Range") {
				unsigned first = variable.find("\"");
				unsigned last = variable.find_last_of("\"");
				std::string variableNew = variable.substr(first + 1, last - first - 1);
				newSpell.set_range(variableNew);
			}
			else if (declared == "Level") {
				newSpell.set_level(std::stoi(variable));
			}
			else if (declared == "Verbal") {
				newSpell.set_verbal(HLib::StringToBool(variable));
			}
			else if (declared == "Somatic") {
				newSpell.set_somatic(HLib::StringToBool(variable));
			}
			else if (declared == "Material") {
				newSpell.set_material(HLib::StringToBool(variable));
			}
			else if (declared == "Ritual") {
				newSpell.set_ritual(HLib::StringToBool(variable));
			}
			else if (declared == "AttackRoll") {
				newSpell.set_attackRoll(HLib::StringToBool(variable));
			}
			else if (declared == "}") {
				if (newSpell.get_name() != "") {
					mySpells.push_back(newSpell);
				}
				newSpell.clear();
				inSpells = false;
			}

		}
		counter++;
	}

	set_races(myRaces);
	set_spells(mySpells);
	return *this;
}

Pack Pack::load_orcbrew(std::fstream& myfile) {
	myfile.clear();
	myfile.seekg(0);
	std::vector<Race> myRaces{ Races };
	Race newRace{};
	Trait newTrait{};

	std::string line;
	int counter{};
	bool inGrouping{};
	bool input{};
	std::vector<bool> listmode{};
	bool namemode{ false };
	std::string tempString{};
	std::string inputString{};
	int listSize{};
	int templistSize{};

	while (std::getline(myfile, line)) {
		
	}

	return *this;
}

void Pack::save_pack()
{
	std::ofstream myfile{};
	std::vector<Race> myRaces{ Races };
	std::vector<Spell> mySpells{ Spells };

	if (!std::filesystem::exists("CustomPacks")) {
		std::filesystem::create_directory("CustomPacks");
	}

	myfile.open("CustomPacks/" + Name + ".pck", std::ios::in | std::ios::trunc);

	myfile
		<< "name=\"" << Name
		<< "\"\nRaces{\n";
	for (Race i : Races) {
		myfile
			<< i.get_key() << "{\n"
			<< "Name=\"" << i.get_name()
			<< "\"\nOptionPack=\"" << i.get_optionPack()
			<< "\"\nDescription=\"" << i.get_description()
			<< "\"\nSize=" << i.get_sizename()
			<< "\nStr=" << i.get_str()
			<< "\nDex=" << i.get_dex()
			<< "\nCon=" << i.get_con()
			<< "\nInt=" << i.get_int()
			<< "\nWis=" << i.get_wis()
			<< "\nCha=" << i.get_cha()
			<< "\nSpeed=" << i.get_speed()
			<< "\nFlySpeed=" << i.get_flySpeed()
			<< "\nSwimSpeed=" << i.get_swimSpeed()
			<< "\nDarkVision=" << i.get_darkVision()
			<< "\nSKOC=" << i.get_skillOptionsCount()
			<< "\nLNOC=" << i.get_languageOptionsCount()
			<< "\nWPOC=" << i.get_weaponOptionsCount()
			<< "\nLizFolkAC=" << i.get_lizFolkAC()
			<< "\nTortAC=" << i.get_tortAC();
		myfile
			<< "\nLanguages={";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nLanguageOptions={";
		if (i.get_languageOption().size() > 0) {
			for (std::string k : i.get_languageOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillProf={";
		if (i.get_skillProf().size() > 0) {
			for (std::string k : i.get_skillProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillOptions={";
		if (i.get_skillOption().size() > 0) {
			for (std::string k : i.get_skillOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponProf={";
		if (i.get_weaponProf().size() > 0) {
			for (std::string k : i.get_weaponProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponOptions={";
		if (i.get_weaponOption().size() > 0) {
			for (std::string k : i.get_weaponOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageRes={";
		if (i.get_damageRes().size() > 0) {
			for (std::string k : i.get_damageRes()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageImmun={";
		if (i.get_damageImmun().size() > 0) {
			for (std::string k : i.get_damageImmun()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nArmorProf={";
		if (i.get_armorProf().size() > 0) {
			for (std::string k : i.get_armorProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTools={";
		if (i.get_tool().size() > 0) {
			for (std::string k : i.get_tool()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTraits={";
		if (i.get_trait().size() > 0) {
			for (Trait k : i.get_trait()) {
				myfile
					<< "\n{name=\"" << k.get_name()
					<< "\"\ndescription=\"" << k.get_description()
					<< "\"\ntype=" << k.get_type()
					<< "\n}";
			}
		}
		myfile
			<< "\n}\n}\n";
	}
	myfile
		<< "}\nSpells{\n";
	for (Spell i : Spells) {
		myfile
			<< i.get_key() << "{\n"
			<< "Name=\"" << i.get_name()
			<< "\"\nOptionPack=\"" << i.get_optionPack()
			<< "\"\nDescription=\"" << i.get_description()
			<< "\"\nSchool=\"" << i.get_school()
			<< "\"\nDuration=\"" << i.get_duration()
			<< "\"\nComponent=\"" << i.get_component()
			<< "\"\nCastingTime=\"" << i.get_castingTime()
			<< "\"\nRange=\"" << i.get_range()
			<< "\"\nLevel=" << i.get_level()
			<< std::boolalpha
			<< "\nVerbal=" << i.is_verbal()
			<< "\nSomatic=" << i.is_somatic()
			<< "\nMaterial=" << i.is_material()
			<< "\nRitual=" << i.is_ritual()
			<< "\nAttackRoll=" << i.is_attackRoll()
			<< std::boolalpha;
		myfile
			<< "\nClassList={";
		if (i.get_class().size() > 0) {
			for (std::string k : i.get_class()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}\n";
	}
	myfile
		<< "}\n";

}
void Pack::save_pack(std::ofstream& myfile)
{
	std::vector<Race> myRaces{ Races };
	std::vector<Spell> mySpells{ Spells };

	myfile
		<< "name=\"" << Name
		<< "\"\nRaces{\n";
	for (Race i : Races) {
		myfile
			<< i.get_key() << "{\n"
			<< "Name=\"" << i.get_name()
			<< "\"\nOptionPack=\"" << i.get_optionPack()
			<< "\"\nDescription=\"" << i.get_description()
			<< "\"\nSize=" << i.get_sizename()
			<< "\nStr=" << i.get_str()
			<< "\nDex=" << i.get_dex()
			<< "\nCon=" << i.get_con()
			<< "\nInt=" << i.get_int()
			<< "\nWis=" << i.get_wis()
			<< "\nCha=" << i.get_cha()
			<< "\nSpeed=" << i.get_speed()
			<< "\nFlySpeed=" << i.get_flySpeed()
			<< "\nSwimSpeed=" << i.get_swimSpeed()
			<< "\nDarkVision=" << i.get_darkVision()
			<< "\nSKOC=" << i.get_skillOptionsCount()
			<< "\nLNOC=" << i.get_languageOptionsCount()
			<< "\nWPOC=" << i.get_weaponOptionsCount()
			<< "\nLizFolkAC=" << i.get_lizFolkAC()
			<< "\nTortAC=" << i.get_tortAC();
		myfile
			<< "\nLanguages={";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nLanguageOptions={";
		if (i.get_languageOption().size() > 0) {
			for (std::string k : i.get_languageOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillProf={";
		if (i.get_skillProf().size() > 0) {
			for (std::string k : i.get_skillProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nSkillOptions={";
		if (i.get_skillOption().size() > 0) {
			for (std::string k : i.get_skillOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponProf={";
		if (i.get_weaponProf().size() > 0) {
			for (std::string k : i.get_weaponProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nWeaponOptions={";
		if (i.get_weaponOption().size() > 0) {
			for (std::string k : i.get_weaponOption()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageRes={";
		if (i.get_damageRes().size() > 0) {
			for (std::string k : i.get_damageRes()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nDamageImmun={";
		if (i.get_damageImmun().size() > 0) {
			for (std::string k : i.get_damageImmun()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nArmorProf={";
		if (i.get_armorProf().size() > 0) {
			for (std::string k : i.get_armorProf()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTools={";
		if (i.get_tool().size() > 0) {
			for (std::string k : i.get_tool()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "}";
		myfile
			<< "\nTraits={";
		if (i.get_trait().size() > 0) {
			for (Trait k : i.get_trait()) {
				myfile
					<< "\n{name=\"" << k.get_name()
					<< "\"\ndescription=\"" << k.get_description()
					<< "\"\ntype=" << k.get_type()
					<< "\n}";
			}
		}
		myfile
			<< "\n}\n}\n";
	}
	myfile
		<< "}\nSpells{\n";
	for (Spell i : Spells) {
		myfile
			<< i.get_key() << "{\n"
			<< "Name=\"" << i.get_name()
			<< "\"\nOptionPack=\"" << i.get_optionPack()
			<< "\"\nDescription=\"" << i.get_description()
			<< "\"\nSchool=\"" << i.get_school()
			<< "\"\nDuration=\"" << i.get_duration()
			<< "\"\nComponent=\"" << i.get_component()
			<< "\"\nCastingTime=\"" << i.get_castingTime()
			<< "\"\nRange=\"" << i.get_range()
			<< "\"\nLevel=" << i.get_level()
			<< std::boolalpha
			<< "\nVerbal=" << i.is_verbal()
			<< "\nSomatic=" << i.is_somatic()
			<< "\nMaterial=" << i.is_material()
			<< "\nRitual=" << i.is_ritual()
			<< "\nAttackRoll=" << i.is_attackRoll()
			<< std::boolalpha;
		myfile
			<< "\nClassList={";
		if (i.get_class().size() > 0) {
			for (std::string k : i.get_class()) {
				myfile
					<< "\"" << k << "\"";
			}
		}
		myfile
			<< "\n}";
	}
	myfile
		<< "\n}\n";

}

Pack Pack::merge(std::vector<Pack> Packs)
{
	Pack MergedPack{};
	MergedPack.set_name(get_name());
	std::vector<std::string> allRaces{};
	std::vector<std::string> allSpells{};
	int index{};
	for (Pack i : Packs) {
		for (Race j : i.get_races()) {
			if (std::find(allRaces.begin(), allRaces.end(), j.get_name()) == allRaces.end()) {
				allRaces.push_back(j.get_name());
				j.set_optionPack(MergedPack.get_name());
				MergedPack.set_races(j);
			}
		}
		for (Spell j : i.get_spells()) {
			if (std::find(allSpells.begin(), allSpells.end(), j.get_name()) == allSpells.end()) {
				allSpells.push_back(j.get_name());
				j.set_optionPack(MergedPack.get_name());
				MergedPack.set_spells(j);
			}
		}
	}
	return MergedPack;
}

void Pack::print_pack(bool multi, std::ofstream& outputfile) {
	std::vector<Race> myRaces{ Races };

	if (!std::filesystem::exists("OrcbrewPacks")) {
		std::filesystem::create_directory("OrcbrewPacks");
	}
	if (!multi) {
		outputfile.open("OrcbrewPacks/" + Name + ".orcbrew", std::ios::in | std::ios::trunc);
	}
	outputfile
		<< "\"" << Name
		<< "\"\n{:orcpub.dnd.e5/races\n{\n";

	for (Race i : Races)
	{
		if (i.get_optionPack() != Name) {
			break;
		}
		outputfile
			<< ":" << i.get_key()
			<< "\n{:key :" << i.get_key()
			<< "\n, :name \"" << i.get_name()
			<< "\n\", :swimming-speed " << i.get_swimSpeed()
			<< "\n, :help \"" << i.get_description()
			<< "\n\", :option-pack \"" << i.get_optionPack()
			<< "\n\", :speed " << i.get_speed()
			<< "\n, :flying-speed " << i.get_flySpeed()
			<< "\n, :darkvision " << i.get_darkVision()
			<< std::boolalpha
			<< "\n, :lizardfolk-ac " << i.get_lizFolkAC()
			<< "\n, :tortle-ac " << i.get_tortAC()
			<< std::boolalpha
			<< "\n, :abilities{";
		if (i.get_str() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/str " << i.get_str();
			if (i.get_dex() != 0 || i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				outputfile
					<< ",";
			}
		}
		if (i.get_dex() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/dex " << i.get_dex();
			if (i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				outputfile
					<< ",";
			}
		}
		if (i.get_con() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/con " << i.get_con();
			if (i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				outputfile
					<< ",";
			}
		}
		if (i.get_int() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/int " << i.get_int();
			if (i.get_wis() != 0 || i.get_cha() != 0) {
				outputfile
					<< ",";
			}
		}
		if (i.get_wis() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/wis " << i.get_wis();
			if (i.get_cha() != 0) {
				outputfile
					<< ",";
			}
		}
		if (i.get_cha() != 0) {
			outputfile
				<< "\n :orcpub.dnd.e5.character/cha " << i.get_cha();
		}

		outputfile
			<< "\n},\n :languages \n#{\n";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				outputfile
					<< "\n \"" << k << "\"";
			}
		}
		outputfile
			<< "\n}, \n:profs \n{";
		if (i.get_tool().size() > 0) {
			int counter{};
			outputfile
				<< " \n:tool\n{";
			for (std::string k : i.get_tool()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_tool().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n},\n";
		}
		if (i.get_skillOption().size() > 0) {
			int counter{};
			outputfile
				<< "\n :skill-options \n{\n"
				<< "\n :choose " << i.get_skillOptionsCount()
				<< "\n, :options \n{";
			for (std::string k : i.get_skillOption()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_skillOption().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n}\n},\n";
		}
		if (i.get_languageOption().size() > 0) {
			int counter{};
			std::vector<std::string> languagesOrdered{ "draconic","deep-speech","orc","dwarvish","gnomish","sylvan","elvish","abyssal","infernal","celestial","common","undercommon","primordial","giant","halfling","goblin" };
			std::vector<std::string> newLanguages{ "","","","","","","","","","","","","","","","","","","","", };
			for (std::string k : i.get_languageOption()) {
				std::string newK;
				for (char j : k) {
					if (isalpha(j)) {
						newK += tolower(j);
					}
					else if (j == '-') {
						newK += j;
					}
				}
				int jcounter{};
				for (std::string j : languagesOrdered) {
					if (j == newK) {
						newLanguages.at(jcounter) = newK;
						break;
					}
					jcounter++;
				}
			}
			int index{ 0 };
			for (std::string k : newLanguages) {
				if (k == "") {
					newLanguages.erase(newLanguages.begin() + index);
					index--;
				}
				index++;
			}
			outputfile
				<< "\n :language-options \n{"
				<< "\n :choose " << i.get_languageOptionsCount()
				<< "\n, :options \n{\n";
			for (std::string k : newLanguages) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_languageOption().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "}},";
		}
		if (i.get_weaponOption().size() > 0) {
			int counter{};
			outputfile
				<< "\n :weapon-proficiency-options \n{\n"
				<< "\n :choose " << i.get_weaponOptionsCount()
				<< "\n, :options {";
			for (std::string k : i.get_weaponOption()) {
				outputfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_weaponOption().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n}\n}\n";
		}
		outputfile
			<< "\n},\n :props \n{\n";
		if (i.get_weaponProf().size() > 0) {
			int counter{};
			outputfile
				<< "\n :weaponProf\n{\n";
			for (std::string k : i.get_weaponProf()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_weaponProf().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n},\n";
		}
		if (i.get_armorProf().size() > 0) {
			int counter{};
			outputfile
				<< "\n :armor-prof\n{\n";
			for (std::string k : i.get_armorProf()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_armorProf().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n},\n";
		}
		if (i.get_damageRes().size() > 0) {
			int counter{};
			outputfile
				<< "\n :damage_resistance\n{\n";
			for (std::string k : i.get_damageRes()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_damageRes().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n},\n";
		}
		if (i.get_damageImmun().size() > 0) {
			int counter{};
			outputfile
				<< "\n :damage-immunity\n{\n";
			for (std::string k : i.get_damageImmun()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_damageImmun().size()) {
					outputfile << ",";
				}
			}
			outputfile
				<< "\n},\n";
		}
		if (i.get_skillProf().size() > 0) {
			int counter{};
			outputfile
				<< "\n :skill-prof\n{\n";
			for (std::string k : i.get_skillProf()) {
				outputfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_skillProf().size()) {
					outputfile << ",";
				}
				counter++;
			}
			outputfile
				<< "\n}\n";
		}
		outputfile
			<< "\n},\n :traits \n[\n";
		if (i.get_trait().size() > 0) {
			for (Trait i : i.get_trait()) {
				outputfile
					<< "\n{"
					<< "\n :type :" << i.get_typename()
					<< "\n, :name \"" << i.get_name()
					<< "\n\", :description \"" << i.get_description() << "\""
					<< "\n}\n";
			}
		}
		outputfile
			<< "\n]\n},";

	}
	outputfile
		<< "\n},\n:orcpub.dnd.e5/spells\n{";
	for (Spell i : get_spells()) {
		if (i.get_optionPack() != Name) {
			break;
		}
		outputfile
			<< ":" << i.get_key()
			<< "\n{:key :" << i.get_key()
			<< "\n, :name \"" << i.get_name()
			<< "\n\", :description \"" << i.get_description()
			<< "\n\", :school \"" << i.get_school()
			<< "\n\", :duration \"" << i.get_duration()
			<< "\n\", :range \"" << i.get_range()
			<< "\n\", :casting-time \"" << i.get_castingTime()
			<< "\n\", :option-pack \"" << i.get_optionPack()
			<< "\n\", :level " << i.get_level()
			<< std::boolalpha
			<< "\n, :ritual " << i.is_ritual()
			<< "\n, :attack-roll? " << i.is_attackRoll()
			<< std::boolalpha
			<< "\n, :components{";
		if (i.is_verbal()) {
			outputfile
				<< std::boolalpha
				<< "\n:verbal "
				<< i.is_verbal()
				<< std::boolalpha;
			if (i.is_somatic() || i.is_material() || i.get_component() != "") {
				outputfile
					<< ",\n";
			}
		}
		if (i.is_somatic()) {
			outputfile
				<< std::boolalpha
				<< "\n:somatic "
				<< i.is_somatic()
				<< std::boolalpha;
			if (i.is_material() || i.get_component() != "") {
				outputfile
					<< ",\n";
			}
		}
		if (i.is_material()) {
			outputfile
				<< std::boolalpha
				<< "\n:material "
				<< i.is_material()
				<< std::boolalpha;
			if (i.get_component() != "") {
				outputfile
					<< ",\n";
			}
		}
		if (i.get_component() != "") {
			outputfile
				<<"\n:material-component \"" << i.get_component() << "\"";
		}
		outputfile
			<< "\n},:spell-lists{";
		if (i.get_class().size() > 0) {
			for (std::string k : i.get_class()) {
				outputfile
					<< "\n :" << k << " true,";
			}
		}
		outputfile
			<< "\n}\n},\n";
	}

	if (!multi) {
		outputfile
			<< "\n}\n}\n}";

		outputfile.close();

		std::cout << std::endl << "File printed" << std::endl;
	}
	else {
		outputfile
			<< "\n},\n";
	}
}
void Pack::print_pack()
{
	std::ofstream myfile{};
	std::vector<Race> myRaces{Races};

	if (!std::filesystem::exists("OrcbrewPacks")) {
		std::filesystem::create_directory("OrcbrewPacks");
	}
	
	myfile.open("OrcbrewPacks/" + Name + ".orcbrew", std::ios::in | std::ios::trunc);
	
	myfile
		<< "{\"" << Name
		<< "\"\n{:orcpub.dnd.e5/races\n{\n";

	for (Race i : Races) 
	{
		if (i.get_optionPack() != Name) {
			break;
		}
		myfile
			<< ":" << i.get_key()
			<< "\n{:key :" << i.get_key()
			<< "\n, :name \"" << i.get_name()
			<< "\n\", :swimming-speed " << i.get_swimSpeed()
			<< "\n, :help \"" << i.get_description()
			<< "\n\", :option-pack \"" << i.get_optionPack()
			<< "\n\", :speed " << i.get_speed()
			<< "\n, :flying-speed " << i.get_flySpeed()
			<< "\n, :darkvision " << i.get_darkVision()
			<< std::boolalpha
			<< "\n, :lizardfolk-ac " << i.get_lizFolkAC()
			<< "\n, :tortle-ac " << i.get_tortAC()
			<< std::boolalpha
			<< "\n, :abilities{";
		if (i.get_str() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/str " << i.get_str();
			if (i.get_dex() != 0 || i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_dex() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/dex " << i.get_dex();
			if (i.get_con() != 0 || i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_con() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/con " << i.get_con();
			if (i.get_int() != 0 || i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_int() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/int " << i.get_int();
			if (i.get_wis() != 0 || i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_wis() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/wis " << i.get_wis();
			if (i.get_cha() != 0) {
				myfile
					<< ",";
			}
		}
		if (i.get_cha() != 0) {
			myfile
				<< "\n :orcpub.dnd.e5.character/cha " << i.get_cha();
		}

		myfile
			<< "\n},\n :languages \n#{\n";
		if (i.get_language().size() > 0) {
			for (std::string k : i.get_language()) {
				myfile
					<< "\n \"" << k << "\"";
			}
		}
		myfile
			<< "\n}, \n:profs \n{";
		if (i.get_tool().size() > 0) {
			int counter{};
			myfile
				<< " \n:tool\n{";
			for (std::string k : i.get_tool()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_tool().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n},\n";
		}
		if (i.get_skillOption().size() > 0) {
			int counter{};
			myfile
				<< "\n :skill-options \n{\n"
				<< "\n :choose " << i.get_skillOptionsCount()
				<< "\n, :options \n{";
			for (std::string k : i.get_skillOption()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_skillOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n}\n},\n";
		}
		if (i.get_languageOption().size() > 0) {
			int counter{};
			std::vector<std::string> languagesOrdered{"draconic","deep-speech","orc","dwarvish","gnomish","sylvan","elvish","abyssal","infernal","celestial","common","undercommon","primordial","giant","halfling","goblin"};
			std::vector<std::string> newLanguages{"","","","","","","","","","","","","","","","","","","","",};
			for (std::string k : i.get_languageOption()) {
				std::string newK;
				for (char j : k) {
					if (isalpha(j)) {
						newK += tolower(j);
					}
					else if(j == '-') {
						newK += j;
					}
				}
				int jcounter{};
				for (std::string j : languagesOrdered) {
					if (j == newK) {
						newLanguages.at(jcounter) = newK;
						break;
					}
					jcounter++;
				}
			}
			int index{0};
			for (std::string k : newLanguages) {
				if (k == "") {
					newLanguages.erase(newLanguages.begin() + index);
					index--;
				}
				index++;
			}
			myfile
				<< "\n :language-options \n{"
				<< "\n :choose " << i.get_languageOptionsCount()
				<< "\n, :options \n{\n";
			for (std::string k : newLanguages) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_languageOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "}},";
		}
		if (i.get_weaponOption().size() > 0) {
			int counter{};
			myfile
				<< "\n :weapon-proficiency-options \n{\n"
				<< "\n :choose " << i.get_weaponOptionsCount()
				<< "\n, :options {";
			for (std::string k : i.get_weaponOption()) {
				myfile
					<< " :" << k << " true";
				if (counter + 1 != i.get_weaponOption().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n}\n}\n";
		}
		myfile
			<< "\n},\n :props \n{\n";
		if (i.get_weaponProf().size() > 0) {
			int counter{};
			myfile
				<< "\n :weaponProf\n{\n";
			for (std::string k : i.get_weaponProf()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_weaponProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n},\n";
		}
		if (i.get_armorProf().size() > 0) {
			int counter{};
			myfile
				<< "\n :armor-prof\n{\n";
			for (std::string k : i.get_armorProf()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_armorProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n},\n";
		}
		if (i.get_damageRes().size() > 0) {
			int counter{};
			myfile
				<< "\n :damage_resistance\n{\n";
			for (std::string k : i.get_damageRes()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_damageRes().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n},\n";
		}
		if (i.get_damageImmun().size() > 0) {
			int counter{};
			myfile
				<< "\n :damage-immunity\n{\n";
			for (std::string k : i.get_damageImmun()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_damageImmun().size()) {
					myfile << ",";
				}
			}
			myfile
				<< "\n},\n";
		}
		if (i.get_skillProf().size() > 0) {
			int counter{};
			myfile
				<< "\n :skill-prof\n{\n";
			for (std::string k : i.get_skillProf()) {
				myfile
					<< "\n :" << k << " true";
				if (counter + 1 != i.get_skillProf().size()) {
					myfile << ",";
				}
				counter++;
			}
			myfile
				<< "\n}\n";
		}
		myfile
			<< "\n},\n :traits \n[\n";
		if (i.get_trait().size() > 0) {
			for (Trait i : i.get_trait()) {
				myfile
					<< "\n{"
					<< "\n :type :" << i.get_typename()
					<< "\n, :name \"" << i.get_name()
					<< "\n\", :description \"" << i.get_description() << "\""
					<< "\n}\n";
			}
		}
		myfile
			<< "\n]\n}";

	}
		myfile
			<< "\n}\n}\n}";

		myfile.close();

		std::cout << std::endl << "File printed" << std::endl;
}
