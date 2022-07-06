#include "Trait.h"


Trait::Trait()
{
	Name = "";
	Description = "";
	Type = TraitType::Other;
}
Trait::Trait(std::string name)
{
	Name = name;
	Description = "";
	Type = TraitType::Other;
}
std::string Trait::get_name()
{
	return Name;
}
std::string Trait::get_description()
{
	return Description;
}
std::string Trait::get_typename()
{
	switch (this->get_type()) {
	case TraitType::Action:
		return "action";
	case TraitType::BAction:
		return "bonus action";
	case TraitType::Reaction:
		return "reaction";
	case TraitType::Other:
		return "other";
	}
}
TraitType::Type Trait::get_type()
{
	return Type;
}

//Assignment
void Trait::set_name(std::string name)
{
	Name = name;
}
void Trait::set_description(std::string description)
{
	Description = description;
}
void Trait::set_type(TraitType::Type type)
{
	Type = type;
}

Trait Trait::create_trait(std::string name, std::string description, std::string type)
{
	Trait newTrait{};
	if (name == "") {
		std::cout << "\nEnter name of trait/feat: ";
		std::getline(std::cin, name);
		name = HLib::InputCheck(name, "Enter name of trait/feat: ");
	}
	newTrait.set_name(name);

	if (description == "") {
		std::cout << "\nEnter Description:\n";
		std::getline(std::cin, description);
	}
	newTrait.set_description(description);

	if (type == "") {
		std::cout << "\nEnter type (Action, Bonus Action, Reaction, Other): ";
		std::getline(std::cin, type);
		type = HLib::InputCheck(type, "Enter type (Action, Bonus Action, Reaction, Other): ", true, false, std::vector<std::string>{"action", "bonus action", "reaction", "other"});
	}
	if (type == "action") {
		newTrait.set_type(TraitType::Action);
	}
	else if (type == "bonus action") {
		newTrait.set_type(TraitType::BAction);
	}
	else if (type == "reaction") {
		newTrait.set_type(TraitType::Reaction);
	}
	else {
		newTrait.set_type(TraitType::Other);
	}

	return newTrait;
}
