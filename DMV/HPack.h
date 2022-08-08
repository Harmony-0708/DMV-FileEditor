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

class HPack
{
private:
	std::string Name{};
	std::vector<Pack> Packs{};

public:
	HPack();
	HPack(std::string name);

	std::vector<Pack> get_packs();
	std::string get_name();

	void set_name(std::string name);
	void set_packs(std::vector<Pack> packs);
	void set_pack_name(std::string packName, std::string newName);
	void add_pack(Pack pack);

	std::vector<Pack> merge(std::vector<std::vector<Pack>> PackSet);
	HPack merge(std::vector<HPack> HPackPack);

	void load(std::string fileName);
	void save();
	//Orcbrew convert_pack_file();

};

