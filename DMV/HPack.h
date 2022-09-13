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
#include "CommandObject.h"

class HPack :
	public CommandObject
{
private:
	std::string Name{};
	std::vector<Pack> Packs{};

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
	HPack merge(std::vector<HPack> HPackPack);

	void load(std::string fileName);
	void save();

	//Virtual Overrides
	CommandObject* ExecuteCommand(int cmdCode, CommandObject* object, std::vector<std::string> parameters = {}, std::string context = {});
	void Display();
	std::string get_title();
	bool IsDone(std::string input);
	std::vector<std::string> get_commands();
	std::vector<std::string> get_command_defs();

};

