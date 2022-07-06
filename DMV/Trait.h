#pragma once
#include <string>
#include <iostream>
#include "harmonylib.h"
#include "TraitType.h"
class Trait
{
private:
	std::string Name{};
	std::string Description{};
	TraitType::Type Type{};
public:
	Trait();
	Trait(std::string);

	std::string get_name();
	std::string get_description();
	std::string get_typename();
	TraitType::Type get_type();

	void set_name(std::string);
	void set_description(std::string);
	void set_type(TraitType::Type);

	Trait create_trait(std::string name = "", std::string description = "", std::string type = "");
};

