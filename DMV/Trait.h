#pragma once
#include <string>
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
	TraitType::Type get_type();

	void set_name(std::string);
	void set_description(std::string);
	void set_type(TraitType::Type);
};

