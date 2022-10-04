#include "Race.h"
Race::Race()
{
	Key = "";
	Name = "";
	OptionPack = "";
	Description = "";
	Size = SizeEnum::small;
	Speed = 30;
	FlyingSpd = 0;
	SwimmingSpd = 0;
	DarkVision = 0;
	SkillOptionsCount = 1;
	LanguageOptionsCount = 1;
	WeaponOptionsCount = 1;
	LizFolkAC = false;
	TortAC = false;
}
Race::Race(std::string name)
{
	//Key = "";
	std::string newKey{};
	for (char i : name){
		if (isalpha(i)) {
			newKey += tolower(i);
		}
	}
	Key = newKey;
	Name = name;
	OptionPack = "";
	Description = "";
	Size = SizeEnum::small;
	Speed = 30;
	FlyingSpd = 0;
	SwimmingSpd = 0;
	DarkVision = 0;
	SkillOptionsCount = 1;
	LanguageOptionsCount = 1;
	WeaponOptionsCount = 1;
	LizFolkAC = false;
	TortAC = false;
}

void Race::clear()
{
	Key = "";
	Name = "";
	OptionPack = "";
	Description = "";
	Size = SizeEnum::small;
	Speed = 30;
	FlyingSpd = 0;
	SwimmingSpd = 0;
	DarkVision = 0;
	SkillOptionsCount = 1;
	LanguageOptionsCount = 1;
	WeaponOptionsCount = 1;
	LizFolkAC = false;
	TortAC = false;
	Languages.clear();
	Tools.clear();
	SkillOptions.clear();
	SkillProf.clear();
	LanguageOptions.clear();
	WeaponOptions.clear();
	WeaponProf.clear();
	ArmorProf.clear();
	DamageRes.clear();
	DamageImmun.clear();
	Traits.clear();
}

void Race::DisplayVector(int wrapLimit, std::vector<Spell> inputVector)
{
	std::string stringOfVector{};
	for (Spell i : inputVector) {
		if (i.get_key() == inputVector.back().get_key()) {
			stringOfVector += i.get_key() + "\n";
		}
		else {
			stringOfVector += i.get_key() + ", ";
		}
	}
	HLib::WordWrap(wrapLimit, stringOfVector);
}
void Race::DisplayVector(int wrapLimit, std::vector<Trait> inputVector)
{
	std::string outputString{};
	for (Trait i : inputVector) {
		std::string name{i.get_name()};
		std::string desc{i.get_description()};
		std::string type{i.get_typename()};
		outputString += "\n" + name + " (" + type + ")\n\n" + desc + "\n";
	}
	HLib::WordWrap(wrapLimit, outputString);
}

std::string Race::get_key()
{
	return Key;
}
std::string Race::get_name()
{
	return Name;
}
std::string Race::get_optionPack()
{
	return OptionPack;
}
std::string Race::get_description()
{
	return Description;
}
SizeEnum::Size Race::get_size()
{
	return Size;
}
std::string Race::get_sizename()
{
	switch (this->get_size()) {
	case SizeEnum::small:
		return "Small";
	case SizeEnum::medium:
		return "Medium";
	case SizeEnum::large:
		return "Large";
	}
}
int Race::get_str()
{
	return Str;
}
int Race::get_dex()
{
	return Dex;
}
int Race::get_con()
{
	return Con;
}
int Race::get_int()
{
	return Int;
}
int Race::get_wis()
{
	return Wis;
}
int Race::get_cha()
{
	return Cha;
}
int Race::get_speed()
{
	return Speed;
}
int Race::get_flySpeed()
{
	return FlyingSpd;
}
int Race::get_swimSpeed()
{
	return SwimmingSpd;
}
int Race::get_darkVision()
{
	return DarkVision;
}
int Race::get_skillOptionsCount()
{
	return SkillOptionsCount;
}
int Race::get_languageOptionsCount()
{
	return LanguageOptionsCount;
}
int Race::get_weaponOptionsCount()
{
	return WeaponOptionsCount;
}
bool Race::get_lizFolkAC()
{
	return LizFolkAC;
}
bool Race::get_tortAC()
{
	return TortAC;
}
std::string Race::get_language(int index)
{
	if (index < Languages.size()) {
		return "";
	}
	else {
		return Languages[index];
	}
}
std::vector<std::string> Race::get_language()
{
	return Languages;
}
std::string Race::get_tool(int index)
{
	if (index < Tools.size()) {
		return "";
	}
	else {
		return Tools[index];
	}
}
std::vector<std::string> Race::get_tool()
{
	return Tools;
}
std::string Race::get_skillOption(int index)
{
	if (index < SkillOptions.size()) {
		return "";
	}
	else {
		return SkillOptions[index];
	}
}
std::vector<std::string> Race::get_skillOption()
{
	return SkillOptions;
}
std::string Race::get_skillProf(int index)
{
	if (index < SkillProf.size()) {
		return "";
	}
	else {
		return SkillProf[index];
	}
}
std::vector<std::string> Race::get_skillProf()
{
	return SkillProf;
}
std::string Race::get_languageOption(int index)
{
	if (index < LanguageOptions.size()) {
		return "";
	}
	else {
		return LanguageOptions[index];
	}
}
std::vector<std::string> Race::get_languageOption()
{
	return LanguageOptions;
}
std::string Race::get_weaponOption(int index)
{
	if (index < WeaponOptions.size()) {
		return "";
	}
	else {
		return WeaponOptions[index];
	}
}
std::vector<std::string> Race::get_weaponOption()
{
	return WeaponOptions;
}
std::string Race::get_weaponProf(int index)
{
	if (index < WeaponProf.size()) {
		return "";
	}
	else {
		return WeaponProf[index];
	}
}
std::vector<std::string> Race::get_weaponProf()
{
	return WeaponProf;
}
std::string Race::get_armorProf(int index)
{
	if (index < ArmorProf.size()) {
		return "";
	}
	else {
		return ArmorProf[index];
	}
}
std::vector<std::string> Race::get_armorProf()
{
	return ArmorProf;
}
std::string Race::get_damageRes(int index)
{
	if (index < DamageRes.size()) {
		return "";
	}
	else {
		return DamageRes[index];
	}
}
std::vector<std::string> Race::get_damageRes()
{
	return DamageRes;
}
std::string Race::get_damageImmun(int index)
{
	if (index < DamageImmun.size()) {
		return "";
	}
	else {
		return DamageImmun[index];
	}
}
std::vector<std::string> Race::get_damageImmun()
{
	return DamageImmun;
}
Trait Race::get_trait(int index)
{
	if (index < Traits.size()) {
		Trait emptyTrait{ "empty" };
		return emptyTrait;
	}
	else {
		return Traits[index];
	}
}
std::vector<Trait> Race::get_trait()
{
	return Traits;
}
Spell Race::get_spell(int index,std::string spellName)
{
	if (index < Spells.size()) {
		Spell emptySpell{ "empty" };
		return emptySpell;
	}
	else {
		for (Spell i : Spells[index]) {
			if (i.get_key() == spellName) {
				return i;
			}
		}
	}
}
std::vector<std::vector<Spell>> Race::get_spell()
{
	return Spells;
}

