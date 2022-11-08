#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include "TraitType.h"
#include "SizeEnum.h"
#include "Spell.h"
#include "Trait.h"
#include "GUI.h"
#include "harmonylib.h"
#include "Pack.h"
#include "Orcbrew.h"
#include "CommandObject.h"

class HPack :
	public CommandObject
{
private:
	std::string Name{};
	std::vector<Pack> Packs{};

	Console HPackConsole{};
	std::string Title{ "Menu" };
	std::string DoneVariable{};
	std::vector<std::string> Commands{
		"exit",
		"help",
		"display",
		"add",
		"load",
		"save",
		"export",
		"name",
		"edit"
	};
	std::vector<std::string> CommandDefs{
		"Closes the program",
		"Displays Commands",
		"Displays stuff",
		"Add to pack",
		"Load from a file",
		"Save to a file",
		"Export to Orcbrew",
		"Rename Packs",
		"Edit an item"
	};


public:
	HPack();
	HPack(std::string name);

	std::vector<Pack> get_packs();
	Pack get_pack(std::string name);
	std::string get_name();

	void set_name(std::string name);
	void set_packs(std::vector<Pack> packs);
	void set_pack_name(std::string packName, std::string newName);
	void update_pack(Pack pack);
	void add_pack(Pack pack);

	bool has_pack(Pack inputPack);

	std::vector<Pack> merge(std::vector<std::vector<Pack>> PackSet);
	CommandObject* merge(std::vector<HPack> HPackPack);

	void load(std::string fileName);
	void save();

	void GrabObjectName(std::vector<std::string>& parameters, CommandObject*& currentHPack, std::string& objectName, std::string& displayType, Pack& loadedPack);

	CommandObject* ObjectDisplay(CommandObject* currentHPack, std::vector<std::string> parameters);

	CommandObject* Load(CommandObject* currentHPack, std::vector<std::string> parameters);

	CommandObject* Save(CommandObject* currentHPack, std::vector<std::string> parameters);

	CommandObject* Edit(CommandObject* currentHPack, std::vector<std::string> parameters);

	CommandObject* Add(CommandObject* currentHPack, std::vector<std::string> parameters);

	//Virtual Overrides
	CommandObject* ExecuteCommand(int cmdCode, CommandObject* currentHPack, std::vector<std::string> parameters = {}, std::string context = {});
	void Display();
	std::string get_title();
	bool IsDone(std::string input);
	std::vector<std::string> get_commands();
	std::vector<std::string> get_command_defs();

};

