#include "Spell.h"

Spell::Spell()
{
	this->ClassList = {};
	this->Key = "";
	this->Name = "";
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}
Spell::Spell(std::string name)
{
	this->set_name(name);
	this->ClassList = {};
	this->set_name(name);
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}

//Gets
std::string Spell::get_key()
{
	return this->Key;
}
std::string Spell::get_name()
{
	return this->Name;
}
std::string Spell::get_description()
{
	return this->Description;
}
std::string Spell::get_school()
{
	return this->School;
}
std::string Spell::get_duration()
{
	return this->Duration;
}
std::string Spell::get_optionPack()
{
	return this->OptionPack;
}
std::string Spell::get_component()
{
	return this->Component;
}
std::string Spell::get_castingTime()
{
	return this->CastingTime;
}
int Spell::get_level()
{
	return this->Level;
}
bool Spell::is_verbal()
{
	return this->Verbal;
}
bool Spell::is_somatic()
{
	return this->Somatic;
}
bool Spell::is_material()
{
	return this->Material;
}
bool Spell::is_ritual()
{
	return this->Ritual;
}
bool Spell::is_attackRoll()
{
	return this->AttackRoll;
}
bool Spell::has_class(std::string Class)
{
	for (std::string i : this->ClassList) {
		if (i == Class) {
			return true;
		}
	}
	return false;
}
std::string Spell::get_class(int index)
{
	int Index{};
	for (std::string i : this->ClassList) {
		if (Index == index) {
			return i;
		}
		Index++;
	}
	return "";
}
std::vector<std::string> Spell::get_class()
{
	return this->ClassList;
}


//Assignment
void Spell::set_key(std::string key)
{
	this->Key = key;
}
void Spell::set_name(std::string input)
{
	std::string newString{};
	this->Name = input;
	for (char i : input) {
		if (i == ' ') {
			newString.push_back('-');
		}
		else if (isalpha(i)) {
			newString.push_back(tolower(i));
		}
		else {
			newString.push_back(i);
		}
	}
	this->set_key(newString);
}
void Spell::set_description(std::string input)
{
	this->Description = input;
}
void Spell::set_school(std::string input)
{
	this->School = input;
}
void Spell::set_duration(std::string input)
{
	this->Duration = input;
}
void Spell::set_optionPack(std::string input)
{
	this->OptionPack = input;
}
void Spell::set_component(std::string input)
{
	this->Component = input;
}
void Spell::set_castingTime(std::string input)
{
	this->CastingTime = input;
}
void Spell::set_level(int input)
{
	this->Level = input;
}
void Spell::set_verbal(bool input)
{
	this->Verbal = input;
}
void Spell::set_somatic(bool input)
{
	this->Somatic = input;
}
void Spell::set_material(bool input)
{
	this->Material = input;
}
void Spell::set_ritual(bool input)
{
	this->Ritual = input;
}
void Spell::set_attackRoll(bool input)
{
	this->AttackRoll = input;
}
void Spell::set_classes(std::vector<std::string> input)
{
	this->ClassList = input;
}
void Spell::insert_class(std::string input)
{
	this->ClassList.push_back(input);
}
void Spell::remove_class(std::string input)
{
	std::vector<std::string> newClassList{};
	for (std::string i : this->ClassList) {
		if (i != input) {
			newClassList.push_back(i);
		}
	}
	this->ClassList = newClassList;
}
void Spell::remove_class(int index)
{
	int Index{};
	std::vector<std::string> newClassList{};
	for (std::string i : this->ClassList) {
		if (Index != index) {
			newClassList.push_back(i);
		}
		Index++;
	}
	this->ClassList = newClassList;
}

//Clear
void Spell::clear()
{
	this->ClassList = {};
	this->Key = "";
	this->Name = "";
	this->Description = "";
	this->School = "";
	this->Duration = "";
	this->OptionPack = "";
	this->Component = "";
	this->CastingTime = "";
	this->Level = 0;
	this->Verbal = false;
	this->Somatic = false;
	this->Material = false;
	this->Ritual = false;
	this->AttackRoll = false;
}