//Assign Functions
/// <summary>
/// Sets new key for race
/// </summary>
/// <param name="key">- The new key</param>
void Race::set_key(std::string key)
{
	Key = key;
}
/// <summary>
/// Sets new name for race
/// </summary>
/// <param name="name">- The new name</param>
void Race::set_name(std::string name)
{
	Name = name;
	std::string newKey{};
	for (char i : name) {
		if (isalpha(i)) {
			newKey += tolower(i);
		}
	}
	Key = newKey;
}
/// <summary>
/// Sets new Options Pack for race
/// </summary>
/// <param name="optionPack">- The new options pack</param>
void Race::set_optionPack(std::string optionPack)
{
	OptionPack = optionPack;
}
/// <summary>
/// Sets new description for race
/// </summary>
/// <param name="description">- The new description</param>
void Race::set_description(std::string description)
{
	Description = description;
}
/// <summary>
/// Sets new size for race
/// </summary>
/// <param name="size">- The new size</param>
void Race::set_size(SizeEnum::Size size)
{
	Size = size;
}
void Race::set_str(int str)
{
	Str = str;
}
void Race::set_dex(int dex)
{
	Dex = dex;
}
void Race::set_con(int con)
{
	Con = con;
}
void Race::set_int(int Inte)
{
	Int = Inte;
}
void Race::set_wis(int wis)
{
	Wis = wis;
}
void Race::set_cha(int cha)
{
	Cha = cha;
}
/// <summary>
/// Sets new speed for race.
/// </summary>
/// <param name="speed">- The new speed, must be between 0 and 50</param>
void Race::set_speed(int speed)
{
	if (speed < 0) {
		speed = 0;
	}
	else if (speed > 50) {
		speed = 50;
	}
	Speed = speed;
}
/// <summary>
/// Sets new flying speed for race.
/// </summary>
/// <param name="flyspeed">- The new flyspeed, must be between 0 and 50</param>
void Race::set_flySpeed(int flyspeed)
{
	if (flyspeed < 0) {
		flyspeed = 0;
	}
	else if (flyspeed > 50) {
		flyspeed = 50;
	}
	FlyingSpd = flyspeed;
}
/// <summary>
/// Sets new swimming speed for race.
/// </summary>
/// <param name="swimspeed">- The new swimspeed, must be between 0 and 50</param>
void Race::set_swimSpeed(int swimspeed)
{
	if (swimspeed < 0) {
		swimspeed = 0;
	}
	else if (swimspeed > 50) {
		swimspeed = 50;
	}
	SwimmingSpd = swimspeed;
}
/// <summary>
/// Sets new Dark Vision distance for race
/// </summary>
/// <param name="darkVision">- The new dark vision, must be between 0 and 120</param>
void Race::set_darkVision(int darkVision)
{
	if (darkVision < 0) {
		darkVision = 0;
	}
	else if (darkVision > 120) {
		darkVision = 120;
	}
	DarkVision = darkVision;
}
/// <summary>
/// Sets new amount of skill options.
/// </summary>
/// <param name="skillOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_skillOptionsCount(int skillOptionsCount)
{
	if (skillOptionsCount < 0) {
		skillOptionsCount = 0;
	}
	else if (skillOptionsCount > 5) {
		skillOptionsCount = 5;
	}
	SkillOptionsCount = skillOptionsCount;
}
/// <summary>
/// Sets new amount of language options.
/// </summary>
/// <param name="languageOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_languageOptionsCount(int languageOptionsCount)
{
	if (languageOptionsCount < 0) {
		languageOptionsCount = 0;
	}
	else if (languageOptionsCount > 5) {
		languageOptionsCount = 5;
	}
	LanguageOptionsCount = languageOptionsCount;
}
/// <summary>
/// Sets new amount of weapon options.
/// </summary>
/// <param name="weaponOptionsCount">- The new amount for options, must be between 1 and 5</param>
void Race::set_weaponOptionsCount(int weaponOptionsCount)
{
	if (weaponOptionsCount < 0) {
		weaponOptionsCount = 0;
	}
	else if (weaponOptionsCount > 5) {
		weaponOptionsCount = 5;
	}
	WeaponOptionsCount = weaponOptionsCount;
}
/// <summary>
/// Sets whether using lizard folk AC
/// </summary>
/// <param name="lizAC">- </param>
void Race::set_lizFolkAC(bool lizAC)
{
	LizFolkAC = lizAC;
}
/// <summary>
/// Sets whether using tortle folk AC
/// </summary>
/// <param name="tortAC">- </param>
void Race::set_tortAC(bool tortAC)
{
	TortAC = tortAC;
}
/// <summary>
/// Inserts a single language into the race
/// </summary>
/// <param name="language">- Language to be passed in</param>
void Race::insert_language(std::string language)
{
	Languages.push_back(language);
}
/// <summary>
/// Sets languages to new set of languages
/// </summary>
/// <param name="languages">- The new languages to be passed in</param>
void Race::insert_language(std::vector<std::string> languages)
{
	Languages = languages;
}
/// <summary>
/// Inserts a single tool into the race
/// </summary>
/// <param name="language">- Tool to be passed in</param>
void Race::insert_tool(std::string tool)
{
	Tools.push_back(tool);
}
/// <summary>
/// Sets tools to new set of tools
/// <param name="tools">- The new tools to be passed in</param>
void Race::insert_tool(std::vector<std::string> tools)
{
	Tools = tools;
}
/// <summary>
/// Inserts a single skill option into the race
/// </summary>
/// <param name="skillOption">- Skill option to be passed in</param>
void Race::insert_skillOption(std::string skillOption)
{
	SkillOptions.push_back(skillOption);
}
/// <summary>
/// Sets skill options to new set of skill options
/// </summary>
/// <param name="skillOptions">- The new skill options to be passed in</param>
void Race::insert_skillOption(std::vector<std::string> skillOptions)
{
	SkillOptions = skillOptions;
}
/// <summary>
/// Inserts a single Skill prof into the race
/// </summary>
/// <param name="skillProf">- Skill prof to be passed in</param>
void Race::insert_skillProf(std::string skillProf)
{
	SkillProf.push_back(skillProf);
}
/// <summary>
/// Sets skill profs to new set of skill profs
/// </summary>
/// <param name="skillProfs">- The new skill profs to be passed in</param>
void Race::insert_skillProf(std::vector<std::string> skillProfs)
{
	SkillProf = skillProfs;
}
/// <summary>
/// Inserts a single language option into the race
/// </summary>
/// <param name="languageOption">- Language option to be passed in</param>
void Race::insert_languageOption(std::string languageOption)
{
	LanguageOptions.push_back(languageOption);
}
/// <summary>
/// Sets language options to new set of language options
/// </summary>
/// <param name="languageOptions">- The new Language options to be passed in</param>
void Race::insert_languageOption(std::vector<std::string> languageOptions)
{
	LanguageOptions = languageOptions;
}
/// <summary>
/// Inserts a single weapon option into the race
/// </summary>
/// <param name="weaponOption">- Weapon option to be passed in</param>
void Race::insert_weaponOption(std::string weaponOption)
{
	WeaponOptions.push_back(weaponOption);
}
/// <summary>
/// Sets weapon options to new set of weapon options
/// </summary>
/// <param name="weaponOptions">- The new weapon options to be passed in</param>
void Race::insert_weaponOption(std::vector<std::string> weaponOptions)
{
	WeaponOptions = weaponOptions;
}
/// <summary>
/// Inserts a single weapon prof into the race
/// </summary>
/// <param name="weaponProf">- Weapon prof to be passed in</param>
void Race::insert_weaponProf(std::string weaponProf)
{
	WeaponProf.push_back(weaponProf);
}
/// <summary>
/// Sets weapon profs to new set of weapon profs
/// </summary>
/// <param name="weaponProfs">- The new weapon profs to be passed in</param>
void Race::insert_weaponProf(std::vector<std::string> weaponProfs)
{
	WeaponProf = weaponProfs;
}
/// <summary>
/// Inserts a single armor prof into the race
/// </summary>
/// <param name="armorProf">- Language to be passed in</param>
void Race::insert_armorProf(std::string armorProf)
{
	ArmorProf.push_back(armorProf);
}
/// <summary>
/// Sets armor profs to new set of armor profs
/// </summary>
/// <param name="armorProfs">- The new armor profs to be passed in</param>
void Race::insert_armorProf(std::vector<std::string> armorProfs)
{
	ArmorProf = armorProfs;
}
/// <summary>
/// Inserts a single damage resistance into the race
/// </summary>
/// <param name="damageRes">- Damage resistance to be passed in</param>
void Race::insert_damageRes(std::string damageRes)
{
	DamageRes.push_back(damageRes);
}
/// <summary>
/// Sets damage resistances to new set of damage resistances
/// </summary>
/// <param name="damageResList">- The new damage resistances to be passed in</param>
void Race::insert_damageRes(std::vector<std::string> damageResList)
{
	DamageRes = damageResList;
}
/// <summary>
/// Inserts a single damage immunity into the race
/// </summary>
/// <param name="damageImmun">- Damage immunity to be passed in</param>
void Race::insert_damageImmun(std::string damageImmun)
{
	DamageImmun.push_back(damageImmun);
}
/// <summary>
/// Sets damage immunities to new set of damage immunities
/// </summary>
/// <param name="damageImmunList">- The new damage immunities to be passed in</param>
void Race::insert_damageImmun(std::vector<std::string> damageImmunList)
{
	DamageImmun = damageImmunList;
}
/// <summary>
/// Inserts a single trait into the race
/// </summary>
/// <param name="trait">- Trait to be passed in</param>
void Race::insert_trait(Trait trait)
{
	Traits.push_back(trait);
}
/// <summary>
/// Sets traits to new set of traits
/// </summary>
/// <param name="traits">- The traits to be passed in</param>
void Race::insert_trait(std::vector<Trait> traits)
{
	Traits = traits;
}
/// <summary>
/// Inserts spell at specfic index of the spell list, with the index meaning the level its unlocked
/// </summary>
/// <param name="index">- Index of spell, level that spell is unlocked</param>
/// <param name="spell">- The spell to be passed in</param>
void Race::insert_spell(int index, Spell spell)
{
	Spells[index].push_back(spell);
}
/// <summary>
/// Sets Spells to new list of spells
/// </summary>
/// <param name="spellList">- The new list of spells</param>
void Race::insert_spell(std::vector<std::vector<Spell>> spellList)
{
	Spells = spellList;
}

