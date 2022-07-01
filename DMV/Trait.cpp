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
