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
#include "Race.h"
#include "GUI.h"
#include "harmonylib.h"
#include "Pack.h"
#include "HPack.h"
#include "emptytest.h"

class Orcbrew
{
private:
	std::string Name{};
	std::vector<Pack> Packs{};

public:
	Orcbrew();

	std::vector<Pack> merge(std::vector<std::vector<Pack>> PackSet);
	Orcbrew merge(std::vector<Orcbrew> OrcbrewPack);

	void set_packs(std::vector<Pack> packs);

	Pack add_to_pack(Pack inPack, std::string command, std::string input, std::string packPart, std::string objectName);
	Pack add_to_pack(Pack inPack, std::string command, std::vector<std::string> input, std::string packPart, std::string objectName);

	HPack load(std::string fileName);
	void save();
	//HPack convert_pack_file();

};