//Race Race::merge(Race r1, Race r2)
//{
//	Race mergedRace{};
//	mergedRace.set_name(r1.get_name());
//	mergedRace.set_optionPack(r1.get_optionPack());
//	if (r1.get_description() > r2.get_description()) {
//		mergedRace.set_description(r1.get_description());
//	}
//	else {
//		mergedRace.set_description(r2.get_description());
//	}
//	if (r1.get_str() > r2.get_str()) {
//		mergedRace.set_str(r1.get_str());
//	}
//	else {
//		mergedRace.set_str(r2.get_str());
//	}
//	if (r1.get_dex() > r2.get_dex()) {
//		mergedRace.set_dex(r1.get_dex());
//	}
//	else {
//		mergedRace.set_dex(r2.get_dex());
//	}
//	if (r1.get_con() > r2.get_con()) {
//		mergedRace.set_con(r1.get_con());
//	}
//	else {
//		mergedRace.set_con(r2.get_con());
//	}
//	if (r1.get_int() > r2.get_int()) {
//		mergedRace.set_int(r1.get_int());
//	}
//	else {
//		mergedRace.set_int(r2.get_int());
//	}
//	if (r1.get_wis() > r2.get_wis()) {
//		mergedRace.set_wis(r1.get_wis());
//	}
//	else {
//		mergedRace.set_wis(r2.get_wis());
//	}
//	if (r1.get_cha() > r2.get_cha()) {
//		mergedRace.set_cha(r1.get_cha());
//	}
//	else {
//		mergedRace.set_cha(r2.get_cha());
//	}
//	mergedRace.set_size(r1.get_size());
//
//
//
//	return mergedRace;
//}


