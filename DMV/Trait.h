#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include "TraitType.h"
#include "harmonylib.h"
#include "CommandObject.h"

class Trait :
	public CommandObject
{
private:
	std::string Name{};
	std::string Description{};
	TraitType::Type Type{};
public:
	Trait();
	Trait(std::string);

	void clear();

	std::string get_name();
	std::string get_description();
	std::string get_typename();
	TraitType::Type get_type();

	void set_name(std::string);
	void set_description(std::string);
	void set_type(TraitType::Type);

	Trait create_trait(std::string name = "", std::string description = "", std::string type = "");

	//Virtual Overrides
	CommandObject* ExecuteCommand(int cmdCode, CommandObject* object, std::vector<std::string> parameters = {}, std::string context = {});
	void Display();
	std::string get_title();
	bool IsDone(std::string input);
	std::vector<std::string> get_commands();
	std::vector<std::string> get_command_defs();
};

