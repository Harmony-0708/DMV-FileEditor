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

class Orcbrew
{
private:
	std::string Name{"Tester"};
	std::vector<Pack> Packs{};

public:
	std::vector<Pack> merge(std::vector<std::vector<Pack>> PackSet);
	Orcbrew merge(std::vector<Orcbrew> OrcbrewPack);

	void set_packs(std::vector<Pack> packs);

	void load(std::string fileName);
	void save();
	//HPack convert_pack_file();

};