void Race::print(std::ofstream& myfile)
{
    myfile
        << this->get_key() << "{\n"
        << "Name=\"" << this->get_name()
        << "\"\nOptionPack=\"" << this->get_optionPack()
        << "\"\nDescription=\"" << this->get_description()
        << "\"\nSize=" << this->get_sizename()
        << "\nStr=" << this->get_str()
        << "\nDex=" << this->get_dex()
        << "\nCon=" << this->get_con()
        << "\nInt=" << this->get_int()
        << "\nWis=" << this->get_wis()
        << "\nCha=" << this->get_cha()
        << "\nSpeed=" << this->get_speed()
        << "\nFlySpeed=" << this->get_flySpeed()
        << "\nSwimSpeed=" << this->get_swimSpeed()
        << "\nDarkVision=" << this->get_darkVision()
        << "\nSKOC=" << this->get_skillOptionsCount()
        << "\nLNOC=" << this->get_languageOptionsCount()
        << "\nWPOC=" << this->get_weaponOptionsCount()
        << "\nLizFolkAC=" << this->get_lizFolkAC()
        << "\nTortAC=" << this->get_tortAC();
    myfile
        << "\nLanguages={";
    if (this->get_language().size() > 0) {
        for (std::string k : this->get_language()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nLanguageOptions={";
    if (this->get_languageOption().size() > 0) {
        for (std::string k : this->get_languageOption()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nSkillProf={";
    if (this->get_skillProf().size() > 0) {
        for (std::string k : this->get_skillProf()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nSkillOptions={";
    if (this->get_skillOption().size() > 0) {
        for (std::string k : this->get_skillOption()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nWeaponProf={";
    if (this->get_weaponProf().size() > 0) {
        for (std::string k : this->get_weaponProf()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nWeaponOptions={";
    if (this->get_weaponOption().size() > 0) {
        for (std::string k : this->get_weaponOption()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nDamageRes={";
    if (this->get_damageRes().size() > 0) {
        for (std::string k : this->get_damageRes()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nDamageImmun={";
    if (this->get_damageImmun().size() > 0) {
        for (std::string k : this->get_damageImmun()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nArmorProf={";
    if (this->get_armorProf().size() > 0) {
        for (std::string k : this->get_armorProf()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nTools={";
    if (this->get_tool().size() > 0) {
        for (std::string k : this->get_tool()) {
            myfile
                << "\"" << k << "\"";
        }
    }
    myfile
        << "}";
    myfile
        << "\nTraits={";
    if (this->get_trait().size() > 0) {
        for (Trait k : this->get_trait()) {
            myfile
                << "\n{name=\"" << k.get_name()
                << "\"\ndescription=\"" << k.get_description()
                << "\"\ntype=" << k.get_type()
                << "\n}";
        }
    }
    myfile
        << "\n}\n}\n";
}

void Race::load(bool& inTraits, std::string& declared, bool& input, Race& newRace, Trait& newTrait, std::string& variable, bool& inObject, std::vector<Race>& myRaces, bool& inRaces)
{
    if (inTraits) {
        if (declared == "}" && input) {
            input = false;
            newRace.insert_trait(newTrait);
            newTrait.clear();
        }
        else if (declared == "}" && !input) {
            inTraits = false;
        }
        else if (declared == "{name") {
            unsigned first = variable.find("\"");
            unsigned last = variable.find_last_of("\"");
            std::string variableNew = variable.substr(first + 1, last - first - 1);
            newTrait.set_name(variableNew);
            input = true;
        }
        else if (declared == "description") {
            unsigned first = variable.find("\"");
            unsigned last = variable.find_last_of("\"");
            std::string variableNew = variable.substr(first + 1, last - first - 1);
            newTrait.set_description(variableNew);
        }
        else if (declared == "type") {
            switch (std::stoi(variable)) {
            case 0:
                newTrait.set_type(TraitType::Action);
                break;
            case 1:
                newTrait.set_type(TraitType::BAction);
                break;
            case 2:
                newTrait.set_type(TraitType::Reaction);
                break;
            case 3:
                newTrait.set_type(TraitType::Other);
                break;
            }
        }
    }
    else if (declared == "Name") {
        inObject = true;
        unsigned first = variable.find("\"");
        unsigned last = variable.find_last_of("\"");
        std::string variableNew = variable.substr(first + 1, last - first - 1);
        newRace.set_name(variableNew);
    }
    else if (declared == "OptionPack") {
        unsigned first = variable.find("\"");
        unsigned last = variable.find_last_of("\"");
        std::string variableNew = variable.substr(first + 1, last - first - 1);
        newRace.set_optionPack(variableNew);
    }
    else if (declared == "Description") {
        unsigned first = variable.find("\"");
        unsigned last = variable.find_last_of("\"");
        std::string variableNew = variable.substr(first + 1, last - first - 1);
        newRace.set_description(variableNew);
    }
    else if (declared == "Size") {
        if (variable == "Small") {
            newRace.set_size(SizeEnum::small);
        }
        else if (variable == "Medium") {
            newRace.set_size(SizeEnum::medium);
        }
        else if (variable == "Large") {
            newRace.set_size(SizeEnum::large);
        }
    }
    else if (declared == "Str") {
        newRace.set_str(std::stoi(variable));
    }
    else if (declared == "Dex") {
        newRace.set_dex(std::stoi(variable));
    }
    else if (declared == "Con") {
        newRace.set_con(std::stoi(variable));
    }
    else if (declared == "Int") {
        newRace.set_int(std::stoi(variable));
    }
    else if (declared == "Wis") {
        newRace.set_wis(std::stoi(variable));
    }
    else if (declared == "Cha") {
        newRace.set_cha(std::stoi(variable));
    }
    else if (declared == "Speed") {
        newRace.set_speed(std::stoi(variable));
    }
    else if (declared == "FlySpeed") {
        newRace.set_flySpeed(std::stoi(variable));
    }
    else if (declared == "SwimSpeed") {
        newRace.set_swimSpeed(std::stoi(variable));
    }
    else if (declared == "DarkVision") {
        newRace.set_darkVision(std::stoi(variable));
    }
    else if (declared == "SKOC") {
        newRace.set_skillOptionsCount(std::stoi(variable));
    }
    else if (declared == "LNOC") {
        newRace.set_languageOptionsCount(std::stoi(variable));
    }
    else if (declared == "WPOC") {
        newRace.set_weaponOptionsCount(std::stoi(variable));
    }
    else if (declared == "LizFolkAC") {
        if (variable == "0") {
            newRace.set_lizFolkAC(false);
        }
        else {
            newRace.set_lizFolkAC(true);
        }
    }
    else if (declared == "TortAC") {
        if (variable == "0") {
            newRace.set_tortAC(false);
        }
        else {
            newRace.set_tortAC(true);
        }
    }
    else if (declared == "Languages") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_language(vector);
    }
    else if (declared == "LanguageOptions") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_languageOption(vector);

    }
    else if (declared == "SkillProf") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_skillProf(vector);

    }
    else if (declared == "SkillOptions") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_skillOption(vector);

    }
    else if (declared == "WeaponProf") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_weaponProf(vector);

    }
    else if (declared == "WeaponOptions") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_weaponOption(vector);

    }
    else if (declared == "DamageRes") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_damageRes(vector);

    }
    else if (declared == "DamageImmun") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_damageImmun(vector);

    }
    else if (declared == "ArmorProf") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_armorProf(vector);

    }
    else if (declared == "Tools") {
        std::stringstream ssvar(variable);
        std::string segment{};
        std::vector<std::string> vector{};
        while (std::getline(ssvar, segment, '\"'))
        {
            if (segment != "{" && segment != "}" && segment != "\"\"" && segment != "{}" && segment != "") {
                vector.push_back(segment);
            }
        }
        newRace.insert_tool(vector);
    }
    else if (declared == "Traits") {
        inTraits = true;
    }
    else if (inObject && !inTraits && declared == "}") {
        if (newRace.get_name() != "") {
            myRaces.push_back(newRace);
        }
        newRace.clear();
        inObject = false;
    }
    else if (!inObject && declared == "}") {
        inRaces = false;
    }
}

//Display
/// <summary>
/// Displays the race and all of it's features
/// </summary>
void Race::display_info()
{
	GUI displayGUI{};

	std::cout << std::endl << std::endl;
	displayGUI.MakeBox(get_name(), 2);
	std::cout << std::endl;
	displayGUI.GenerateGrid(std::vector<std::string>{
		"Race: " + get_name(),
		"Pack: " + get_optionPack(),
		"Size: " + get_sizename()
	});
	std::cout << std::endl;
	displayGUI.GenerateMenu("Description", std::vector<std::string>{get_description()});
	std::cout << std::endl;
	displayGUI.GenerateGrid(std::vector<std::string>{
		"Str Mod: " + std::to_string(get_str()),
		"Dex Mod: " + std::to_string(get_dex()),
		"Con Mod: " + std::to_string(get_con()),
		"Int Mod: " + std::to_string(get_int()),
		"Wis Mod: " + std::to_string(get_wis()), 
		"Cha Mod: " + std::to_string(get_cha()),
		"Speed: " + std::to_string(get_speed()),
		"Fly Speed: " + std::to_string(get_flySpeed()),
		"Swimming Speed: " + std::to_string(get_swimSpeed()),
		"Dark Vision: " + std::to_string(get_darkVision()),
		"",
		"",
		"Skill options: " + std::to_string(get_skillOptionsCount()),
		"Language options: " + std::to_string(get_languageOptionsCount()),
		"Weapon options: " + std::to_string(get_weaponOptionsCount()),
		"",
		"",
		"",
		"Lizard Folk AC: " + std::to_string(get_lizFolkAC()),
		"Tortle AC: " + std::to_string(get_tortAC()),
	},4,6);
	displayGUI.GenerateMenu("Languages", get_language(), "", true, 4);
	displayGUI.GenerateMenu("Tools", get_tool(), "", true, 4);
	displayGUI.GenerateMenu("Skill Options", get_skillOption(), "", true, 4);
	displayGUI.GenerateMenu("Language Options", get_languageOption(), "", true, 4);
	displayGUI.GenerateMenu("Weapon Options", get_weaponOption(), "", true, 4);
	displayGUI.GenerateMenu("Skill Proficencies", get_skillProf(), "", true, 4);
	displayGUI.GenerateMenu("Weapon Proficencies", get_weaponProf(), "", true, 4);
	displayGUI.GenerateMenu("Armor Proficencies", get_armorProf(), "", true, 4);
	displayGUI.GenerateMenu("Damage Resistance", get_damageRes(), "", true, 4);
	displayGUI.GenerateMenu("Damage Immunites", get_damageImmun(), "", true, 4);
	std::cout << std::endl;
	for (Trait i : get_trait()) {
		displayGUI.GenerateMenu(i.get_name(), std::vector<std::string>{i.get_description()}, i.get_typename());
	}
	std::cout << std::endl;
}

CommandObject* Race::Add(CommandObject* currentRace, std::vector<std::string>& parameters)
{
    GUI addGUI{};
    std::string newName{};
    std::vector<std::string> compareBase{};
    bool multi{ true };
    int cmdCode{ RaceConsole.CommandCode(parameters.at(0), GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18: {
        currentRace = ExecuteCommand(RaceConsole.CommandCode("edit", Commands), currentRace, parameters, "edit");
        multi = false;
        break;
    }
    case 19: {
        compareBase = GlobalLanguages;
        break;
    }
    case 20: {
        compareBase = GlobalTools;
        break;
    }
    case 21: {
        compareBase = GlobalSkills;
        break;
    }
    case 22: {
        compareBase = GlobalSkills;
        break;
    }
    case 23: {
        compareBase = GlobalLanguages;
        break;
    }
    case 24: {
        compareBase = GlobalWeapons;
        break;
    }
    case 25: {
        compareBase = GlobalWeapons;
        break;
    }
    case 26: {
        compareBase = GlobalArmorType;
        break;
    }
    case 27: {
        compareBase = GlobalDamageType;
        break;
    }
    case 28: {
        compareBase = GlobalDamageType;
        break;
    }
    case 29: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            for (std::string i : parameters) {
                newName += i;
            }
        }
        multi = false;
        break;
    }
    }
    if (multi) {
        if (parameters.size() == 1) {
            addGUI.GenerateMenu("Loaded", compareBase, "", true, 4);
            std::cout << "\nWhat do you want to add?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhat do you want to add?\n", compareBase, true, false);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
    }
    switch (cmdCode)
    {
        //Languages
    case 19: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_language(i);
            }
            index++;
        }
        break;
    }
           //Tools
    case 20: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_tool(i);
            }
            index++;
        }
        break;
    }
           //Skill Options
    case 21: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_skillOption(i);
            }
            index++;
        }
        break;
    }
           //Skill Profs
    case 22: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_skillProf(i);
            }
            index++;
        }
        break;
    }
           //Language Options
    case 23: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_languageOption(i);
            }
            index++;
        }
        break;
    }
           //Weapon Options
    case 24: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_weaponOption(i);
            }
            index++;
        }
        break;
    }
           //Weapon Profs
    case 25: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_weaponProf(i);
            }
            index++;
        }
        break;
    }
           //Armor Profs
    case 26: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_armorProf(i);
            }
            index++;
        }
        break;
    }
           //Damage Res
    case 27: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_damageRes(i);
            }
            index++;
        }
        break;
    }
           //Damage Imm
    case 28: {
        int index{};
        for (std::string i : parameters) {
            if (HLib::IncludesString(i, compareBase)) {
                this->insert_damageImmun(i);
            }
            index++;
        }
        break;
    }
           //Traits
    case 29: {
        Trait newTrait{};
        newTrait.set_name(newName);
        //newTrait = EditTrait(newTrait);
        if (newTrait.get_name() != "%%CANCELED%%") {
            this->insert_trait(newTrait);
        }
        break;
    }
    default:
        break;
    }
    return currentRace;
}
CommandObject* Race::Edit(CommandObject* currentRace, std::vector<std::string>& parameters)
{
    GUI editGUI{};
    std::string newName{};
    std::vector<std::string> traitNames{};
    /*for (Trait i : this->get_trait()) {
        traitNames.push_back(i.get_name());
    }*/
    int cmdCode{ RaceConsole.CommandCode(parameters.at(0), GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        break;
    }
    case 3: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{"small", "medium", "large"}, true, false);
        break;
    }
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{}, false, true);
        break;
    }
    case 17:
    case 18: {
        if (parameters.size() > 1) {
            parameters.erase(parameters.begin());
            HLib::VectorToString(parameters, newName);
        }
        else {
            std::cout << "\nEnter new value:\n";
            std::getline(std::cin, newName);
        }
        newName = HLib::InputCheck(newName, "\nEnter new value\n", std::vector<std::string>{"yes", "no"}, true, false);
        break;
    }
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28: {
        currentRace = ExecuteCommand(RaceConsole.CommandCode("edit", Commands), currentRace, std::vector<std::string>{}, "edit");
        break;
    }
    case 29: {
        parameters.erase(parameters.begin());
        if (parameters.size() == 0) {
            std::cout << "\nWhich trait do you want to edit?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhich trait do you want to edit?\n", traitNames, true, false);
        }
        else {
            int index{};
            for (std::string i : parameters) {
                if (index == 0) { newName += i; }
                else { newName += " " + i; }
                index++;
            }
        }


        break;
    }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        this->set_name(newName);
        break;
    }
          //OptionPack
    case 1: {
        this->set_optionPack(newName);
        break;
    }
          //Description
    case 2: {
        this->set_description(newName);
        break;
    }
          //Size
    case 3: {
        if (newName == "small") {
            this->set_size(SizeEnum::small);
        }
        else if (newName == "medium") {
            this->set_size(SizeEnum::medium);
        }
        else if (newName == "large") {
            this->set_size(SizeEnum::large);
        }
        break;
    }
          //Str
    case 4: {
        this->set_str(std::stoi(newName));
        break;
    }
          //Dex
    case 5: {
        this->set_dex(std::stoi(newName));
        break;
    }
          //Con
    case 6: {
        this->set_con(std::stoi(newName));
        break;
    }
          //Int
    case 7: {
        this->set_int(std::stoi(newName));
        break;
    }
          //Wis
    case 8: {
        this->set_wis(std::stoi(newName));
        break;
    }
          //Cha
    case 9: {
        this->set_cha(std::stoi(newName));
        break;
    }
          //Speed
    case 10: {
        this->set_speed(std::stoi(newName));
        break;
    }
           //FlyingSpeed
    case 11: {
        this->set_flySpeed(std::stoi(newName));
        break;
    }
           //SwimmingSpeed
    case 12: {
        this->set_swimSpeed(std::stoi(newName));
        break;
    }
           //Dark vision
    case 13: {
        this->set_darkVision(std::stoi(newName));
        break;
    }
           //Skill Options Count
    case 14: {
        this->set_skillOptionsCount(std::stoi(newName));
        break;
    }
           //Language Options Count
    case 15: {
        this->set_languageOptionsCount(std::stoi(newName));
        break;
    }
           //Weapon Options Count
    case 16: {
        this->set_weaponOptionsCount(std::stoi(newName));
        break;
    }
           //LizFolkAC
    case 17: {
        if (newName == "yes") {
            this->set_lizFolkAC(true);
        }
        else {
            this->set_lizFolkAC(false);
        }
        break;
    }
           //TortAC
    case 18: {
        if (newName == "yes") {
            this->set_tortAC(true);
        }
        else {
            this->set_tortAC(false);
        }
        break;
    }
           //Traits
    case 29: {
        Trait newTrait{};
        std::vector<Trait> allTraits{ this->get_trait() };
        int index{};
        for (Trait i : allTraits) {
            if (i.get_name() == newName) {
                newTrait = i;
            }
            index++;
        }
        //allTraits.at(index) = EditTrait(newTrait);
        this->insert_trait(allTraits);
        break;
    }
    default:
        break;
    }
    return currentRace;
}
CommandObject* Race::Remove(CommandObject* currentRace, std::vector<std::string>& parameters)
{
    GUI removeGUI{};
    std::string newName{};
    std::vector<std::string> compareBase{};
    bool multi{ true };
    int cmdCode{ RaceConsole.CommandCode(parameters.at(0), this->GlobalRaceOptions) };
    switch (cmdCode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18: {
        multi = false;
        break;
    }
    case 19: {
        compareBase = this->get_language();
        break;
    }
    case 20: {
        compareBase = this->get_tool();
        break;
    }
    case 21: {
        compareBase = this->get_skillOption();
        break;
    }
    case 22: {
        compareBase = this->get_skillProf();
        break;
    }
    case 23: {
        compareBase = this->get_languageOption();
        break;
    }
    case 24: {
        compareBase = this->get_weaponOption();
        break;
    }
    case 25: {
        compareBase = this->get_weaponProf();
        break;
    }
    case 26: {
        compareBase = this->get_armorProf();
        break;
    }
    case 27: {
        compareBase = this->get_damageRes();
        break;
    }
    case 28: {
        compareBase = this->get_damageImmun();
        break;
    }
    case 29: {
        currentRace = ExecuteCommand(RaceConsole.CommandCode("edit", Commands), currentRace, parameters, "remove");
        multi = false;
        break;
    }
    }
    if (multi) {
        if (parameters.size() == 1) {
            removeGUI.GenerateMenu("Loaded", compareBase, "", true, 4);
            std::cout << "\nWhat do you want to remove?\n";
            std::getline(std::cin, newName);
            newName = HLib::InputCheck(newName, "\nWhat do you want to remove?\n", compareBase, true, false);
            parameters.clear();
            parameters.push_back(newName);
        }
        else {
            parameters.erase(parameters.begin());
        }
    }
    switch (cmdCode)
    {
        //Name
    case 0: {
        if (this->get_name() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_name("");
        }
        break;
    }
          //OptionPack
    case 1: {
        if (this->get_optionPack() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_optionPack("");
        }
        break;
    }
          //Description
    case 2: {
        if (this->get_description() == "") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_description("");
        }
        break;
    }
          //Size
    case 3: {
        if (this->get_sizename() == "Small") {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_size(SizeEnum::small);
        }
        break;
    }
          //Str
    case 4: {
        if (this->get_str() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_str(0);
        }
        break;
    }
          //Dex
    case 5: {
        if (this->get_dex() == 0) {
            std::cout << "\nNothing to remove\n"; break;

        }
        else {
            this->set_dex(0);
        }
        break;
    }
          //Con
    case 6: {
        if (this->get_con() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_con(0);
        }
        break;
    }
          //Int
    case 7: {
        if (this->get_int() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_int(0);
        }
        break;
    }
          //Wis
    case 8: {
        if (this->get_wis() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_wis(0);
        }
        break;
    }
          //Cha
    case 9: {
        if (this->get_cha() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_cha(0);
        }
        break;
    }
          //Speed
    case 10: {
        if (this->get_speed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_speed(0);
        }
        break;
    }
           //FlyingSpeed
    case 11: {
        if (this->get_flySpeed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_flySpeed(0);
        }
        break;
    }
           //SwimmingSpeed
    case 12: {
        if (this->get_swimSpeed() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_swimSpeed(0);
        }
        break;
    }
           //Dark vision
    case 13: {
        if (this->get_darkVision() == 0) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_darkVision(0);
        }
        break;
    }
           //Skill Options Count
    case 14: {
        if (this->get_skillOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_skillOptionsCount(0);
        }
        break;
    }
           //Language Options Count
    case 15: {
        if (this->get_languageOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_languageOptionsCount(0);
        }
        break;
    }
           //Weapon Options Count
    case 16: {
        if (this->get_weaponOptionsCount() == 1) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_weaponOptionsCount(0);
        }
        break;
    }
           //LizFolkAC
    case 17: {
        if (this->get_lizFolkAC() == false) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_lizFolkAC(false);
        }
        break;
    }
           //TortAC
    case 18: {
        if (this->get_tortAC() == false) {
            std::cout << "\nNothing to remove\n"; break;
        }
        else {
            this->set_tortAC(false);
        }
        break;
    }
           //Languages
    case 19: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_language()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_language(newInsert);
        break;
    }
           //Tools
    case 20: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_tool()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_tool(newInsert);
        break;
    }
           //Skill Options
    case 21: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_skillOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_skillOption(newInsert);
        break;
    }
           //Skill Profs
    case 22: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_skillProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_skillProf(newInsert);
        break;
    }
           //Language Options
    case 23: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_languageOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_languageOption(newInsert);
        break;
    }
           //Weapon Options
    case 24: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_weaponOption()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_weaponOption(newInsert);
        break;
    }
           //Weapon Profs
    case 25: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_weaponProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_weaponProf(newInsert);
        break;
    }
           //Armor Profs
    case 26: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_armorProf()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_armorProf(newInsert);
        break;
    }
           //Damage Res
    case 27: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_damageRes()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_damageRes(newInsert);
        break;
    }
           //Damage Imm
    case 28: {
        std::vector<std::string> newInsert{};
        for (std::string i : this->get_damageImmun()) {
            if (!HLib::IncludesString(i, parameters)) {
                newInsert.push_back(i);
            }
        }
        this->insert_damageImmun(newInsert);
        break;
    }
    }
    return currentRace;
}

