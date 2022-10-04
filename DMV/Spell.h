#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "GUI.h"
#include "Console.h"
#include "CommandObject.h"

class Spell :
	public CommandObject
{

private:
	std::vector<std::string> ClassList{};
	std::string Key{};
	std::string Name{};
	std::string Description{};
	std::string School{};
	std::string Duration{};
	std::string OptionPack{};
	std::string Component{};
	std::string CastingTime{};
	std::string Range{};
	int Level{};
	bool Verbal{};
	bool Somatic{};
	bool Material{};
	bool Ritual{};
	bool AttackRoll{};

	Console SpellConsole{};

	std::string Title{ "Spell" };
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
		"Finishes Spell",
		"Get help on command",
		"Cancels current action",
		"Add an aspect of spell",
		"Edit aspect",
		"Clears spell",
		"Remove element"
	};
	std::vector<std::string> GlobalSpellOptions{
		"name",
		"option-pack",
		"description",
		"school",
		"duration",
		"component",
		"casting-time",
		"level",
		"verbal",
		"somatic",
		"material",
		"ritual",
		"attack-roll",
		"classes",
		"range"
	};
	std::vector<std::string> GlobalSpellDefs{
		"The name of your Spell",
		"The name of the pack your spell is in",
		"The Description of your spell",
		"The school of magic your spell is under",
		"The duration of the spell",
		"Components needed to case spell",
		"How long it takes to cast",
		"Level of spell, 0 is cantrip",
		"Veberal spell",
		"Somatic spell",
		"Material Spell",
		"Ritual Spell",
		"If spell is an attack roll",
		"The classes that can use the spell",
		"The range of the spell"
	};

public:
	//Construction
	Spell();
	Spell(std::string name);

	//Gets
	std::string get_key();
	std::string get_name();
	std::string get_description();
	std::string get_school();
	std::string get_duration();
	std::string get_optionPack();
	std::string get_component();
	std::string get_castingTime();
	std::string get_range();
	int get_level();
	bool is_verbal();
	bool is_somatic();
	bool is_material();
	bool is_ritual();
	bool is_attackRoll();
	bool has_class(std::string Class);
	std::string get_class(int index);
	std::vector<std::string> get_class();

	//Sets
	void set_key(std::string input);
	void set_name(std::string input);
	void set_description(std::string input);
	void set_school(std::string input);
	void set_duration(std::string input);
	void set_optionPack(std::string input);
	void set_component(std::string input);
	void set_castingTime(std::string input);
	void set_range(std::string input);
	void set_level(int input);
	void set_verbal(bool input);
	void set_somatic(bool input);
	void set_material(bool input);
	void set_ritual(bool input);
	void set_attackRoll(bool input);
	void set_classes(std::vector<std::string> input);
	void insert_class(std::string input);
	void remove_class(std::string input);
	void remove_class(int index);

	void print(std::ofstream& myfile);

	void load(std::string& declared, bool& inObject, std::string& variable, Spell& newSpell, std::vector<Spell>& mySpells, bool& inSpells);

	//Clear
	void clear();

	CommandObject* Add(CommandObject* currentSpell, std::vector<std::string>& parameters);

	CommandObject* Edit(CommandObject* currentSpell, std::vector<std::string>& parameters);

	CommandObject* Remove(CommandObject* currentSpell, std::vector<std::string>& parameters);

	//Virtual Overrides
	CommandObject* ExecuteCommand(int cmdCode, CommandObject* object, std::vector<std::string> parameters = {}, std::string context = {});
	void Display();
	std::string get_title();
	bool IsDone(std::string input);
	std::vector<std::string> get_commands();
	std::vector<std::string> get_command_defs();
};