//Virtual 
CommandObject* Race::ExecuteCommand(int cmdCode, CommandObject* currentRace, std::vector<std::string> parameters, std::string context)
{
	switch (cmdCode)
	{
		//Done
	case 0: {
		break;
	}

		  //Help
	case 1: {
		GUI helpGUI{};
		std::vector<std::string> helpOptions{};
		std::string input{};

		if (parameters.empty()) {
		}
		else {
			std::vector<std::string> selection{};
			int index{};
			if (parameters.at(0) == "all") {
				parameters.clear();
				parameters = HLib::MergeOrdered(GlobalRaceOptions, GlobalRaceDefs);
			}
			if (context != "console") {
				for (std::string i : GlobalRaceOptions) {
					for (std::string k : parameters) {
						if (i == k) {
							selection.push_back(i);
							selection.push_back(GlobalRaceDefs.at(index));
						}
					}
					index++;
				}
			}
			else {
				context = "";
				selection = parameters;
			}
			if (selection.empty()) {
				std::cout << "\nInput not found, try again\n";
			}
			else {
				helpGUI.GenerateMenu("Command - Definition", selection, "", true, 2);
			}
		}
		break;
	}

		  //Cancel
	case 2: {
		Race cancelRace{ "%%CANCELED%%" };
		currentRace = &cancelRace;
		break;
	}

		  //Add
	case 3: {
        if (parameters.size() > 0) {
            if (parameters.at(0) == "add") {
            parameters.erase(std::begin(parameters));
            }
        }
		switch (RaceConsole.ValidateCommand("What would you like to add?", GlobalRaceOptions, GlobalRaceDefs, parameters))
		{
		case 0: {
			currentRace = ExecuteCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
			break;
		}
		case 1: {
			break;
		}
		case 2: {
			currentRace = Add(currentRace, parameters);
			break;
		}
		case 3: {
			std::cout << "\nInvalid parameter\n";
			currentRace = ExecuteCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
			break;
		}
		}
		break;
	}

		  //Edit
	case 4: {
		switch (RaceConsole.ValidateCommand("What would you like to edit?", GlobalRaceOptions, GlobalRaceDefs, parameters))
		{
		case 0: {
			currentRace = ExecuteCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
			break;
		}
		case 1: {
			break;
		}
		case 2: {
			currentRace = Edit(currentRace, parameters);
			break;
		}
		case 3: {
			std::cout << "\nInvalid parameter\n";
			currentRace = ExecuteCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
			break;
		}
		}
		break;
	}

		  //Clear
	case 5: {
		std::vector<std::string> options{ "yes", "no" };
		std::vector<std::string> optionDefs{ "", "" };

		switch (RaceConsole.ValidateCommand("Are you sure?", options, optionDefs, parameters))
		{
		case 0: {
			currentRace = ExecuteCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
			break;
		}
		case 1: {
			break;
		}
		case 2: {
			Race newRace{};
			currentRace = &newRace;
			break;
		}
		case 3: {
			std::cout << "\nInvalid parameter\n";
			currentRace = ExecuteCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
			break;
		}
		}
		break;
	}

		  //Remove
	case 6: {
		switch (RaceConsole.ValidateCommand("What would you like to remove?", GlobalRaceOptions, GlobalRaceDefs, parameters))
		{
		case 0: {
			currentRace = ExecuteCommand(cmdCode, currentRace, parameters, std::to_string(cmdCode));
			break;
		}
		case 1: {
			break;
		}
		case 2: {
			currentRace = Remove(currentRace, parameters);
			break;
		}
		case 3: {
			std::cout << "\nInvalid parameter\n";
			currentRace = ExecuteCommand(cmdCode, currentRace, std::vector<std::string>{}, std::to_string(cmdCode));
			break;
		}
		}
		break;
	}
	default:
		break;
	}
	if (context == "") {
		system("pause");
		system("cls");
	}
	return currentRace;
}

void Race::Display()
{
	display_info();
}

std::string Race::get_title()
{
	return this->Title;
}

bool Race::IsDone(std::string input)
{
	if (input == "done" || input == "exit" || this->get_name() == "%%CANCELED%%") {
		return false;
	}
	else {
		return true;
	}
}

std::vector<std::string> Race::get_commands()
{
	return this->Commands;
}

std::vector<std::string> Race::get_command_defs()
{
	return this->CommandDefs;
}

